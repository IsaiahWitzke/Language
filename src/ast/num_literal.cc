#include "num_literal.h"
#include "type.h"

Value* NumLiteralAST::codegen() {
	if(isBasicTypeInt(tokenType)) {
		return ConstantInt::get(*TheContext, llvm::APInt(
			computedType->toBasicType()->size,
			iNum,
			computedType->toBasicType()->isSigned
		));
	}

	if(isBasicTypeFloat(tokenType)) {
		return ConstantFP::get(*TheContext, llvm::APFloat(
			fNum
		));
	}
}


TypeAST* NumLiteralAST::computeType() {
	return new BasicTypeAST(tokenType);
}

TypeAST* NumLiteralAST::overrideType(TypeAST* newType) {
	// for example, if we were trying to do something like:
	//		var: i8 = 129 		<--- ERROR!!
	// for a signed i8, the max would be 128, so trying to do this would cause an error
	BasicTypeAST *btFrom = computedType->toBasicType();
	if(!btFrom) {
		LogErrorV("numeric literal not convertible to basic type");	// should never get this
		return nullptr;
	}
	BasicTypeAST *btTo = computedType->toBasicType();
	if(!btTo) {
		LogErrorV("Trying to convert numeric literal into non-basic type");
		return nullptr;
	}

	if(btTo->size < btFrom->size) {
		LogErrorV("Trying to convert numeric literal into smaller type than required!");
		return nullptr;
	}

	computedType = newType;
	return computedType;
}