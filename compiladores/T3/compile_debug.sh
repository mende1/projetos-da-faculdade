cd src

bison -d blite.y --debug --verbose

flex blite.l

cc -o blite blite.tab.c lex.yy.c main.c ast.c

chmod +x blite

mv blite ../

rm lex.yy.c blite.tab.c blite.tab.h