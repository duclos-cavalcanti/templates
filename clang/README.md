# ClangFormat-C

Simple repo to exhibit the use of `clang-format`.

The Makefile contains targets for:
* gnu 
* google 
* llvm 
* chromium 
* mozilla 
* webkit 
* microsoft

Usage:
1. Default: google
```
make
```

2. Different Style
```sh
make STYLE=<style>
# replace style with mozilla or any of the listed style above
```

This will format the `*.c` and `*.h` files within the project to the according style guide.


