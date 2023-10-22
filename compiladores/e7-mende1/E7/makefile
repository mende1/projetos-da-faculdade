install:
	sudo apt-get install -f flex
	sudo apt-get install bison

compile:
	bison -d e7.y
	flex e7.l
	cc -o interpreta lex.yy.c e7.tab.c main.c

test:
	./run_tests.sh

all:
	make install
	make compile
	make test

