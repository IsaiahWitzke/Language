#pragma once
#include "ast.h"
#include "token.h"

class VarDecAST;
class BasicTypeAST;
class FunctionTypeAST;

class TypeAST {
protected:
	TypeAST(bool isFunc) : isFunc(isFunc) {}
public:
	bool isFunc;
	virtual ~TypeAST() = default;

	virtual BasicTypeAST* toBasicType() = 0;
	virtual FunctionTypeAST* toFunctionType() = 0;
	virtual bool operator==(TypeAST& t) = 0;
};

/// To represent a type like an int, float
/// TODO: bool, char...
class BasicTypeAST : public TypeAST {
public:
	Token basicType;
	unsigned size;
	bool isSigned;
	BasicTypeAST(
		Token t
	) : basicType(t),
		size(basicTypeToSize(t)),
		isSigned(false),	// TODO: unsigned types
		TypeAST(false) { }

	BasicTypeAST *toBasicType() override { return this; }
	FunctionTypeAST *toFunctionType() override { return nullptr; }

	bool operator==(TypeAST& t) override;
};

class FunctionTypeAST : public TypeAST {
public:
	vector<unique_ptr<VarDecAST>> params;
	unique_ptr<TypeAST> returnType;
	FunctionTypeAST(
		vector<unique_ptr<VarDecAST>> params,
		unique_ptr<TypeAST> returnType
	) : params(move(params)), returnType(move(returnType)), TypeAST(true) {}

	BasicTypeAST *toBasicType() override { return nullptr; }
	FunctionTypeAST *toFunctionType() override { return this; }

	bool operator==(TypeAST& t) override;
};