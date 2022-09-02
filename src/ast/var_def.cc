#include "var_def.h"

Value* VarDefAST::codegen() {
	Value* v = varDec->codegen();
	if (varDec->isFuncType()) {
		Function* llvmFunc = TheModule->getFunction(varDec->name);
		BasicBlock* entryBB = BasicBlock::Create(*TheContext, "entry", llvmFunc);
		Builder->SetInsertPoint(entryBB);
		functionScope->codegen();
	}

	return v;
}