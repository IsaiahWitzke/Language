#include "id_expr.h"
#include <vector>

Value* IdExprAST::codegen() {
	Variable* var = ScopeAST::curScope->searchVar(id);
	if (!var) {
		LogErrorV("No variable defined: " + id);
		return nullptr;
	}

	// return Builder->CreateLoad(Type::getInt64Ty(*TheContext), v, id.c_str());
	if (var->type->isFunc) {
		// TODO: type checking
		Function* calleeFunc = static_cast<Function*>(var->value);

		// load in the args
		vector<Value*> argsV;
		for (unsigned i = 0, e = ((FunctionTypeAST *)var->type)->params.size(); i != e; ++i) {
			// ArgsV.push_back(Args[i]->codegen());
			// if (!ArgsV.back())
				// return nullptr;
		}
		return Builder->CreateCall(calleeFunc, argsV, "calltmp");
	}
	else {
		return Builder->CreateAlignedLoad(Type::getInt64Ty(*TheContext), var->value, Align(8), id.c_str());
	}
}

TypeAST* IdExprAST::computeType() {
	Variable* var = ScopeAST::curScope->searchVar(id);
	if (!var) {
		LogErrorV("No variable defined: " + id);
		return nullptr;
	}
	return var->type;
}