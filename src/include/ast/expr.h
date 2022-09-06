#pragma once
#include "ast.h"

class TypeAST;

class ExprAST {
private:
public:
	ExprAST() {}
	virtual Value* codegen() = 0;

	virtual TypeAST *computeType() = 0;

	TypeAST *computedType;
};
