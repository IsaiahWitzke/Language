#include "assignment_stmt.h"

Value* AssignmentStmtAST::codegen() {
	AllocaInst* var = ScopeAST::curScope->searchVal(id);
	Value* newVal = expr->codegen();

	// testing
	cout << var << " " << newVal << endl;
	// Value* initVal = ConstantInt::get(*TheContext, llvm::APInt(64, 5, true));
	// AllocaInst* allocaInst = Builder->CreateAlloca(Type::getInt64Ty(*TheContext), nullptr, "TESTVAR");

	Builder->CreateStore(newVal, var);
	cout << "umm" << endl;
	return nullptr;
}
