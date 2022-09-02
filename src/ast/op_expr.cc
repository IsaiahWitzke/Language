#include "op_expr.h"

Value* OpExprAST::codegen() {
	Value* l = lhsExpr->codegen();
	Value* r = rhsExpr->codegen();
	if (!l || !r) return nullptr;

	switch (opcode) {
	case '+':
		return Builder->CreateAdd(l, r, "addtmp");
	case '-':
		return Builder->CreateSub(l, r, "sumtmp");
	case '*':
		return Builder->CreateMul(l, r, "multmp");
			// case '/':
			// 	return Builder.CreateDiv(l, r, "addtmp")
			// TODO: more ops here
	default:
		return LogErrorV("invalid binary operator");
	}
}