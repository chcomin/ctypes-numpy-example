# -fpic means Position Independent Code. It is necessary when compiling shared libraries
# -shared is used for creating a shared library
libpymodule.so: interface.c functions.cpp
	g++ -c -fpic -Wall interface.c functions.cpp
	g++ -shared -o libpymodule.so interface.o functions.o
	rm -f interface.o functions.o