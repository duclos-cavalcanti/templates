# Bazel-Template with GoogleTest

## Table of Contents
1. [Introduction](#introduction)
2. [Dependencies](#dependencies)
3. [Installation](#installation)
4. [Usage](#usage)
5. [File Structure](#filestructure)

<a name="introduction"/>

# 1. Introduction

Simple project template to write code in `C` that is compiled and built with [Bazel](https://bazel.build/) and can be tested using [GoogleTest's](http://google.github.io/googletest/) `C++` testing framework.


Simple project template that aims:
1. To write code in `C` that is compiled/built with [Bazel](https://bazel.build/).
2. Test the project using [GoogleTest's](http://google.github.io/googletest/) `C++` framework, which is also mantained through `Bazel`.
3. Obtain coverage reports of said tests using GNU's `gcov/lcov`.

<a name="dependencies"/>

## 2. Dependencies
* `Bazel`
* `GCC`
* `Python`
* `gcov` and `lcov`

<a name="installation"/>

## 3. Installation
### Linux
#### Arch-based systems
Python is assumed to already be installed, as well as the `gcc` toolchain.
```sh
sudo pacman -S bazel
```

From the AuR:
```sh
git clone https://aur.archlinux.org/lcov.git
cd lcov
makepkg -si
```

#### Ubuntu and Debian-based systems
Python is assumed to already be installed, as well as the `gcc` toolchain.
```sh
sudo apt-get install lcov gcov
```
For `Bazel`, instructions were taken from [here](https://docs.bazel.build/versions/main/install-ubuntu.html).
```sh
sudo apt install apt-transport-https curl gnupg
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
sudo mv bazel.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list

sudo apt update && sudo apt install bazel
```

### Mac OS
1. If `Homebrew` is already installed go to `2`, else:
```sh
/bin/bash -c "$(curl -fsSL \
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

2. Then:
```
brew install bazel gcc gcovr lcov
```
Python is assumed to already be installed.

### Windows
```
¯\\(°_o)/¯
```

TODO: Complete this.

<a name="usage"/>

## 4. Usage
See [5. File Structure](#filestructure) to be able to have a better visual representation
of the following explanation.

1. **Building**
```
bazel build ...
```

2. **Running Tests and Obtaining Tests Report**

```
python test.py
```

<a name="filestructure"/>

## 5. File Structure
```
.
├── main
│   ├── include
│   ├── lib
│   │   └── include
│   └── src
└── test
    ├── include
    ├── mock
    │   └── include
    ├── reports
    │   ├── coverage
    │   └── html
    └── src
```
