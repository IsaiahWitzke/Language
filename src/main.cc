#include "lexer.h"
#include "ast.h"
#include "parser.h"
#include "codegen.h"
#include "lib.h"

using namespace llvm;
using namespace llvm::sys;

//===----------------------------------------------------------------------===//
// Main driver code.
//===----------------------------------------------------------------------===//

int main() {
	setupBinopPrecedence();
	// Prime the first token.
	fprintf(stderr, "ready> ");
	getNextToken();

	InitializeModuleAndPassManager();

	// Run the main "interpreter loop" now.
	MainLoop();

	if (!outputObjCode(std::string("output.o")))
		return 1;

	return 0;
}