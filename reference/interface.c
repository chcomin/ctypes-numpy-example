/* This file contains the interface of the library. That is, the functions
   that will be called by the Python program. Each function just calls the
   respective function defined elsewhere (in this case, functions in file
   functions.cpp). */

#include "functions.h"

/* Verify if __cplusplus is defined, so that only C++ compilers will
    see the extern "C" command */
#ifdef __cplusplus
/* extern "C" is used for defining C code when compiling with a C++ compiler.
   This is necessary since ctypes needs to call a C function. */
extern "C" {
#endif

// Definitions of the interface functions

int print(int *arr_in, unsigned int *shape) {
  apply_print(arr_in, shape);
  return 0;
}

int multiply(int *arr_in, int factor, int *arr_out, unsigned int *shape) {
  apply_multiply(arr_in, factor, arr_out, shape);
  return 0;
}

#ifdef __cplusplus
}
#endif
