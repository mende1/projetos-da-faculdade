#!/bin/bash

testenv=$(pwd)
src=/src

cd "$testenv$src"
bison -d "$testenv$src/blite.y"
flex "$testenv$src/blite.l"
cc -o blite blite.tab.c lex.yy.c main.c ast.c
cp "$testenv$src/blite" $testenv
cd $testenv

