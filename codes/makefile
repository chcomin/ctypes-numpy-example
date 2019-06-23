libpymodule.so: c_or_cpp_code.cpp
	g++ -c -fpic -Wall c_or_cpp_code.cpp
	g++ -shared -o libpymodule.so c_or_cpp_code.o
	rm -f c_or_cpp_code.o
