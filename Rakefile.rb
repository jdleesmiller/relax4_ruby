require 'mkmf' # for Config

begin
  require 'rubygems'
  require 'gemma'

  Gemma::RakeTasks.with_gemspec_file 'relax4.gemspec' do |g|
    # Remove extension files (rdoc can't currently make sense of them) and some
    # test data files.
    g.rdoc.files.delete_if {|f| !%w(. lib lib/relax4).member?(File.dirname(f))}
    g.yard.files.delete_if {|f| !%w(. lib lib/relax4).member?(File.dirname(f))}

    # Old-style docs; rdoc 2.5.11 seems to mangle the included header file.
    g.rdoc.use_gem_if_available = false

    g.rdoc.title = "relax4-#{g.gemspec.version}"
  end
rescue LoadError
  # Gemma is not installed; optionally, you can print a message:
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

