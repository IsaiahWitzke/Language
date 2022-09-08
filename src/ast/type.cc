#include "ast.h"
#include "var_dec.h"

bool BasicTypeAST::operator==(TypeAST& t) {
	// if(!t) return false;
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
Type* BasicTypeAST::toLlvmType() {
	if (isBasicTypeFloat(basicType)) {
		switch (size) {
		case 16:
			return Type::getHalfTy(*TheContext);
		case 32:
			return Type::getFloatTy(*TheContext);
		case 64:
			return Type::getDoubleTy(*TheContext);
		case 128:
			return Type::getFP128Ty(*TheContext);
		default:
			cout << "bad float size in toLlvmType()" << endl;
			return nullptr;
		}
	} else if (isBasicTypeInt(basicType)) {
		return Type::getIntNTy(*TheContext, size);
	} else {
		cout << "ERROR: bad basic type in toLlvmType" << endl;
		return nullptr;
	}
}