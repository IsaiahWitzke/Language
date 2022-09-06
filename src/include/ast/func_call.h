#pragma once
#include "ast.h"

class FuncCallAST : public ExprAST {
public:
	unique_ptr<ExprAST> callee;
	vector<unique_ptr<ExprAST>> args;
	FuncCallAST(
		unique_ptr<ExprAST> callee,
		vector<unique_ptr<ExprAST>> args
	) : callee(move(callee)), args(move(args)) {
		this->computedType = computeType();
	}

	Value* codegen() override;

	TypeAST* computeType() override;
};