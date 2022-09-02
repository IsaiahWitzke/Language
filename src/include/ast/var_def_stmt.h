#pragma once
#include "ast.h"

class VarDefAST;

class VarDefStmtAST : public StmtAST {
public:
	unique_ptr<VarDefAST> varDef;
	VarDefStmtAST(
		unique_ptr<VarDefAST> varDef
	) : varDef(move(varDef)) {}

	Value* codegen() override;
};
