#include "id_expr.h"

Value* IdExprAST::codegen() {
	Value *v = ScopeAST::curScope->searchVal(id);
	if (!v) {
		LogErrorV("No variable defined: " + id);
		return nullptr;
	}
	
	// return Builder->CreateLoad(Type::getInt64Ty(*TheContext), v, id.c_str());
	return Builder->CreateAlignedLoad(Type::getInt64Ty(*TheContext), v, Align(8), id.c_str());
}