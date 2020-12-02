.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	BST

BST:  BST.o cBinarySearchTree.o cNode.o
	g++ -o $@ $^

clean:
	rm *.o BST