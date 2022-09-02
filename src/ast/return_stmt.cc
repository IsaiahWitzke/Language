#include "return_stmt.h"
#include "llvm/IR/Verifier.h"

Value* ReturnStmtAST::codegen() {
	Value* retVal = expr->codegen();
	Builder->CreateRet(retVal);
	verifyFunction(*Builder->GetInsertBlock()->getParent());
	return retVal;	// ??
}