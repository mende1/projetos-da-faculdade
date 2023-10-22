#!/bin/bash
# no parameters
# add your Flex code to scr/blite.l
# you don't need to modify src/blite.y
# do NOT change src/main.c

T1=$(pwd)

# run inside src
cd src
bison -d blite.y

flex blite.l           

cc -o blite lex.yy.c blite.tab.c main.c

# change blite to exec and move it to T1
chmod +x blite
mv blite "$T1"

# clean
rm lex.yy.c
rm blite.tab.*

# back to T1
cd "$T1"

