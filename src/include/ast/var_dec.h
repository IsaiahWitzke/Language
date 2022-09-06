#pragma once
#include "ast.h"

class BasicTypeAST;
class FunctionTypeAST;

class VarDecAST {
public:
	const string name;
	unique_ptr<TypeAST> type;
	// unique_ptr<FunctionDecAST> funcDec;	// variables can "hold functions"
	VarDecAST(
		string name,
		unique_ptr<TypeAST> type
	) : name(name), type(move(type)) {}

	bool isFuncType();
	FunctionTypeAST* getFunctionType();
	BasicTypeAST* getBasicType();

	Value* codegen();
};