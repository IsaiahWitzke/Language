#include "parser_driver.h"
#include "parser.h"

driver::driver (bool traceParsing, bool traceScanning) 
	: trace_parsing (traceParsing), trace_scanning (trace_scanning) {}

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
