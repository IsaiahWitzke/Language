#pragma once
#include "ast.h"
#include "stmt.h"

class ReturnStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ReturnStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	llvm::Value* codegen() override;
};