#include "func_call.h"

llvm::Value* FuncCallAST::codegen() {
	Function *calleeFunc = static_cast<Function *>(callee->codegen());
}