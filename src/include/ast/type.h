#pragma once
#include "ast.h"

class VarDecAST;
class FunctionTypeAST;

class TypeAST {
public:
	bool isFunc;
	TypeAST(bool isFunc) : isFunc(isFunc) {}
	virtual ~TypeAST() = default;
};

class BasicTypeAST : public TypeAST {
public:
	int basicType;
	BasicTypeAST(int basicType) : basicType(basicType), TypeAST(false) {}
};

class FunctionTypeAST : public TypeAST {
public:
	vector<unique_ptr<VarDecAST>> params;
	unique_ptr<TypeAST> returnType;
	FunctionTypeAST(
		vector<unique_ptr<VarDecAST>> params,
		unique_ptr<TypeAST> returnType
	) : params(move(params)), returnType(move(returnType)), TypeAST(true) {}
};