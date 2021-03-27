all: main

main: main.cpp
	g++ -o main main.cpp
	./main
	rm main

on: main.cpp
	g++ -o main main.cpp
	./main < tests/in
	rm main

diff: main.cpp
	g++ -o main main.cpp
	./main < tests/in > tests/out_mine
	diff tests/out tests/out_mine
	rm main

copy: main.cpp
	cp main.cpp $(path)/$(name)