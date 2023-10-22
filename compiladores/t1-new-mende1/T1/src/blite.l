%option noyywrap yylineno nodefault
%{

// noyywrap    - no need to deal with multiple input files
// yylineno    - variable to track line numbers 
// nodefault   - do not add a default rule at the end of the scanner 
//               that copies otherwise unmatched input to yyout.

#include "blite.tab.h"

%}

%%

"//"(.)*\n { /* ignore comments */ }

"boolean" |
"else" |
"false" |
"function" |
"if" |
"integer" |
"print" |
"return" |
"string" |
"true" |
"void" |
"while" { return KEY; }

\"(\\[n0]|[^\"\\\n])*\" { if (yyleng > 256) return ERROR; else return STRING; }

[0-9]+ { return NUM; }

\+ |
\- |
\* |
\/ |
\% |
\! |
\< |
\> |
\= |
\: |
\; |
\, |
\( |
\) |
\{ |
\} { return SYM; }

\<\= |
\>\= |
\=\= |
\!\= |
\&\& |
\|\| { return SYMC; }

[a-zA-Z][a-zA-Z0-9_]* { if (yyleng > 256) return ERROR; else return ID; }

[ \t\n\r] { /* ignore whitespace */ }

. { return ERROR; }

%%