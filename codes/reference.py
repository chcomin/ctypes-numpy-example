import numpy as np
import numpy.ctypeslib as npct
import ctypes as ct

# Importa modulo e define argumentos
mymodule = npct.load_library('libmymodule', '.')
args = [npct.ndpointer(dtype=np.int32, ndim=3, flags=['C_CONTIGUOUS']),
        npct.ndpointer(dtype=np.int32, ndim=3, flags=['C_CONTIGUOUS']),
        npct.ndpointer(dtype=np.uint32, ndim=1, flags=['C_CONTIGUOUS'])
    ]
mymodule.operation.argtypes = args
mymodule.operation.restype = ct.c_int


vol_in = (10*np.random.randn(5, 4, 3)).astype(np.int32)

for plane in vol_in:
    for row in plane:
        for val in row:
            print(val, end=' ')
        print('')
    print('')

vol_out = np.zeros_like(vol_in)
shape = np.array(vol_in.shape, dtype=np.uint32)
mymodule.operation(vol_in, vol_out, shape)