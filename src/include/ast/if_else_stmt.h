#pragma once

#include "ast.h"

class ScopeAST;

class IfElseStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> cond;
	unique_ptr<ScopeAST> thenScope;
	unique_ptr<ScopeAST> elseScope;

	IfElseStmtAST(
		unique_ptr<ExprAST> cond,
		unique_ptr<ScopeAST> thenScope,
		unique_ptr<ScopeAST> elseScope
	) : cond(move(cond)), thenScope(move(thenScope)), elseScope(move(elseScope)) {}

	Value* codegen() override;
};
