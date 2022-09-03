#include "var_def.h"

Value* VarDefAST::codegen() {
	AllocaInst* allocaInst = varDec->codegen();
	if (varDec->isFuncType()) {
		Function* llvmFunc = TheModule->getFunction(varDec->name);
		BasicBlock* entryBB = BasicBlock::Create(*TheContext, "entry", llvmFunc);
		Builder->SetInsertPoint(entryBB);
		functionScope->codegen();
	} else {
		Value *initVal = initExpr->codegen();
		Builder->CreateStore(initVal, allocaInst);
	}

	return allocaInst;
}