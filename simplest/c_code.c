/**
  Multiply input array by a given integer factor. The output is calculated as
  arr_out[i] = factor*arr_in[i]. 
  The function loops over rows and columns but index the arrays as 1D. This is 
  done only to show that we can use the shape parameter for obtaining the number
  of rows and columns of the array.

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
int multiply(int *arr_in, int factor, int *arr_out, unsigned int *shape) {

  unsigned int num_rows, num_cols, row, col;

  num_rows = shape[0];
  num_cols = shape[1];

  for (row=0; row<num_rows; row++) {
    for (col=0; col<num_cols; col++) {
      arr_out[row*num_cols + col] = factor*arr_in[row*num_cols + col];
    }
  }

  return 0;
}
