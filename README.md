# Project Templates

1. [Introduction](#intro)
2. [Templates](#templates)
    1. [Go](#go)
    2. [Rust](#rust)
    3. [C](#C)
    4. [Cpp](#cpp)
2. [License](#lic)
2. [Donations](#don)

<a name="intro"/>

## Introduction
Every time I'm learning a new technology or a new language, I feel the need to create a reproducible template project that has already the basics built in. The idea is to have a somewhat abstracted away template, such that I
can in the future use it as a basis for an actual project without having to remember fine details and commands to the specific tech stack at hand.

Since that was becoming a strong habit and there were numerous little template projects littered throughout my profile, I took the liberty to unify them under a single repository. They hopefully have the basics covered, as in a language
it should have compiling, running, testing and debugging as targets or at least documentation on how to perform these actions for the given template.

## Templates
- [Go](#go)
- [Rust](#rust)
- [C](#C)
- [Cpp](#cpp)
- [Haskell](#haskell)

<a name="go"/>

### Go
[![golang](https://img.shields.io/badge/-template-00ADD8?style=flat-square&logo=Go&logoColor=white)](https://go.dev/)

##### Dependencies
- [go](https://go.dev/)
- [dlv](https://github.com/derekparker/delve) for debugging, if needed
- [godoc](https://pkg.go.dev/golang.org/x/tools/cmd/godoc) for documentation generation

```sh
$ go install  https://github.com/derekparker/delve
$ go install  golang.org/x/tools/cmd/godoc
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

##### Usage
```sh
$ cargo build             # build's project
$ cargo build --release   # stores executable in target/release and performs optimizations
$ cargo check             # checks if project compiles without building
$ cargo run               # builds project and runs binary
$ cargo test              # unit testing
$ cargo fmt               # format go files
```

<a name="C"/>

### C
<img alt="C" src="https://img.shields.io/badge/-template-A8B9CC?style=flat-square&logo=c&logoColor=white" />

##### Dependencies

- [CMake](https://cmake.org/)

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

### Cpp
<img alt="C" src="https://img.shields.io/badge/-template-00599C?style=flat-square&logo=cplusplus&logoColor=white" />

##### Dependencies

- [CMake](https://cmake.org/)

##### Usage

Almost a 1 to 1 copy of the [C]("C") template. If it is necessary to specify a version of the language change the following line within `CMakeLists.txt`:

```cmake
set (CMAKE_CXX_STANDARD 11)
```

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
</p>

