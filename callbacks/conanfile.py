from conans import ConanFile, CMake

class CallbacksExample(ConanFile):
    

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=self.source_folder, build_folder=self.build_folder)
        cmake.build()
        cmake.test()
        cmake.install()
        