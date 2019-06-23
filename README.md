# ctypes-numpy-example

A simple example of creating a python module using C or C++ code.

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
