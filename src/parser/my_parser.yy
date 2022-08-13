%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include <memory>

using namespace std;

%}

%require "3.2"
%language "c++"
/* want to just use c++ types instead of the regular yacc %union */
/* See: https://www.gnu.org/software/bison/manual/html_node/A-Simple-C_002b_002b-Example.html */
%define api.value.type variant

/* %union {int num; char *id; unique_ptr<TermAST> t_term;} */
%start module
/* %token tok_eof tok_func tok_extern tok_if tok_then tok_else tok_for tok_in */
%token <string> tok_identifier
%token <int> tok_number
%token <Type::BasicType> tok_i128 tok_i64 tok_i32 tok_i16 tok_f128 tok_f64 tok_f32 tok_f16
%token tok_arrow						/* -> */
%type <unique_ptr<ModuleAST>> 			module
%type <vector<unique_ptr<StmtAST>>> 	stmts
%type <vector<unique_ptr<VarDecAST>>> 	variable_decs
%type <vector<unique_ptr<ExprAST>>> 	arg_list
%type <unique_ptr<StmtAST>> 			stmt
%type <unique_ptr<VarDecAST>> 			variable_dec
%type <unique_ptr<VarDefAST>> 			variable_def
%type <unique_ptr<TermAST>> 			term
%type <unique_ptr<ExprAST>> 			expr
%type <unique_ptr<TypeAST>> 			type
%type <unique_ptr<FunctionTypeAST>> 	function_type
%type <unique_ptr<FunctionCallAST>> 	function_call
%type <Type::BasicType>					basic_type

%%

module	: stmts	{$$ = make_unique<ModuleAST>("test", move($1))}
		;

stmts	: stmt {
			$$ = vector<uniqe_ptr<StmtAST>>(move($1));
		}
		| stmts stmt {
			$1->push_back(move($2));
			$$ = $1
		}
		;

stmt	: expr { $$ = make_unique<StmtAST>(move($1), nullptr, nullptr); }
		| variable_dec ';'	{ $$ = make_unique<StmtAST>(nullptr, move($1), nullptr); }
		| variable_def ';'	{ $$ = make_unique<StmtAST>(nullptr, nullptr, move($1)); }
		;

variable_def	: variable_dec '=' expr ';'	{
					$$ = make_unique<VarDefAST>(move($1), move($3), nullptr);
				}
				/* function definition */
				| variable_dec '=' '{' stmts '}' {
					$$ = make_unique<VarDefAST>(move($1), nullptr, move($4));
				}


variable_dec	: tok_identifier ':' type	{$$ = make_unique<VarDecAST>($1, move($3));}
				;

variable_decs	: variable_dec {
					$$ = make_unique<vector<uniqe_ptr<VarDecAST>>>(move($1));
				}
				| variable_decs ',' variable_dec  {
					$1->push_back(move($3));
					$$ = $3;
				}
				;

type	: basic_type	{ $$ = make_unique<TypeAST>($1, nullptr); }
		| function_type	{ $$ = make_unique<TypeAST>(nullptr, move($1)); }
		/* | tok_identifier {;} */
		;

basic_type : tok_i16 | tok_i32 | tok_i64 | tok_i128 | tok_f16 | tok_f32 | tok_f64 | tok_f128 ;

/* (varName1: type1, varName2: type2, ...) -> returnType */
function_type 	: '(' variable_decs ')' tok_arrow type {
					$$ = make_unique<FunctionTypeAST>(move($2), move($5));
				}
				;

expr 	: term {
			$$ = make_unique<ExprAST>(move($1), nullptr, nullptr, nullptr);
		}
		| expr '+' term {
			$$ = make_unique<ExprAST>(nullptr, move($1), '+', move($3));
		}
		| expr '-' term {
			$$ = make_unique<ExprAST>(nullptr, move($1), '-', move($3));
		}
		| '(' expr ')' { $$ = move($2); }
		;

term	: tok_number		{ $$ = make_unique<TermAST>($1, nullptr, nullptr); }
		| tok_identifier	{ $$ = make_unique<TermAST>(0, $1, nullptr); }
		| function_call		{ $$ = make_unique<TermAST>(0, nullptr, move($1)); }
		;

/* will make sure later on in contextual analysis that typeof(expr) is a func */
function_call	: expr '(' arg_list ')'	{
					$$ = make_unique<FunctionCallAST>(move($1), move($3));
				}

arg_list 	: expr {
				$$ = vector<uniqe_ptr<ExprAST>>(move($1));
			}
			| arg_list ',' expr {
				$1->push_back(move($1));
				$$ = $3;
			}

%%

void yyerror (char *s) {
	fprintf (stderr, "%s\n", s);
}
