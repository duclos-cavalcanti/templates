import numpy as np
import os, logging
from cffi import FFI

try:
  import cpp_interface

except (ModuleNotFoundError, ImportError) as e:
  print(f"Importing of Backend failed:\n{e}\n")
  raise

#########################
# Wrappers for c++ code #
#########################

def my_add(a:int, b:int) -> (int):
    """
    C++ version backend

    """
    _ffi = FFI()

    # int_ptr = _ffi.cast("int*", val)
    a_ffi = _ffi.cast("int", a)
    b_ffi = _ffi.cast("int", b)

    result = cpp_interface.lib.my_add(a_ffi, b_ffi)

    return result

def my_sub(a:int, b:int) -> (int):
    """
    C++ version backend

    """
    _ffi = FFI()

    # int_ptr = _ffi.cast("int*", val)
    a_ffi = _ffi.cast("int", a)
    b_ffi = _ffi.cast("int", b)

    result = cpp_interface.lib.my_sub(a_ffi, b_ffi)

    return result

def my_mul(a:int, b:int) -> (int):
    """
    C++ version backend

    """
    _ffi = FFI()

    # int_ptr = _ffi.cast("int*", val)
    a_ffi = _ffi.cast("int", a)
    b_ffi = _ffi.cast("int", b)

    result = cpp_interface.lib.my_mul(a_ffi, b_ffi)

    return result

def main():
    a = 10
    b = 2

    print(f"a is {a} and b is {b}")

    add = my_add(a, b)
    print(f"a + b from C++: {add}")

    sub = my_sub(a, b)
    print(f"a - b from C++: {sub}")

    mul = my_mul(a, b)
    print(f"a * b from C++: {mul}")

if __name__ == "__main__":
  main()
