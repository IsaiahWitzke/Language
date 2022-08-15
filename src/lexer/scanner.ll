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

/* %option outfile="src/lexer/scanner.cc" */

%%
i64							{ cout << "HI\n"; return Token::tok_i64; }
[a-zA-Z][_a-zA-Z0-9]*		return yy::parser::make_tok_identifier(yytext);
[1-9][0-9]*					return yy::parser::make_tok_inum(atoi(yytext));
[ \t\r\n]					;
.							{ECHO;}

%%

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

