#pragma once
#include "ast.h"
#include "stmt.h"

class ExprAST;

class ExprStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ExprStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	Value* codegen() override;
};