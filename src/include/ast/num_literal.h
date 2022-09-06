#pragma once
#include "ast.h"
#include "token.h"
#include "type.h"

class NumLiteralAST : public ExprAST {
public:
	int iNum;
	float fNum;
	Token tokenType;

	NumLiteralAST(
		int num
	) : iNum(num) { 
		// TODO: if num is > something, up the type
		this->tokenType = Token::tok_i64;
		this->computedType = computeType();
	}

	NumLiteralAST(
		float num
	) : fNum(num) { 
		// TODO: if num is > something, up the type
		this->tokenType = Token::tok_f64;
		this->computedType = computeType();
	}

	~NumLiteralAST() {
		delete this->computedType;
	}

	Value* codegen() override;

	TypeAST* computeType() override;

	TypeAST* overrideType(TypeAST* newType);
};