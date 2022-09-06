#include "ast.h"
#include "var_dec.h"

bool BasicTypeAST::operator==(TypeAST& t) {
	BasicTypeAST* bt = t.toBasicType();
	if (!bt) return false;
	return (
		basicType == bt->basicType &&
		size == bt->size &&
		isSigned == bt->isSigned
		);
}

bool FunctionTypeAST::operator==(TypeAST& t) {
	FunctionTypeAST* ft = t.toFunctionType();
	if (!ft) return false;

	if (ft->params.size() != params.size()) return false;

	for (int i = 0; i < params.size(); i++) {
		if (!(*ft->params[i]->type == *params[i]->type)) {
			return false;
		}
	}

	return returnType == ft->returnType;
}