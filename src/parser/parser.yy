%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.1"
%header
%language "c++"
%define api.token.raw
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <string>
#include "ast.h"	// our parse tree classes

class driver;
using namespace std;
}

// The parsing context.
%param { driver& drv }


/*
%define parse.trace
%define parse.error detailed
%define parse.lac full
*/

%code {
#include "parser_driver.h"
}

/* %printer { yyo << $$; } <*>; */

/* %token tok_eof tok_func tok_extern tok_if tok_then tok_else tok_for tok_in */
%token <std::string> tok_identifier;
%token <int> tok_number tok_i128 tok_i64 tok_i32 tok_i16 tok_f128 tok_f64 tok_f32 tok_f16 ;
%token
  tok_eq			"="
  tok_minus			"-"
  tok_plus			"+"
  tok_lparen		"("
  tok_rparen		")"
  tok_lcurly		"{"
  tok_rcurly		"}"
  tok_colon			":"
  tok_semi_colon	";"
  tok_coma			","
  tok_arrow			"->"
;
%nterm <unique_ptr<ModuleAST>>			module;
%nterm <vector<unique_ptr<StmtAST>>> 	stmts;
%nterm <vector<unique_ptr<VarDecAST>>>	variable_decs;
%nterm <vector<unique_ptr<ExprAST>>>	arg_list;
%nterm <unique_ptr<StmtAST>>			stmt;
%nterm <unique_ptr<VarDecAST>> 			variable_dec;
%nterm <unique_ptr<VarDefAST>>			variable_def;
%nterm <unique_ptr<TermAST>>			term;
%nterm <unique_ptr<ExprAST>>			expr;
%nterm <unique_ptr<TypeAST>> 			type;
%nterm <unique_ptr<FunctionTypeAST>> 	function_type;
%nterm <unique_ptr<FunctionCallAST>> 	function_call;
%nterm <int>						 	basic_type;

%%

%start module;


module	: stmts	{$$ = make_unique<ModuleAST>("test", move($1));}
		;

stmts	: stmt {
			$$ = vector<unique_ptr<StmtAST>>();
			$$.push_back(move($1));
		}
		| stmts stmt {
			$1.push_back(move($2));
			$$ = move($1);
		}
		;

stmt	: expr { $$ = make_unique<StmtAST>(move($1), nullptr, nullptr); }
		| variable_dec tok_semi_colon	{ $$ = make_unique<StmtAST>(nullptr, move($1), nullptr); }
		| variable_def tok_semi_colon	{ $$ = make_unique<StmtAST>(nullptr, nullptr, move($1)); }
		;

variable_def	: variable_dec "=" expr tok_semi_colon	{
					$$ = make_unique<VarDefAST>(move($1), move($3), vector<unique_ptr<StmtAST>>());
				}
				/* function definition */
				| variable_dec tok_eq tok_lcurly stmts tok_rcurly {
					$$ = make_unique<VarDefAST>(move($1), unique_ptr<ExprAST>(nullptr), move($4));
				}


variable_dec	: tok_identifier tok_colon type	{$$ = make_unique<VarDecAST>($1, move($3));}
				;

variable_decs	: variable_dec {
					$$ = vector<unique_ptr<VarDecAST>>();
					$$.push_back(move($1));
				}
				| variable_decs tok_coma variable_dec  {
					$1.push_back(move($3));
				}
				;

type	: basic_type	{ $$ = make_unique<TypeAST>($1, unique_ptr<FunctionTypeAST>(nullptr)); }
		| function_type	{ $$ = make_unique<TypeAST>(0, move($1)); }
		/* | tok_identifier {;} */
		;

basic_type : tok_i16 | tok_i32 | tok_i64 | tok_i128 | tok_f16 | tok_f32 | tok_f64 | tok_f128 ;

/* (varName1: type1, varName2: type2, ...) -> returnType */
function_type 	: tok_lparen variable_decs tok_rparen tok_arrow type {
					$$ = make_unique<FunctionTypeAST>(move($2), move($5));
				}
				;

expr 	: term {
			$$ = make_unique<ExprAST>(move($1), nullptr, 0, nullptr);
		}
		| expr tok_plus term {
			$$ = make_unique<ExprAST>(nullptr, move($1), '+', move($3));
		}
		| expr tok_minus term {
			$$ = make_unique<ExprAST>(nullptr, move($1), '-', move($3));
		}
		| tok_lparen expr tok_rparen { $$ = move($2); }
		;

term	: tok_number		{ $$ = make_unique<TermAST>($1, nullptr, unique_ptr<FunctionCallAST>(nullptr)); }
		| tok_identifier	{ $$ = make_unique<TermAST>(0, $1, unique_ptr<FunctionCallAST>(nullptr)); }
		| function_call		{ $$ = make_unique<TermAST>(0, nullptr, move($1)); }
		;

/* will make sure later on in contextual analysis that typeof(expr) is a func */
function_call	: expr tok_lparen arg_list tok_rparen	{
					$$ = make_unique<FunctionCallAST>(move($1), move($3));
				}

arg_list 	: expr {
				$$ = vector<unique_ptr<ExprAST>>();
				$$.push_back(move($1));
			}
			| arg_list tok_coma expr {
				$1.push_back(move($3));
				$$ = move($1);
			}

%%

void yy::parser::error (const std::string& m) {
	std::cerr << m << '\n';
}