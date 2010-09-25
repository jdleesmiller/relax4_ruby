require 'mkmf' # for Config
require 'rake/clean'

begin
  require 'rubygems'
  require 'gemma'

  Gemma::RakeTasks.with_gemspec_file 'relax4.gemspec' do |g|
    # Use old rdoc, because rdoc 2.5.11 seems to mangle the included relax4.h
    # header file. Unfortunately, the old rdoc ignores --exclude when given an
    # explicit file list (2.5.11 doesn't), so we have to fix that up here.
    g.rdoc.use_gem_if_available = false
    g.rdoc.files.delete_if {|f| File.dirname(f) == 'ext'}
  end
rescue LoadError
  puts "Install gemma (sudo gem install gemma) for more rake tasks."
end

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

desc "docs to rubyforge"
task :publish_docs => :rdoc do
  sh "rsync --archive --delete --verbose rdoc/* "\
     " jdleesmiller@rubyforge.org:/var/www/gforge-projects/relax4"
end

CLEAN.include('ext/*.o', 'ext/mkmf.log', 'ext/Makefile')
CLOBBER.include('ext/*.so')

task :test => EXT
task :default => :test

