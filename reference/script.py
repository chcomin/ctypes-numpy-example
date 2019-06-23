import numpy as np
import numpy.ctypeslib as npct
import ctypes as ct

# Import module
mymodule = npct.load_library('libpymodule', '.')

# Define the arguments accepted by the C functions. This is not strictly necessary,
# but it is good practice for avoiding segmentation faults. 
npflags = ['C_CONTIGUOUS']   # Require a C contiguous array in memory
uint_1d_type = npct.ndpointer(dtype=np.uint32, ndim=1, flags=npflags)
int_2d_type = npct.ndpointer(dtype=np.int32, ndim=2, flags=npflags)
args = [int_2d_type,
        uint_1d_type,     
       ]
mymodule.print.argtypes = args

args = [int_2d_type,
        ct.c_int,      # Integer type
        int_2d_type,
        uint_1d_type
       ]
mymodule.multiply.argtypes = args

# Define return type of the C fucntions. Also not necessary, but good practice.
mymodule.print.restype = ct.c_int
mymodule.multiply.restype = ct.c_int

# Generate some numpy array
N = 5
arr_in = np.arange(N**2, dtype=np.int32).reshape(N, N)

# Allocate the output array in memory, and get the shape of the array
arr_out = np.zeros_like(arr_in)
shape = np.array(arr_in.shape, dtype=np.uint32)

# Call functions
mymodule.print(arr_in, shape)
factor = -2
mymodule.multiply(arr_in, factor, arr_out, shape)

print(arr_out)

