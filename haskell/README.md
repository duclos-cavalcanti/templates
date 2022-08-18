# Learning Haskell

1. [Introduction](#Introduction)
2. [Dependencies](#deps)
3. [Getting Started](#start)
    1. [Build](#build)
    2. [REPL](#repl)
    3. [Test](#test)
    4. [Documentation](#docs)
    5. [Haskell Material](#search)

<a name="Introduction"/>

## 1. Introduction
Inspired by [this](https://github.com/joshcough/HaskellStarter#getting-started-with-this-project) awesome `haskell` starter project, 
I made this small *repo* to visualize and learn the possible ways to go about haskell projects and templates. The idea was to 
partially make annotations about the tools and development process of a haskell project, but also make some boilerplate structure to the 
project to go along with it.

<a name="deps"/>

## 2. Dependencies
### Arch Linux
```sh
sudo pacman -S ghc ghc-static haskell cabal-install stack
cabal install base
cabal install github # example of direct haskell installation, not needed here
```

<a name="start"/>

## 3. Getting Started

<a name="build"/>

### 1. Build
#### Cabal
Cabal (Common Architecture for Building Applications and Binaries) enables us to 
build `haskell` libraries and programs. This is the/one of the standard tool for haskell projects.
[This](https://www.haskell.org/cabal/) is a great starting point to understand how to work with cabal.

A few helpful commands for getting started with Cabal:

```sh
$ cabal --help
$ cabal update
$ cabal init
$ cabal install github
$ cabal build
$ cabal test
$ cabal repl
$ cabal install
```

* `cabal --help` shows you all the Cabal commands. Highly recommended.
* `cabal update` updates Cabal so that it has all of the latest package information.
* `cabal init` runs you through a series of questions to start a new project.
* `cabal build` builds your project locally (into the `dist` directory).
* `cabal test` builds your project and then runs all of your tests.
    * Given the `--enable-tests` flag, all tests will be run and only installs the library if the tests pass!
    * All `test-suite` configurations in the `*.cabal` file get ran when running this command.
* `cabal repl` runs GHCI with your project already loaded.
* `cabal install` installs a package.
  * Given zero arguments, it will install your package.
  * Given any number of library arguments (like `cabal install github` which was used above), it will download those libraries from hackage, build, and install them.
  * Given `--only-dependencies`, it will install all your package's dependencies.  This is the recommended way to install new libraries to a project, as it will choose a version to install that is compatible with your other dependencies.
  * Normal installs executables in your project as well as the library. Location is by default `~/.cabal/bin`.

There is however an issue with dynamic vs static building with Cabal. By default it will try to build the project in a static manner, which will then require that specific libraries are 
located within your system. This makes for a greater RAM usage and larger binaries. Also different OSes will make different choices on how to distribute the haskell packages. This ultimately means one 
for an OS that only distribute dynamic libraries, one has to either install extra packages and change some many system configurations or settle to configure cabal to work with dynamic libraries. This is the case 
for Arch Linux so the following lines have to be added/uncommented at the `~/.cabal/config`. More about this can be found [here](https://wiki.archlinux.org/title/Haskell#Static_linking).
```sh
library-vanilla: False
shared: True
executable-dynamic: True
program-default-options
  ghc-options: -dynamic
```

After this, once can build the same project with `cabal build` even when using the stack-generated config.

#### Stack
This is another option and was ultimately chosen due to its easy configuration and wrapping around Cabal. Great starting 
points are [here](https://docs.haskellstack.org/en/stable/README/) and [here](https://docs.haskellstack.org/en/stable/GUIDE/). Stack 
facilitates the use of cabal to manage dependencies, sandbox builds and therefore resolves the `dynamic packaging` issue from Cabal above 
without any configurations having to be made. This makes for this specific OS an easier choice and also one that can be done on any other 
platform since stack has the sandboxing approach.

```sh
$ stack new
$ stack build
$ stack exec
$ stack test
$ stack setup
$ stack ghc 
$ stack ghci
$ stack runghc
```

<a name="repl"/>

### 2. REPL
#### ghci
`ghci` is something like a haskell REPL where we can try out and evaluate haskell code in real time.
```sh
$ ghci
```

#### Cabal
Starts ghci REPL with all the modules preloaded.
```sh
$ cabal repl
```

<a name="test"/>

### 3. Test
In Haskell and Cabal there are a lot of different test libraries and frameworks:

- HUnit – a library for writing unit tests
- QuickCheck – a library for writing properties
- test-framework – a framework for organizing and running unit tests and properties
- doctest – inject tests directly into your documentation

Tests can be easily automated with a CI tool such as `Travis CI` and the cabal build 
tool.

#### Travis CI
```sh
TODO
```

<a name="docs"/>

### 4. Documentation
#### Haddock - Haskell Documentation
```sh
TODO
```

<a name="search"/>

### 5. Haskell Material
#### Hackage
Haskell packages :)

- [http://hackage.haskell.org](http://hackage.haskell.org)
- [http://hackage.haskell.org/packages](http://hackage.haskell.org/packages)
- [http://hackage.haskell.org/upload](http://hackage.haskell.org/upload)

#### Hoogle
[Hoogle](https://hoogle.haskell.org/) is the go place for searching haskell-related APIs.

- Functions 
- Libraries 
- Documentation 
- Links to source code

#### [Learn You a Haskell](http://learnyouahaskell.com/chapters)
Great starting point to learn Haskell! Some examples of what it covers: 
1. Introduction to the Haskell Paradigm (Chapter 1: Introduction)
    - Purely Functional Programming
    - Lazy Computations
    - Statically Typed

2. Basics (Chapter 2: Starting Out)
    - Arithmetic
    - Comparison/Booleans/if statements
    - Bultin and Simple Functions
    - Lists
    - Ranges
    - **List Comprehension**
    - Tuples

3. Types and Typeclasses (Chapter 3: Types and Typeclasses)
    - `:t` and `::` (has type of)
    - Different Types 
    - Function Type declarations
    - **Type Variable**
    - Typeclasses (Interface that defines behavior, types belong to typeclasses)

4. Functions (Chapter 4: Syntax in Functions)
    - Pattern matching
    - Guards, otherwise, where
    - Let .. in Expressions
    - Case Expressions

5. Recursion (Chapter 5: Recursion)
    - Concept
    - Edge Conditions/Cases
    - Edge Cases and Identities

6. Higher Order Functions (Chapter 6: Higher Order Functions)
    - Curried Functions
    - Functons as first-class citzens (Functions returning Functions)
    - Maps and Filters
    - Lambdas
    - Folds and Scans
    - Functions with $ - Right Associative
    - Function Composition

7. Modules (Chapter 6: Modules)
8. Custom Types and Typeclasses (Chapter 6: Making your own Types and Typeclasses)
