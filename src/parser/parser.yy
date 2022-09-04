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

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "parser_driver.h"
ScopeAST *ScopeAST::curScope;
}

/* %printer { yyo << $$; } <*>; */

/* %token tok_eof tok_func tok_extern tok_if tok_then tok_else tok_for tok_in */
%token <std::string> tok_identifier;
%token <int> tok_inum;
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
  tok_i128 			"i128"
  tok_i64 			"i64"
  tok_i32			"i32"
  tok_i16			"i16"
  tok_f128			"f128"
  tok_f64			"f64"
  tok_f32			"f32"
  tok_f16			"f16"
  tok_return 		"return"
  tok_if			"if"
  tok_else			"else"
  tok_while			"while"
  tok_for			"for"
  tok_true			"true"
  tok_false			"false"
;
%nterm <unique_ptr<ModuleAST>>			module;
%nterm <unique_ptr<ScopeAST>> 			stmts;
%nterm <vector<unique_ptr<VarDecAST>>>	variable_decs;
%nterm <vector<unique_ptr<ExprAST>>>	arg_list;
%nterm <unique_ptr<StmtAST>>			stmt;
%nterm <unique_ptr<VarDecAST>> 			variable_dec;
%nterm <unique_ptr<VarDefAST>>			variable_def;
%nterm <unique_ptr<ExprAST>>			term;
%nterm <unique_ptr<ExprAST>>			expr;
%nterm <unique_ptr<TypeAST>> 			type;
%nterm <unique_ptr<FunctionTypeAST>> 	function_type;
%nterm								 	basic_type;

/* precedences */

/* %left "-" "+" */

%%

%start module;

module	: stmts	{
			$$ = make_unique<ModuleAST>("test", move($1));
			drv.result = move($$);
		}
		;

stmts	: %empty {
			$$ = make_unique<ScopeAST>(ScopeAST::curScope);		// the parent scope for this sequence of stmts is the curScope
			ScopeAST::curScope = $$.get();						// and now the curScope has changed
		}
		| stmts stmt {
			$1->addStmt(move($2));
			$$ = move($1);
		}
		;

stmt	: expr ";" 								{ $$ = make_unique<ExprStmtAST>(move($1)); }
		| variable_dec ";" 						{ $$ = make_unique<VarDecStmtAST>(move($1)); }
		| variable_def 							{ $$ = make_unique<VarDefStmtAST>(move($1)); }
		| tok_identifier "=" expr ";"			{ $$ = make_unique<AssignmentStmtAST>($1, move($3)); }
		| "return" expr ";"						{ $$ = make_unique<ReturnStmtAST>(move($2)); }
		| "if" "(" expr ")" "{" stmts "}"		{ $$ = make_unique<IfElseStmtAST>(move($3), move($6), nullptr); }
		| "if" "(" expr ")" "{" stmts "}"
			"else" "{" stmts "}"				{ $$ = make_unique<IfElseStmtAST>(move($3), move($6), move($10)); }
		;

variable_def	: variable_dec "=" expr ";" {
					$$ = make_unique<VarDefAST>(move($1), move($3), make_unique<ScopeAST>(ScopeAST::curScope->parentScope));
				}
				/* function definition */
				| variable_dec "=" "{" stmts "}" {
					$$ = make_unique<VarDefAST>(move($1), unique_ptr<ExprAST>(nullptr), move($4));
					// the "stmts" part updated the curScope reference, it is time to change it back
					ScopeAST::curScope = ScopeAST::curScope->parentScope;
				}


variable_dec	: tok_identifier ":" type	{$$ = make_unique<VarDecAST>($1, move($3));}
				;

variable_decs	: %empty {
					$$ = vector<unique_ptr<VarDecAST>>();
				}
				| variable_dec {
					$$ = vector<unique_ptr<VarDecAST>>();
					$$.push_back(move($1));
				}
				| variable_decs "," variable_dec  {
					$1.push_back(move($3));
				}
				;

type	: basic_type	{ $$ = make_unique<BasicTypeAST>(yy::parser::token::tok_i64); }
		| function_type	{ $$ = move($1); }
		/* | tok_identifier {;} */
		;

basic_type : tok_i16 | tok_i32 | tok_i64 | tok_i128 | tok_f16 | tok_f32 | tok_f64 | tok_f128 ;

/* (varName1: type1, varName2: type2, ...) -> returnType */
function_type 	: "(" variable_decs ")" "->" type {
					$$ = make_unique<FunctionTypeAST>(move($2), move($5));
				}
				;

expr 	: term 			{ $$ = move($1); }
		| expr "+" term { $$ = make_unique<OpExprAST>(move($1), '+', move($3)); }
		/* | expr "-" term { $$ = make_unique<ExprAST>(nullptr, move($1), '-', move($3)); } */
		;

term	: tok_inum				{ $$ = make_unique<NumLiteralAST>($1); }
		| "(" expr ")" 			{ $$ = move($2); }
		| tok_identifier		{ $$ = make_unique<IdExprAST>($1); }
		| term "(" arg_list ")"	{ $$ = make_unique<FuncCallAST>(move($1), move($3)); }
		;

arg_list 	: %empty {
				$$ = vector<unique_ptr<ExprAST>>();
			}
			| expr {
				$$ = vector<unique_ptr<ExprAST>>();
				$$.push_back(move($1));
			}
			| arg_list "," expr {
				$1.push_back(move($3));
				$$ = move($1);
			}

%%

void yy::parser::error (const location_type& l, const std::string& m) {
	std::cerr << l << ": " << m << '\n';
}

