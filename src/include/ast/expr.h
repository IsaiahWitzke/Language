#pragma once
#include "ast.h"

class ExprAST {
public:
	ExprAST() {}
	virtual llvm::Value* codegen() = 0;
};
