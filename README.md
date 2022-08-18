# Project Templates

1. [Introduction](#intro)
2. [Templates](#templates)
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

<a name="C"/>

### C

With the [CMake](https://cmake.org/) build system it is possible to abstract away much of the flags and command line arguments needed within a large project. To be able to build said project, these are the necessary steps:

```sh
cd build
cmake ..
make
```

Additionally, there are two bakes in targets called `run` and `debug`. How they are setup can be seen in the
`.cmake` files found in the cmake folder within the template project. They do as their name suggest, however to
be able to successfully use the debugger, one needs [gdb](https://sourceware.org/gdb/bugs/) installed in their system.

### Cpp

Almost a 1 to 1 copy of the [C]("C") template. If it is necessary to specify a version of the language change the following line within `CMakeLists.txt`:

```cmake
set (CMAKE_CXX_STANDARD 11)
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

