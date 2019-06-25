# ctypes-numpy-example

A simple example of creating a python module using C or C++ code. Particularly, this repository shows how to pass a numpy array to a C function, and vice versa.

Folder [simplest](simplest) contains a minimum working example of calling a C function from a Python program. 

Folder [reference](reference) contains a reference example using good practices for organizing your files. It includes:
* Using [numpy.ctypeslib.ndpointer](https://docs.scipy.org/doc/numpy-1.13.0/reference/routines.ctypeslib.html#numpy.ctypeslib.ndpointer) for defining the input and output arguments of the C call. This is usefull for avoiding segmentation faults;
* Defining an [interface](reference/interface.c) for the C library;
* Caling C++ [code](reference/functions.cpp);

### Usage instructions:
1. Clone the repository
2. cd into directory "simplest" or "reference"
3. run "make"
4. call "python script.py"

There are many other approaches for integrating C/C++ code and Python, such as [Cython](https://cython.org/), [CFFI](https://cffi.readthedocs.io/en/latest/), [pybind11](https://pybind11.readthedocs.io/en/master/) and [Boost.Python](https://www.boost.org/doc/libs/1_70_0/libs/python/doc/html/index.html). If your interface between Python and C/C++ is really thin, that is, all you want to do is send some matrix to a C/C++ program, run some heavy calculation, and get the data back to Python, then I think ctypes is a great solution. It is a standard library and requires very little additional code. For other uses cases, the other approaches should be preferred.
