%option noyywrap yylineno nodefault
%{
%}

%%

"["   { fprintf(stdout, "%s", "\n["); return 1; }
[ \n] { return 1; }
EOL   { return 0; }
.     { fprintf(stdout, "%c", yytext[0]); return 1; }
%%

int main(int argc, char **argv) {
	int t=1; 
	while(t) {
	  t = yylex();
        }
}

