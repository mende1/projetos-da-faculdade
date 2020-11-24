.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	TADExample 

TADExample:	TADExample.o tadVetorDin.o
	g++ -o $@ $^


clean:
	rm *.o TADExample 
	