%{
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring> // strerror
#include <string>
#include "parser_driver.h"
#include "parser.h"
using Token = yy::parser::token;
%}

%option noyywrap nounput noinput batch debug

%{
	// A number symbol corresponding to the value in S.
	yy::parser::symbol_type make_tok_inum(const std::string &s, const yy::parser::location_type& loc);
%}

%{
	// Code run each time a pattern is matched.
	# define YY_USER_ACTION  loc.columns (yyleng);
%}

id    [a-zA-Z][_a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]
comment \/\/.*

%{
	// Code run each time a pattern is matched.
	# define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
	// A handy shortcut to the location held by the driver.
	yy::location& loc = drv.location;
	// Code run each time yylex is called.
	loc.step();
%}

{blank}+		loc.step ();
{comment}		loc.step ();
\n+				loc.lines (yyleng); loc.step ();
"i64"			return yy::parser::make_tok_i64(loc);
"="				return yy::parser::make_tok_eq(loc);
"-"				return yy::parser::make_tok_minus(loc);
"+"				return yy::parser::make_tok_plus(loc);
"("				return yy::parser::make_tok_lparen(loc);
")"				return yy::parser::make_tok_rparen(loc);
"{"				return yy::parser::make_tok_lcurly(loc);
"}"				return yy::parser::make_tok_rcurly(loc);
":"				return yy::parser::make_tok_colon(loc);
";"				return yy::parser::make_tok_semi_colon(loc);
","				return yy::parser::make_tok_coma(loc);
"->"			return yy::parser::make_tok_arrow(loc);
"return"		return yy::parser::make_tok_return(loc);
"if"			return yy::parser::make_tok_if(loc);
"else"			return yy::parser::make_tok_else(loc);
"while"			return yy::parser::make_tok_while(loc);
"for"			return yy::parser::make_tok_for(loc);
"true"			return yy::parser::make_tok_true(loc);
"false"			return yy::parser::make_tok_false(loc);
{id}			return yy::parser::make_tok_identifier(yytext, loc);
[1-9][0-9]*		return make_tok_inum(yytext, loc);
.				{ ECHO; }
<<EOF>>			return yy::parser::make_YYEOF(loc);

%%

yy::parser::symbol_type make_tok_inum(const std::string &s, const yy::parser::location_type& loc) {
	errno = 0;
	long n = strtol (s.c_str(), NULL, 10);
	if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
		std::cerr << loc << "int out of range + s " << ": " << strerror (errno) << '\n';
		// throw yy::parser::syntax_error (loc, "integer is out of range: " + s);

	return yy::parser::make_tok_inum((int) n, loc);
}

void driver::scan_begin () {
	yy_flex_debug = trace_scanning;
	if (file.empty () || file == "-") {
		yyin = stdin;
	} else if (!(yyin = fopen (file.c_str (), "r"))) {
		std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
		exit (EXIT_FAILURE);
	}
}

void driver::scan_end () {
  fclose (yyin);
}

