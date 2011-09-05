require 'rubygems'
require 'bundler/setup'
require 'gemma'

require 'rbconfig'

Gemma::RakeTasks.with_gemspec_file 'relax4.gemspec'

NAME = 'relax4'
EXT_PATH = File.join('ext', NAME)
LIB_PATH = File.join('lib', NAME)
WRAPPER_C = File.join(EXT_PATH, "#{NAME}_wrap.c")
SO_NAME = "#{NAME}.#{RbConfig::CONFIG['DLEXT']}"

# rule to run swig to generate relax4_wrap.c
file WRAPPER_C => Dir.glob(File.join(EXT_PATH, "*.{h,i}")) do |t|
  Dir.chdir(EXT_PATH) do
    sh "swig -ruby relax4.i"
  end
end

# rule to build the extension: this says
# that the extension should be rebuilt
# after any change to the files in ext
file File.join(LIB_PATH, SO_NAME) =>
  Dir.glob(File.join(EXT_PATH, "*.{rb,c,h}")) + [WRAPPER_C] do
  Dir.chdir(EXT_PATH) do
    # this does essentially the same thing
    # as what rubygems does
    ruby "extconf.rb"
    sh "make"
  end
  cp File.join(EXT_PATH, SO_NAME), LIB_PATH
end

# make the :test task depend on the shared
# object, so it will be built automatically
# before running the tests
task :test => File.join(LIB_PATH, SO_NAME)

# use 'rake clean' and 'rake clobber' to
# easily delete generated files
CLEAN.include('ext/**/*{.o,.log,.so}')
CLEAN.include('ext/**/Makefile')
CLOBBER.include('lib/**/*.so')
CLOBBER.include(WRAPPER_C)

## Run extconf to build.
#EXT = "ext/relax4.#{RbConfig::CONFIG['DLEXT']}"
#file EXT => %w(ext/extconf.rb ext/relax4_wrap.c) do |t|
#  Dir.chdir('ext') do
#    ruby "extconf.rb"
#    sh "make"
#  end
#end

desc "docs to rubyforge"
task :publish_docs => :rdoc do
  sh "rsync --archive --delete --verbose rdoc/* "\
     " jdleesmiller@rubyforge.org:/var/www/gforge-projects/relax4"
end

#CLEAN.include('ext/*.o', 'ext/mkmf.log', 'ext/Makefile')
#CLOBBER.include('ext/*.so')

#task :test => EXT
task :default => :test

