#include "expr_stmt.h"

Value* ExprStmtAST::codegen() {
	return expr->codegen();
}