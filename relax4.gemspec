# -*- encoding: utf-8 -*-
lib = File.expand_path('../lib/', __FILE__)
$:.unshift lib unless $:.include?(lib)

require 'relax4/version'

Gem::Specification.new do |s|
  s.name        = "relax4"
  s.version     = Relax4::VERSION
  s.platform    = Gem::Platform::RUBY
  s.authors     = ["John Lees-Miller"]
  s.email       = ["jdleesmiller@gmail.com"]
  s.homepage    = "http://relax4.rubyforge.org/"
  s.summary     = "The RELAX IV code for the Minimum Cost Network Flow Problem"
  s.description = <<DESC
Ruby interface for the RELAX IV code by D.P. Bertsekas and P. Tseng.
DESC
  s.rubyforge_project = "relax4"

  s.files = Dir.glob("lib/**/*.rb") +
    Dir.glob("ext/relax4/*.{rb,c,h}") +
    Dir.glob("test/relax4/*.{inp,INP}")
  s.test_files = Dir.glob("test/relax4/*_test.rb")
  s.extensions = ["ext/relax4/extconf.rb"]

  s.rdoc_options = [
    "--main",    "README.rdoc",
    "--title",   "relax4-#{Relax4::VERSION}",
    "--exclude", "ext"] # rdoc can't parse swig output -- we just get junk
  s.extra_rdoc_files << "README.rdoc"
end
