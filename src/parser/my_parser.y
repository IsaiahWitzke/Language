%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>

%}

%union {int num; char *id;}
%start module
/* %token tok_eof tok_func tok_extern tok_if tok_then tok_else tok_for tok_in */
%token <id> tok_identifier
%token <num> tok_number
%token tok_i128 tok_i64 tok_i32 tok_i16 tok_f128 tok_f64 tok_f32 tok_f16
%token tok_arrow	/* -> */

%%

module	: stmts			{;}
		;

stmts	: stmt			{;}
		| stmt stmts	{;}
		;

stmt	: expr				{;}
		| variable_decl		{;}
		| variable_def		{;}
		;

variable_decl	: typed_identifier ';'			{;}
				;
variable_def	: typed_identifier '=' expr ';'	{;}
				| typed_identifier '=' '{' stmts '}'	{;}
				;


typed_identifier	: tok_identifier ':' type	{;}
					;

typed_identifiers	: typed_identifier							{;}
					| typed_identifier ',' typed_identifiers	{;}

type	: basic_type	{;}
		| function_type	{;}
		/* | tok_identifier {;} */
		;

basic_type	: tok_i16		{;}
			| tok_i32		{;}
			| tok_i64		{;}
			| tok_i128		{;}
			| tok_f16		{;}
			| tok_f32		{;}
			| tok_f64		{;}
			| tok_f128		{;}
			;

function_type	:	'(' typed_identifiers ')' tok_arrow typed_identifier


expr	: term				{;}
		| expr '+' term		{;}
		| expr '-' term		{;}
		;

term	: tok_number		{;}
		| tok_identifier	{;}
		;
%%

void yyerror (char *s) {
	fprintf (stderr, "%s\n", s);
}