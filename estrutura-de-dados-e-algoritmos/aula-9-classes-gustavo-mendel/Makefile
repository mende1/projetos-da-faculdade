.cpp.o:	$*.h
	g++	-c $*.cpp

all:	TADExample

TADExample:  TADExample.o
	g++ -o $@ $^

clean:
	rm TADExample *.o
