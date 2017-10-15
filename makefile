all: array_tools integral test 
	g++ -std=c++11 array_tools.o integral.o test.o -o  test.out
	make clean

array_tools: array_tools.h array_tools.cpp
	g++ -std=c++11 -c array_tools.cpp

integral: integral.h integral.cpp
	g++ -std=c++11 -c integral.cpp

test: test.cpp 
	g++ -std=c++11 -c   test.cpp


clean:
	rm -rf *.o
