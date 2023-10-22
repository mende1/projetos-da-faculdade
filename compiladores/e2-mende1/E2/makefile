install:
	sudo apt-get install -f flex
	sudo apt-get install bison

compile:
	bison -d e2.y
	flex e2.l
	cc -o valida lex.yy.c e2.tab.c main.c

test:
	./run_tests.sh

all:
	make install
	make compile
	make test

