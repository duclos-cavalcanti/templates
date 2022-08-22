# Project Templates

1. [Introduction](#intro)
2. [Templates](#templates)
    1. [Languages](#templates)
        1. [Go](#go)
        2. [Rust](#rust)
        3. [Lua](#lua)
        4. [C](#C)
        5. [C w/ Lua](#clua)
        6. [Cpp](#cpp)
        7. [Haskell](#haskell)
        8. [Common Lisp](#lisp)
        9. [Java](#java)
        10. [Latex](#tex)
        11. [GHDL](#ghdl)
    2. [CI/CD](#templates)
        1. [Travis-CI](#travis)
        2. [Jenkins](#jen)
    3. [Technologies](#tech)
        1. [Dockerfile](#docker)
        2. [ClangFormat](#clang)
        3. [Git Hooks](#git)
    4. [Libraries and Frameworks](#lib)
        1. [Python CFFI](#cffi)
        2. [C/Lua SDL2](#sdl)
        3. [C++ OpenMPI](#mpi)
    5. [Unit Testing](#test)
        1. [C++ GoogleTest](#gtest)
        2. [Python Pytest](#pytest)
3. [License](#lic)
4. [Donations](#don)

<a name="intro"/>

## Introduction
Every time I'm learning a new technology or a new language, I feel the need to create a reproducible template project that has already the basics built in. The idea is to have a somewhat abstracted away template, such that I
can in the future use it as a basis for an actual project without having to remember fine details and commands to the specific tech stack at hand. There are also tutorials mixed among templates, which are always correctly giving props to the respective authors or sources, since they serve similar purposes as boilerplate/template projects.

Since that was becoming a strong habit and there were numerous little template projects littered throughout my profile, I took the liberty to unify them under a single repository. They hopefully have the basics covered, as in a language
it should have compiling, running, testing and debugging as targets or at least documentation on how to perform these actions for the given template.

## Templates
- [Go](#go)
- [Rust](#rust)
- [Lua](#lua)
- [C](#C)
- [C w/ Lua](#clua)
- [Cpp](#cpp)
- [Haskell](#haskell)
- [Common Lisp](#lisp)
- [Java](#java)
- [Latex](#tex)
- [GHDL](#ghdl)
- [Travis-CI](#travis)
- [Jenkins](#jen)
- [Dockerfile](#docker)
- [ClangFormat](#clang)
- [Git Hooks](#git)
- [Python CFFI](#cffi)
- [C/Lua SDL2](#sdl)
- [C++ OpenMPI](#mpi)
- [Google Test](#gtest)
- [Pytest](#pytest)

<a name="go"/>

### Go
[![golang](https://img.shields.io/badge/-template-00ADD8?style=flat-square&logo=Go&logoColor=white)](https://go.dev/)

##### Dependencies
- [go](https://go.dev/)
- [dlv](https://github.com/derekparker/delve) for debugging, if needed
- [godoc](https://pkg.go.dev/golang.org/x/tools/cmd/godoc) for documentation generation

```sh
$ sudo pacman -S go
$ go install  https://github.com/derekparker/delve  # if debugging is wanted
$ go install  golang.org/x/tools/cmd/godoc          # if documentation is wanted
```

##### Usage
```sh
$ make        # build's project
$ make build  # also build's project
$ make run    # runs binary
$ make debug  # runs binary with debugger
$ make test   # unit testing
$ make cover  # test with coverage information
$ make docs   # generate documentation
$ make fmt    # format go files
```

<a name="rust"/>

### Rust
[![rust](https://img.shields.io/badge/-template-000000?style=flat-square&logo=rust&logoColor=white)](https://www.rust-lang.org/)

##### Dependencies
- [rustup](https://rustup.rs/)
- [rust](https://www.rust-lang.org/)

```sh
$ sudo pacman -S rustup
$ rustup update stable
$ rustup component add rls rust-src # for lsp to be used with your editor
```

##### Usage
```sh
$ cargo build             # build's project
$ cargo build --release   # stores executable in target/release and performs optimizations
$ cargo check             # checks if project compiles without building
$ cargo run               # builds project and runs binary
$ cargo test              # unit testing
$ cargo fmt               # format go files
```

<a name="lua"/>

### Lua
<img alt="Lua" src="https://img.shields.io/badge/-template-2C2D72?style=flat-square&logo=lua&logoColor=white" />

##### Dependencies

- [lua](http://www.lua.org/)
- [luarocks](https://luarocks.org/)
- [luacheck](https://github.com/mpeterv/luacheck)
- [stylua](https://github.com/johnnymorganz/stylua), if styling/formatting is wanted

```sh
$ sudo pacman -S luarocks
$ sudo luarocks install luacheck
$ cargo install stylua      # needs rust installed
```

##### Usage

```sh
$ make        # runs lua project
$ make style  # runs stylua and styles project accordingly
$ make lint   # runs styling first, then lints the project
```

<a name="C"/>

### C
<img alt="C" src="https://img.shields.io/badge/-template-A8B9CC?style=flat-square&logo=c&logoColor=white" />

##### Dependencies

- [CMake](https://cmake.org/)

```sh
sudo pacman -S cmake
```

##### Usage
With [CMake](https://cmake.org/) it is possible to abstract away much of the flags and command line arguments needed within a large project. To be able to build said project, these are the necessary steps:

```sh
$ cd build
$ cmake ..
$ make
```

Additionally, there are two bakes in targets called `run` and `debug`. How they are setup can be seen in the
`.cmake` files found in the cmake folder within the template project. They do as their name suggest, however to
be able to successfully use the debugger, one needs [gdb](https://sourceware.org/gdb/bugs/) installed in their system.

<a name="clua"/>

### C w/ Lua
<img alt="C" src="https://img.shields.io/badge/-template-A8B9CC?style=flat-square&logo=c&logoColor=white" />
<img alt="Lua" src="https://img.shields.io/badge/-template-2C2D72?style=flat-square&logo=lua&logoColor=white" />

##### Dependencies

- [lua](http://www.lua.org/)
- [CMake](https://cmake.org/)

```sh
$ sudo pacman -S cmake lua
```

##### Usage
It's the same process as in the [C](#c) template, the only difference is that the c binary is communicating with the lua virtual machine which of course also was written in C. Essentially, C can call functions and read/write variables within lua and vice versa. This can be very powerful and lead to interesting applications.

```sh
$ cd build
$ cmake ..
$ make
```


<a name="cpp"/>

### Cpp

<img alt="Cpp" src="https://img.shields.io/badge/-template-00599C?style=flat-square&logo=cplusplus&logoColor=white" />

##### Dependencies
- [CMake](https://cmake.org/)

```sh
sudo pacman -S cmake
```

##### Usage
Almost a 1 to 1 copy of the [C](#c) template. If it is necessary to specify a version of the language change the following line within `CMakeLists.txt`:

```cmake
set (CMAKE_CXX_STANDARD 11)
```

<a name="haskell"/>

### Haskell
[![haskell](https://img.shields.io/badge/-template-5D4F85?style=flat-square&logo=haskell&logoColor=white)](https://go.dev/)

An interesting functional language, seemingly very beloved by its community. This project template was derived from
a great repository which is mentioned in the README. Also, there is also mentioned the cabal build system, which stack uses
under the hood. However, it was found by me to be much easier to use stack.

##### Dependencies
- [haskell](https://www.haskell.org/)
- [stack](https://docs.haskellstack.org/en/stable/README/), the build tool

##### Usage
Great documentation on stack can be found [here](https://docs.haskellstack.org/en/stable/README/), also a simple tutorial can be found [here](https://docs.haskellstack.org/en/stable/GUIDE/).

```sh
$ make build    # runs stack build
$ make run      # runs the binary, runs stack exec <project name>
$ make test     # runs stack test to perform unit testing, untested!
$ make fmt      # formats haskell files
$ make clean    # runs stack clean
$ make purge    # runs stack purge
$ make docs     # runs cabal haddock, untested!
```

<a name="lisp"/>

### Common Lisp
[![lisp](https://img.shields.io/badge/CommonLisp-template-purple.svg)](https://lisp-lang.org/)

Minimal template project for common lisp applications. Uses the [asdf](https://common-lisp-libraries.readthedocs.io/asdf/) build tool to manage the project, it's dependencies and
testing. The testing library used here is [prove](https://github.com/fukamachi/prove).

##### Dependencies
- [quicklisp](https://www.quicklisp.org/beta/)
- [sbcl](http://www.sbcl.org/)

##### Usage

```sh
$ make          # compiles and runs application
$ make test     # runs prove unit testing
$ make clean    # cleans project
```

<a name="java"/>

### Java
[![java](https://img.shields.io/badge/Java-template-yellow.svg)](https://www.java.com/en/)
[![lisp](https://img.shields.io/badge/-template-02303A?style=flat-square&logo=gradle&logoColor=white)](https://docs.gradle.org/current/samples/sample_building_java_applications.html)

The best resource will of course be found in the gradle's official [website](https://docs.gradle.org/current/samples/sample_building_java_applications.html). However this folder can be used either as a starting point or an illustration of a simple java application that

##### Dependencies
- [java](https://www.quicklisp.org/beta/)
- [gradle](https://gradle.org/)

```sh
sudo pacman -S jdk-openjdk gradle
```

##### Usage

```sh
$ make          # runs application
$ make build    # builds/packages application
$ make test     # runs unit tests application
$ make clean    # cleans project
```

<a name="tex"/>

### Latex
<img alt="Latex" src="https://img.shields.io/badge/-template-008080?style=flat-square&logo=latex&logoColor=white" />

The idea was to create a latex project that did not need to require an installation
of tex and it's huge libraries. Using a containerized docker that takes care of
this work, it becomes very easy to work with latex in a OS agnostic manner. The docker build in question is
[docker-texlive](https://github.com/thomasWeise/docker-texlive).

##### Dependencies

- [Docker](https://www.docker.com/)
- [docker-texlive](https://github.com/thomasWeise/docker-texlive)

```sh
sudo pacman -S docker
```
Docker may need special rights to be able to be run without `sudo`.

##### Usage
```sh
make        # does it all, pulls docker if necessary, builds the main.tex into a main.pdf
make clean  # cleans project
make reset  # deletes a running docker if there is one and the pulled docker image.
```

<a name="ghdl"/>

### GHDL
Project is working, however I need to document the steps and dependencies.

```sh
TODO
```

<a name="travis"/>

### Travis-CI
[![travis](https://img.shields.io/badge/-template-3EAAAF?style=flat-square&logo=travisci&logoColor=white)](https://www.travis-ci.com/)

##### Dependencies
Depends on the project in question. Here, as an example a regular `cpp` CMake project is used.

```sh
sudo pacman -S cmake
```

##### Usage
An account has to be created at travis-ci. Following to that, one would have to give permissions to the travis-ci bot within github. That way, any project that is pushed and contains a `travis.yml` file will be evaluated by the travis bot. The pipeline steps examples are listed in the above mentioned file, once again as an example of what one could do. Also further configuration
can be done in one's travis account.

<a name="jenkins"/>

### Jenkins
[![jenkins](https://img.shields.io/badge/-template-D24939?style=flat-square&logo=jenkins&logoColor=white)](https://www.jenkins.io/)

There are two project examples at hand. One is the use of jenkins within a docker, which eliminates the dependency
of jenkins directly. Also theoretically shows the use of a containerized deployment of this CI/CD program. The other one
is a regular cmake project that simply has a `Jenkinsfile` that directs how the pipeline should be executed. However, for the
latter's case one has to configure jenkins to look at this project either locally or through a git-based portal and order
it to deploy the pipeline when needed.

#### Jenkins within Docker
##### Dependencies

- [Docker](https://www.docker.com/)

```sh
sudo pacman -S docker
```

##### Usage
```sh
$ make build    # pulls and builds the jenkins docker
$ make run      # runs the docker at port 8080
$ make log      # shows the log output of the running docker
$ make stop     # stops docker
$ make restart  # restarts docker
$ make clean    # stops and deletes the jenkins docker
$ make reset    # stops docker, deletes it, and then its image
```

#### Jenkins CMake
##### Dependencies

- [Jenkins](https://www.jenkins.io/)

```sh
sudo pacman -S jenkins cmake
```

##### Usage
The Jenkinsfile details very explicitly how the pipeline is executed.

<a name="docker"/>

### Dockerfile
[![docker](https://img.shields.io/badge/-template-2496ED?style=flat-square&logo=docker&logoColor=white)](https://www.docker.com/)

An example use of a dockerfile. The idea is to show how one can write a dockerfile for a given linux OS with countless
dependencies, environment variables, file structures and volume instantiations. There is also the use of an entrypoint
script to show what could be done within the docker, since with a shell script the possibilities are endless.

##### Dependencies
- [Docker](https://www.docker.com/)

```sh
sudo pacman -S docker
```

##### Usage
```sh
$ make build    # builds the custom docker with a tag and a repo
$ make run      # runs the docker through the given entrypoint script
$ make clean    # deletes the docker
$ make reset    # deletes the docker and then its image
```

<a name="clang"/>

### Clang Format
[![clang](https://img.shields.io/badge/clang-template-red.svg)](https://clang.llvm.org/docs/ClangFormat.html)

An example toy C project and how to format it using `clang-format`. Possible styles are:
* gnu
* google
* llvm
* chromium
* mozilla
* webkit
* microsoft

##### Dependencies
- [Clang](https://clang.llvm.org/docs/ClangFormat.html)

```sh
paru -S clang-format-all-git
```

##### Usage
```sh
$ make                # default, formats the given toy C project within google's style
$ make STYLE=<style>  # style according to the given variable
```

<a name="git"/>

### Git Hooks
[![sdl](https://img.shields.io/badge/git--hooks-template-yellow.svg)](https://pypi.org/project/cffi/)

A small repo to exemplify what one could do with `git hooks`. Also gives a minor
explanation to what specific hooks do, when they are activated and how they could
be used. Based on [this](https://www.atlassian.com/git/tutorials/git-hooks).

##### Dependencies
- [Git](http://www.lua.org/)

```sh
sudo pacman -S git
```

##### Usage
Not straightforward, please read through [README](git-hooks/README.md).

<a name="cffi"/>

### Python CFFI
[![cffi](https://img.shields.io/badge/Python_CFFI-template-3776AB.svg)](https://pypi.org/project/cffi/)

Example project template that implements a `C++` backend exposed through the use of `CFFI`.
The idea is to be able to use the flexibility of `Python`, but still harness the heavy
lifting or speed from `C++` through using bindings to connect data between the two stacks.

The backend compilation, packaging and installation is managed through `CMake`. Finally
through a couple of simple `Makefiles`, the different capabilities of the project are
abstracted away.

##### Dependencies
- [CMake](https://cmake.org/)
- [CFFI](https://cffi.readthedocs.io/en/latest/)
- [PyTest](https://docs.pytest.org/en/6.2.x/)

```sh
sudo pacman -S cmake
pip install cffi pytest
```

##### Usage
```sh
$ make build   # builds backend, installs it and compiles the C++-to-Python binding interface
$ make run     # runs the example python program that interfaces with the toy `C++` backend
$ make test    # runs unit-tests that ultimately test the python-wrappers that call upon the `C++` backend
$ make clean   # cleans project
```

<a name="sdl"/>

### C/Lua SDL2
[![sdl](https://img.shields.io/badge/C\/Lua_SDL-template-3776AB.svg)](https://pypi.org/project/cffi/)

Boilerplate code for small projects that need graphics with easy extendibility. Here it is done with
the `Lua` scripting language. This is also a learning project to look at the capabilities
of a work written in `C/C++` which can be scripted by users or extended with `Lua`.

The underlying graphics library is `SDL2`, which makes the project written in C.
This is also the chosen language since the `Lua` *VM* has a clean and powerful C API,
which was a language design goal. `Lua` was made to be embedded and further the capabilities of
a language such as `C`. The project would also be maintained by a portable build system like CMake.

##### Dependencies
- [CMake](https://cmake.org/)
- [Lua](http://www.lua.org/)
- [SDL2](https://github.com/libsdl-org/SDL)

```sh
sudo pacman -S cmake lua sdl2 sdl2_gfx sdl2_image sdl2_mixer sdl2_ttf
```

##### Usage
1. Build
```sh
$ cd build
$ cmake ..
$ make
```

2. Run
```sh
$ make run
```

<a name="mpi"/>

### C++ OpenMPI
[![mpi](https://img.shields.io/badge/OpenMPI-template-black.svg)](https://www.open-mpi.org/)

The Open MPI Project is an open source Message Passing Interface implementation that is developed and maintained by a consortium of academic, research, and industry partners.

The source files are not made by me and are taken from this [tutorial](www.mpitutorial.com), authored by Wes Kendall. This template serves as an easy way to compile all projects through CMake and be able to visualize their functionalities and capabilities.


##### Dependencies
- [CMake](https://cmake.org/)
- [OpenMPI](http://www.lua.org/)

```sh
sudo pacman -S cmake openmpi
```

##### Usage
1. Build
```sh
$ cd build
$ cmake ..
$ make
```

2. Run
```sh
$ ../bin/<binary name>
```

<a name="gtest"/>

### Google Test
[![gtest](https://img.shields.io/badge/-template-4285F4?style=flat-square&logo=google&logoColor=white)](https://www.docker.com/)

There are two example templates in this repo. One that attacks this problem through [CMake](https://cmake.org/) and another that
does so through [Bazel](https://bazel.build/).

#### Gtest CMake
Simple project template that aims:
1. To write code in `C` that is compiled/built with [CMake](https://cmake.org/).
2. Test the project using [GoogleTest's](http://google.github.io/googletest/) `C++` framework, which is also mantained through `CMake`.
3. Obtain coverage reports of said tests using GNU's `gcov/lcov`.
4. Integrates all goes through targets in CMake.

##### Dependencies
- [CMake](https://cmake.org/)
- [lcov](https://wiki.documentfoundation.org/Development/Lcov)

```sh
sudo pacman -S cmake lcov
```

##### Usage
1. Build Toy Project
```sh
$ cd build
$ cmake ..
$ make
```

2. Build Tests
```sh
$ cd test/build
$ cmake ..
$ make
```

3. Get Test Report
```sh
$ make report
```

4. Get Coverage Report
```sh
$ make coverage
```

5. Generate documentation for both
```sh
$ make docs
```

#### Gtest Bazel
Similar goals to the CMake version, however done so with Bazel.

##### Dependencies
- [Bazel](https://bazel.build/)
- [lcov](https://wiki.documentfoundation.org/Development/Lcov)

```sh
sudo pacman -S bazel lcov
```

##### Usage
1. **Building**
```
bazel build ...
```

2. **Running Tests and Obtaining Test Report**

```
python test.py
```

<a name="pytest"/>

### Pytest
[![python](https://img.shields.io/badge/-template-3776AB?style=flat-square&logo=Python&logoColor=white)](https://go.dev/)

Example use of [pytest](https://docs.pytest.org/en/7.1.x/) in a quick and dirty project. Should be changed to use a proper
initialized python module, not a c-like src file.

```
TODO
```

##### Dependencies
- [python](https://www.python.org/)
- [pytest](https://docs.pytest.org/en/7.1.x/)

## Dependencies
```
sudo pacman -S python
pip install pytest
```

##### Usage
```sh
$ make        # runs project
$ make test   # unit testing
$ make clean  # cleans project
```

<a name="lic"/>

## License
This project is released under the GNU Public license 3.0. See [LICENSE](LICENSE).

<a name="don"/>

## Donations
I have a ko-fi and a buy-me-a-coffee account, so if you found this repo useful and would like to show your appreciation, feel free to do so!

<p align="center">
<a href="https://ko-fi.com/duclos">
<img src="https://img.shields.io/badge/donation-ko--fi-red.svg">
</a>

<a href="https://www.buymeacoffee.com/danielduclos">
<img src="https://img.shields.io/badge/donation-buy--me--coffee-green.svg">
</a>

</p>

---
<p align="center">
<a href="https://github.com/duclos-cavalcanti/templates/LICENSE">
  <img src="https://img.shields.io/badge/license-GPL-blue.svg" />
</a>
<a>
  <img src="https://img.shields.io/github/languages/code-size/duclos-cavalcanti/templates.svg" />
</a>
<a>
  <img src="https://img.shields.io/github/commit-activity/m/duclos-cavalcanti/templates.svg" />
</a>

</p>

