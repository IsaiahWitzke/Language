#pragma once
#include "ast.h"

class StmtAST {
public:
	StmtAST() {}

	virtual llvm::Value* codegen() = 0;
};