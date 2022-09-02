#pragma once
#include "ast.h"

class ScopeAST;

class VarDefAST {
public:
	unique_ptr<VarDecAST> varDec;
	unique_ptr<ExprAST> initExpr;
	unique_ptr<ScopeAST> functionScope;
	VarDefAST(
		unique_ptr<VarDecAST> varDec,
		unique_ptr<ExprAST> initExpr,
		unique_ptr<ScopeAST> functionScope
	) : varDec(move(varDec)), initExpr(move(initExpr)), functionScope(move(functionScope)) {}

	Value* codegen();
};