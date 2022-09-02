#pragma once
#include "ast.h"

class IdExprAST : public ExprAST {
public:
	string id;
	IdExprAST(
		string id
	) : id(id) {}

	Value* codegen() override;
};