#include "var_dec_stmt.h"

Value* VarDecStmtAST::codegen() {
	Value* v = varDec->codegen();
	// scope->namedValues[varDec->name] = v;
	return v;
}