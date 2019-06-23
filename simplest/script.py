import numpy as np
import numpy.ctypeslib as npct
import ctypes as ct

# Import module
mymodule = npct.load_library('libpymodule', '.')

def call_multiply(arr_in, factor):
    ''' Convenience function for converting the arguments from numpy 
        array pointers to ctypes arrays. '''

    c_intp = ct.POINTER(ct.c_int)                      # ctypes integer pointer 
    c_uintp = ct.POINTER(ct.c_uint)                    # ctypes unsigned integer pointer 

    # Call function
    mymodule.multiply(arr_in.ctypes.data_as(c_intp),   # Cast numpy array to ctypes integer pointer
                    factor,                            # Python integers do not need to be cast
                    arr_out.ctypes.data_as(c_intp), 
                    shape.ctypes.data_as(c_uintp))
                    
    return arr_out

# Generate some 2D numpy array
N = 5
arr_in = np.arange(N**2, dtype=np.int32).reshape(N, N)

# Allocate the output array in memory, and get the shape of the array
arr_out = np.zeros_like(arr_in)
shape = np.array(arr_in.shape, dtype=np.uint32)

# Call function
factor = -2
arr_out = call_multiply(arr_in, factor)

print(arr_out)

