.c.o:   $*.h
	gcc -Wall -c $*.c

.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	registros

registros:	registros.o 
	gcc -o $@ $^ -lm 

clean:
	rm *.*~ *~ *.o registros
	
