// #include "lexer.h"
#include "ast.h"
#include "parser_driver.h"
#include "codegen.h"
// #include "lib.h"

using namespace std;
int main (int argc, char *argv[]) {
	int res = 0;
	driver drv(false, false);
	string outfile = "outfile.out";
	for (int i = 1; i < argc; ++i) {
		if (argv[i] == string("-p")) {
			drv.trace_parsing = true;
		} else if (argv[i] == string("-s")) {
			drv.trace_scanning = true;
		} else if (argv[i] == string("-o")) {
			if (i == argc) {
				cout << "expected output file name after -o option" << endl;
			} else {
				outfile = argv[++i];
			}
		} else if (!drv.parse (argv[i])) {	// actually try to parse the given filename
			cout << drv.result->name << '\n';
		} else {
			res = 1;
		}
	}
	drv.result->codegen();	// try to codegen the IR
	TheModule->print(errs(), nullptr);	// try to print the IR
	outputObjCode(outfile);	// try to output
	return res;
}