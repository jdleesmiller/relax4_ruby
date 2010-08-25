lib = File.expand_path('../lib/', __FILE__)
$:.unshift lib unless $:.include?(lib)

require 'relax4/version'

Gem::Specification.new do |s|
  s.name        = "relax4"
  s.version     = Relax4::VERSION
  s.platform    = Gem::Platform::CURRENT
  s.authors     = ["John Lees-Miller"]
  s.email       = ["jdleesmiller@gmail.com"]
  s.homepage    = ""
  s.summary     = "The RELAX IV code for the Minimum Cost Network Flow Problem"
  s.description = "Ruby interface for the RELAX IV code by D.P. Bertsekas and"\
                    " P. Tseng."
  # s.rubyforge_project         = "rucas" # maybe ?
  
  s.files        = Dir.glob("lib/**/*") + %w(
ext/extconf.rb
ext/relax4.c
ext/relax4.h
ext/relax4_wrap.c
README.rdoc)

  s.extensions = "ext/extconf.rb"
  s.require_paths << 'lib'
  s.require_paths << 'ext'
end
