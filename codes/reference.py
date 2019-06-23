import numpy as np
import numpy.ctypeslib as npct
import ctypes as ct

# Import module
mymodule = npct.load_library('libpymodule', '.')
args = [npct.ndpointer(dtype=np.int32, ndim=2, flags=['C_CONTIGUOUS']),
        npct.ndpointer(dtype=np.int32, ndim=2, flags=['C_CONTIGUOUS']),
        npct.ndpointer(dtype=np.uint32, ndim=1, flags=['C_CONTIGUOUS'])
    ]
mymodule.operation.argtypes = args
mymodule.operation.restype = ct.c_int

N = 5

arr_in = np.random.randint(0, 10, (N, N), dtype = np.int32)

print("Numpy input array values: ")
for row in arr_in:
    for val in row:
        print(val, end=' ')
    print()
print()


arr_out = np.zeros_like(arr_in)
shape = np.array(arr_in.shape, dtype=np.uint32)
mymodule.operation(arr_in, arr_out, shape)

print("Numpy output array values: ")
for row in arr_out:
    for val in row:
        print(val, end=' ')
    print()
print()