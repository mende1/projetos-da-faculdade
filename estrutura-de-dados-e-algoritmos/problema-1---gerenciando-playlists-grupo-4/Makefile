VPATH = src/

.cpp.o:	$*.h
	g++	-c src/$*.cpp

all: main

main: main.o musica.o playlist.o openCsv.o playlistOrdenacao.o
	g++ -o $@ $^
	rm *.o

exe:
	./main
	rm main