#include <iostream>
#include "interface.h"

int*** aloc_vol(unsigned int *shape) {

  int*** vol = new int **[shape[0]];
  for (int plane=0; plane<shape[0]; plane++) {
    vol[plane] = new int *[shape[1]];
    for (int row=0; row<shape[1]; row++) {
      vol[plane][row] = new int [shape[2]];
    }
  }

  return vol;

}

void copy(int ***vol1, int ***vol2, unsigned int *shape) {

	unsigned int num_planes, num_rows, num_cols;

  num_planes = shape[0];
  num_rows = shape[1];
  num_cols = shape[2];

  for (int plane=0; plane<num_planes; plane++) {
    for (int row=0; row<num_rows; row++) {
      for (int col=0; col<num_cols; col++) {
        vol1[plane][row][col] = vol2[plane][row][col];
      }
    }
  }
}

// Transforma o array de entrada em um volume
int*** arr_2_vol(int* arr, unsigned int *shape) {
	unsigned int num_planes, num_rows, num_cols;
  int ***vol;

  num_planes = shape[0];
  num_rows = shape[1];
  num_cols = shape[2];

  vol = aloc_vol(shape);

  for (int plane=0; plane<num_planes; plane++) {
    for (int row=0; row<num_rows; row++) {
      for (int col=0; col<num_cols; col++) {
        vol[plane][row][col] = arr[plane*num_rows*num_cols + row*num_cols + col];
      }
    }
  }

	return vol;
}

// Transforma o volume final em um array de saida
void vol_2_arr(int*** vol, int* arr, unsigned int *shape) {

	unsigned int num_planes, num_rows, num_cols;

  num_planes = shape[0];
  num_rows = shape[1];
  num_cols = shape[2];

  for (int plane=0; plane<num_planes; plane++) {
    for (int row=0; row<num_rows; row++) {
      for (int col=0; col<num_cols; col++) {
        arr[plane*num_rows*num_cols + row*num_cols + col] = vol[plane][row][col];
      }
    }
  }
}

void apply_operation(int *arr_in, int *arr_out, unsigned int *shape) {

  int ***vol_in, ***vol_out;

  vol_in = arr_2_vol(arr_in, shape);

  // Apply operations on volume 

  vol_out = multiply(vol_in, shape);

  // ------------------------

  vol_2_arr(vol_out, arr_out, shape);

}

#ifdef __cplusplus
extern "C" {
#endif

int operation(int *arr_in, int *arr_out, unsigned int *shape)
{
  apply_operation(arr_in, arr_out, shape);
  return 0;
}

#ifdef __cplusplus
}
#endif
