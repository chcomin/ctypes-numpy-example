#include <iostream>

void print_values(int* arr_in, unsigned int* shape) {

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

void apply_operation(int *arr_in, int *arr_out, unsigned int *shape) {

  unsigned int num_rows, num_cols, row, col;

  num_rows = shape[0];
  num_cols = shape[1];

  for (row=0; row<num_rows; row++) {
    for (col=0; col<num_cols; col++) {
      arr_out[row*num_cols + col] = 2*arr_in[row*num_cols + col];
    }
  }

}

#ifdef __cplusplus
extern "C" {
#endif

int operation(int *arr_in, int *arr_out, unsigned int *shape) {
  print_values(arr_in, shape);
  apply_operation(arr_in, arr_out, shape);
  return 0;
}

#ifdef __cplusplus
}
#endif
