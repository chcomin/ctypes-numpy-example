/* This file contains some example functions operating over arrays. */

#include <iostream>

/**
  Print input array

  Parameters
  ---------
  arr_in : int*
    Input array.
  shape : unsigned int*
    Shape of the input array.
 */
void apply_print(int* arr_in, unsigned int* shape) {

  unsigned int num_rows, num_cols, row, col;

  num_rows = shape[0];
  num_cols = shape[1];

  std::cout <<  "C array values: " << std::endl;
  for (row=0; row<num_rows; row++) {
    for (col=0; col<num_cols; col++) {
      std::cout << arr_in[row*num_cols + col] << " ";
    }
    std::cout << std::endl;
  }
  std::cout <<  std::endl;
}

/**
  Multiply input array by a given integer factor. The output is calculated as
  arr_out[i] = factor*arr_in[i]

  Parameters
  ---------
  arr_in : int*
    Input array.
  factor : int
    Constant used in the multiplication.
  arr_out : int*
    Output array. Must be pre-allocated in memory.
  shape : unsigned int*
    Shape of the input array.
 */
void apply_multiply(int *arr_in, int factor, int *arr_out, unsigned int *shape) {

  unsigned int num_rows, num_cols, row, col;

  num_rows = shape[0];
  num_cols = shape[1];

  for (row=0; row<num_rows; row++) {
    for (col=0; col<num_cols; col++) {
      arr_out[row*num_cols + col] = factor*arr_in[row*num_cols + col];
    }
  }

}
