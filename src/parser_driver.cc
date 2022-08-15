#include "parser_driver.h"
#include "parser.h"

driver::driver () : trace_parsing (true), trace_scanning (true) {
	variables["one"] = 1;
	variables["two"] = 2;
}

int driver::parse (const std::string &f) {
	file = f;
	location.initialize (&file);
	scan_begin();
	yy::parser parse(*this);
	parse.set_debug_level(trace_parsing);
	int res = parse();
	scan_end();
	return res;
}
