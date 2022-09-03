#pragma once
#include "ast.h"
#include "stmt.h"

class ExprAST;

class AssignmentStmtAST : public StmtAST {
private:
public:
	string id;
	unique_ptr<ExprAST> expr;
	AssignmentStmtAST(string id, unique_ptr<ExprAST> expr) : id(id), expr(move(expr)) {}

	Value* codegen() override;
};
