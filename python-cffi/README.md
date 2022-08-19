# CFFI-Python-Template

1. [CMake](https://cmake.org/)
2. [CFFI](https://cffi.readthedocs.io/en/latest/)
3. [PyTest](https://docs.pytest.org/en/6.2.x/)

Example project template that implements a `C++` backend exposed through the use of `CFFI`. 
The idea is to be able to use the flexibility of `Python`, but still harness the heavy
lifting or speed from `C++` through using bindings to connect data between the two stacks.

The backend compilation, packaging and installation is managed through `CMake`. Finally
through a couple of simple `Makefiles`, the different capabilities of the project are
abstracted away.



## Dependencies
1. `pip install cffi`
2. `pip install pytest`

## Targets
1. `make build`: builds backend, installs it and compiles the C++-to-Python binding interface.
2. `make run`: runs the example python program that interfaces with the toy `C++` backend.
3. `make test`: runs unit-tests that ultimately test the python-wrappers that call upon the `C++` backend.
4. `make clean`: cleans project.
