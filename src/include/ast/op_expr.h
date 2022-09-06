#pragma once
#include "ast.h"

class OpExprAST : public ExprAST {
public:
	unique_ptr<ExprAST> lhsExpr;
	char opcode;
	unique_ptr<ExprAST> rhsExpr;
	OpExprAST(
		unique_ptr<ExprAST> lhsExpr,
		char opcode,
		unique_ptr<ExprAST> rhsExpr
	) : lhsExpr(move(lhsExpr)), opcode(opcode), rhsExpr(move(rhsExpr)) {
		cout << "OP EXPR: " << opcode << endl;
	}

	TypeAST *computeType() override;

	Value* codegen() override;
};

