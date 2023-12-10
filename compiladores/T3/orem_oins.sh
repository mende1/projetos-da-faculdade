#!/bin/bash

testenv=$(pwd)
src=/src

cd "$testenv"
flex "$testenv/orem.l"
cc -o orem lex.yy.c
flex "$testenv/oins.l"
cc -o oins lex.yy.c


