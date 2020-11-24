.cpp.o:	$*.h
	g++	-c $*.cpp

all:	main

main:  main.o	# os modulos devem ser incluidos aqui.
	g++ -o $@ $^

clean:
	rm main *.o
