#pragma once
#include "ast.h"
#include "scope.h"
#include "variable.h"

class BasicTypeAST;
class FunctionTypeAST;

class VarDecAST {
public:
	const string name;
	unique_ptr<TypeAST> type;
	VarDecAST(string name, unique_ptr<TypeAST> type);

	bool isFuncType();
	FunctionTypeAST* getFunctionType();
	BasicTypeAST* getBasicType();

	Value* codegen();
};