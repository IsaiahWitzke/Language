#include "func_call.h"

llvm::Value* FuncCallAST::codegen() {
	Function *calleeFunc = static_cast<Function *>(callee->codegen());
}

TypeAST *FuncCallAST::computeType() {
	
	TypeAST* calleeType = callee->computedType;
	
	if(!calleeType->isFunc) {
		LogErrorV("Function callee term is not a function type!");
		return nullptr;
	}

	FunctionTypeAST *funcCalleeType = dynamic_cast<FunctionTypeAST*>(calleeType);
	return funcCalleeType->returnType.get();
}