%{
#include <stdio.h>
#include "y.tab.h"
%}

%option noinput nounput

%%
"->"						{return tok_arrow;}
[1-9][0-9]*					{yylval.num = atoi(yytext); return tok_i64;}
[a-zA-Z][_a-zA-Z0-9]*		{yylval.id = yytext; return tok_identifier;}
[ \t\r\n]					;
.							{ECHO;}

%%
int yywrap(void) { return 1; }
