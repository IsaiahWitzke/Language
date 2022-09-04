#include "assignment_stmt.h"

Value* AssignmentStmtAST::codegen() {
	AllocaInst* var = static_cast<AllocaInst*>(ScopeAST::curScope->searchVar(id)->value);
	Value* newVal = expr->codegen();

	// Value* initVal = ConstantInt::get(*TheContext, llvm::APInt(64, 5, true));
	// AllocaInst* allocaInst = Builder->CreateAlloca(Type::getInt64Ty(*TheContext), nullptr, "TESTVAR");

	Builder->CreateStore(newVal, var);
	return nullptr;
}
