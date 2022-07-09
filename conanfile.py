from conans import ConanFile, CMake


class CallbacksExample(ConanFile):
    name = "cpp-examples"
    version = "0.1"
    license = "MIT"
    url = "https://github.com/schnaggelz/cpp-examples"
    description = "Personal C++ examples"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    exports_sources = "*"

    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure(source_folder=self.source_folder, build_folder=self.build_folder)
        cmake.build()
        #cmake.test()
        cmake.install()
        
    def package(self):
        self.copy("*.hpp", dst="include", src="include")
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["callback", "observer"]
