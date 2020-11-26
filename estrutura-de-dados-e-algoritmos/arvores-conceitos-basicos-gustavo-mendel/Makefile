.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	BT

BT:  BT.o cBinaryTree.o cNode.o
	g++ -o $@ $^

clean:
	rm *.o *.*~ BT