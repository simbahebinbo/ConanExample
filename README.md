# Conan Example

Example project to use Conan as C++ dependencies manager.

## Docs

* Conan's resources: https://conan.io/

### Install Conan binary

Install CLion by downloading the binary installation: https://conan.io/downloads.html

### Generate Conan profiles

Conan profiles needs to be generated and placed in the directory `~/.conan2/profiles/`. They could be generated with the
following command:

```bash
conan profile detect
```

Do not forget to tweak the values "arch" and "build_type".

Example file:

```text
[settings]
arch=armv8
build_type=Release
compiler=apple-clang
compiler.cppstd=20
compiler.libcxx=libc++
compiler.version=15
os=Macos
```

### Create conanfile.txt

Create a conanfile.txt at the root path of the project containing the dependencies.

For example:

```text
[requires]
spdlog/1.14.1
sfml/2.6.1

[generators]
CMakeDeps
CMakeToolchain

[layout]
cmake_layout
```

### Configure cmake

Add the required elements to obtain a `CMakeLists.txt` file like below:

```cmake
cmake_minimum_required(VERSION 3.20)

project(ConanTemplate)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
```

```shell
$ conan --version
Conan version 2.7.0

$ conan profile show
Host profile:
[settings]
arch=armv8
build_type=Release
compiler=apple-clang
compiler.cppstd=20
compiler.libcxx=libc++
compiler.version=15
os=Macos

Build profile:
[settings]
arch=armv8
build_type=Release
compiler=apple-clang
compiler.cppstd=20
compiler.libcxx=libc++
compiler.version=15
os=Macos
```

```shell
$ cmake --version
cmake version 3.30.0

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

```shell
$ gcc --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.5.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

```shell
$ g++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)
Target: arm64-apple-darwin23.5.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

编译

```shell
$ ./build.sh
```

运行

```shell
$ ./run.sh
```
