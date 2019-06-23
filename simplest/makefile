# -fpic means Position Independent Code. It is necessary when compiling shared libraries
# -shared is used for creating a shared library
libpymodule.so: c_code.c
	gcc -fpic -Wall -shared c_code.c -o libpymodule.so
