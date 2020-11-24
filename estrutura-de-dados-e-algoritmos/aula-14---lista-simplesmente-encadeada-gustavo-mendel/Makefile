.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	LSE-Dinamica 

LSE-Dinamica:	LSE-Dinamica.o tadListaEncDin.o tadNo.o
	g++ -o $@ $^


clean:
	rm *.o LSE-Dinamica 
	