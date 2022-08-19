## Interface python code for CFFI

## Imports
from cffi import FFI

def compile_interface(verbose:bool = True) -> object:
  ffi = FFI()
  ffi.cdef("""int my_add(int a, int b);
              int my_sub(int a, int b);
              int my_mul(int a, int b);
           """)

  ffi.set_source("cpp_interface",
                 """ #include "interface.h" """,
                 include_dirs=['include'],
                 libraries=['backend'],
                 library_dirs=['lib'],
                 extra_link_args=['-Wl,-rpath=$ORIGIN/lib', '-fopenmp'],
                 extra_compile_args=['-O3', '-ffast-math', '-fopenmp', '-D use_openmp'],
                 source_extension='.cpp')

  return ffi.compile(verbose=verbose)

def main():
  compile_interface()

if __name__ == "__main__":
  main()
