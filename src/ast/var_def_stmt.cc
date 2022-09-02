#include "var_def_stmt.h"

Value* VarDefStmtAST::codegen() {
	return varDef->codegen();
}