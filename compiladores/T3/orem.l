%option noyywrap yylineno nodefault
%{
%}

%%

(" ")+  { fprintf(stdout, "%s", " "); return 1; }
[\n]    { return 1; }
EOL     { return 0; }
.*      { fprintf(stdout, "%s", yytext); return 1;}
%%

int main(int argc, char **argv) {
	int t; 
	while((t=yylex())) { }
        fprintf(stdout, "%s", "\n");
}

