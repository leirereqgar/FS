CC := g++
flags := -std=c++11 -g -Wall
INCLUDE := ./
LIB := ./

all: examen2

examen2: pr.o mateslib.a
	$(CC) -L $(LIB) -o $@ $^ $(flags)

pr.o: pr.cpp
	$(CC) -I$(INCLUDE) -c $< $(flags)

mateslib.a: complex.o dist.o geom.o vector.o
	ar -rvs mateslib.a $^

complex.o: complex.cpp
	$(CC) -I$(INCLUDE) -c $< $(flags)

dist.o: dist.cpp
	$(CC) -I$(INCLUDE) -c $< $(flags)

geom.o: geom.cpp
	$(CC) -I$(INCLUDE) -c $< $(flags)

vector.o: vector.cpp
	$(CC) -I$(INCLUDE) -c $< $(flags)

limpiar:
	rm *.o
	rm *.a
	rm examen2

instalar: examen2
	mkdir -p bin SOURCE CABECERAS LIB
	mv examen2 bin
	mv *.cpp SOURCE
	mv *.h CABECERAS
	mv *.a LIB
	rm *.o

desinstalar:
	mv SOURCE/*.cpp ./
	mv CABECERAS/*.h ./
	rmdir SOURCE
	rmdir CABECERAS
	rm -rf bin
	rm -rf LIB
