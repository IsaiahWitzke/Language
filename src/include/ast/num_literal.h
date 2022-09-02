#pragma once
#include "ast.h"

class NumLiteralAST : public ExprAST {
public:
	int num;
	NumLiteralAST(
		int num
	) : num(num) {}

	Value* codegen() override;
};