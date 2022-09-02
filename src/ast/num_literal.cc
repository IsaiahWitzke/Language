#include "num_literal.h"

Value* NumLiteralAST::codegen() {
	// TODO: more types!
	return ConstantInt::get(*TheContext, llvm::APInt(64, num, true));
}