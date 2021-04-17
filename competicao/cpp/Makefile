all: main

main: main.cpp
	g++ -o main main.cpp
	./main
	rm main

on: main.cpp
	g++ -o main main.cpp
	./main < in
	rm main

diff: main.cpp
	g++ -o main main.cpp
	./main < in > out
	diff out outm
	rm main

