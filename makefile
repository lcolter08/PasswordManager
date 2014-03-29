#makefile


MovieTest: MovieInventory.o Movie.o

	g++ MovieInventory.o Movie.o -o MovieTest


MovieInventory.o: MovieInventory.cpp MovieInventory.h

	g++ -c MovieInventory.cpp



Movie.o: Movie.cpp Movie.h

	g++ -c Movie.cpp
