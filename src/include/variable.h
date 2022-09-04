#pragma once

#include "ast.h"

using namespace llvm;

class TypeAST;

class Variable {
public:
	string name;
	Value *value;
	TypeAST *type;

	Variable(string n, Value* v, TypeAST* t) : name(n), value(v), type(t) {}
};