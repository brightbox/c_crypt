require "rake/extensiontask"

spec = Gem::Specification.new do |s|
  s.name = "c_crypt"
  s.version = "0.2"
  s.author = "Caius Durling"
  s.email = "caius@brightbox.co.uk"
  s.homepage = "http://github.com/brightbox/c_crypt"
  s.platform = Gem::Platform::RUBY
  s.summary = "Ruby wrapper for the C crypt() function."
  s.files = FileList["ext/**/*", "lib/**/*.rb", "[A-Z]*"].to_a
  s.extensions = FileList["ext/**/extconf.rb"]
  s.add_development_dependency "rake-compiler"
  s.has_rdoc = false
end

# add your default gem packing task
Rake::GemPackageTask.new(spec) do |pkg|
end

# feed your ExtensionTask with your spec
Rake::ExtensionTask.new('c_crypt', spec)
