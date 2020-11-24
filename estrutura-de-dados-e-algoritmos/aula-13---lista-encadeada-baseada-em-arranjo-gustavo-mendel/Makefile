.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	mainListaEncVet

mainListaEncVet:	mainListaEncVet.o tadListEncVet.o tadNo.o
	g++ -o $@ $^


clean:
	rm *.o mainListaEncVet 
	