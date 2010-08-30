$:.unshift File.expand_path("../lib", __FILE__)
require 'mkmf' # for Config

# Run swig.
file 'ext/relax4_wrap.c' => %w(ext/relax4.h ext/relax4.c ext/relax4.i) do |t|
  Dir.chdir('ext') do
    sh "swig -ruby relax4.i"
  end
end

# Run extconf to build.
EXT = "ext/relax4.#{Config::CONFIG['DLEXT']}"
file EXT => %w(ext/extconf.rb ext/relax4_wrap.c) do |t|
  Dir.chdir('ext') do
    ruby "extconf.rb"
    sh "make"
  end
end

desc "gem build"
task :build => EXT do
  sh "gem build relax4.gemspec"
end
 
desc "gem release"
task :release => :build do
  require 'relax4/version'
  sh "gem push relax4-#{Relax4::VERSION}"
end

require 'rake/testtask'
Rake::TestTask.new(:test) do |test|
  test.libs << 'ext' << 'test'
  test.pattern = 'test/**/test_*.rb'
  test.verbose = false
end

require 'rake/rdoctask'
Rake::RDocTask.new do |rdoc|
  require 'relax4/version'
  rdoc.rdoc_dir = 'doc'
  rdoc.title = "relax4 #{Relax4::VERSION}"
  rdoc.rdoc_files.include('README.rdoc')
  rdoc.rdoc_files.include('lib/**/*.rb')
end

# Unfortunately, the RDocTask on 1.8.7 gives us an ancient version of rdoc that
# doesn't handle the docs correctly. If the rdoc gem is installed and the
# rubygems bin path is on the $PATH, this gives us a working version.
desc "docs with rdoc gem"
task :rdoc_sh do |t|
  require 'relax4/version'
  rm_f 'doc'
  sh "rdoc --title='relax4 #{Relax4::VERSION}' --main=README.rdoc "\
    "README.rdoc #{Dir.glob('lib/**/*.rb').join(' ')}"
end

desc "docs to rubyforge"
task :publish_docs => :rdoc_sh do
  sh "rsync --archive --delete --verbose doc/* "\
     " jdleesmiller@rubyforge.org:/var/www/gforge-projects/relax4"
end

begin
  require 'rcov/rcovtask'
  Rcov::RcovTask.new do |test|
    test.libs << 'ext'
    test.libs << 'test'
    test.pattern = 'test/**/test_*.rb'
    test.verbose = true
  end
rescue LoadError
  task :rcov do
    abort "RCov is not available; you must: sudo gem install spicycode-rcov"
  end
end

require 'rake/clean'
CLEAN.include('ext/*.o', 'ext/mkmf.log', 'ext/Makefile')
CLOBBER.include('ext/*.so')

task :test => EXT
task :default => :test


