#pragma once
#include "ast.h"

class VarDecStmtAST : public StmtAST {
public:
	unique_ptr<VarDecAST> varDec;

	VarDecStmtAST(unique_ptr<VarDecAST> varDec) : varDec(move(varDec)) {}

	Value* codegen() override;
	
};