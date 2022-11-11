main: complex.o main.o
		g++  -O -o main -lm main.o  complex.o

complex.o: complex.hpp complex.cpp
		g++  -O -c complex.cpp

main.o: complex.hpp main.cpp
		g++  -O -c main.cpp

clean:
		rm *.o main 
