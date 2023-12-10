cd src

bison -d blite.y --debug --verbose

flex blite.l

cc -o blite lex.yy.c blite.tab.c main.c

chmod +x blite

mv blite ../

rm lex.yy.c blite.tab.c blite.tab.h