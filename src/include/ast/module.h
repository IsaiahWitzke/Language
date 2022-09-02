#pragma once
#include "ast.h"

class ScopeAST;

/// ModuleAST - The parent AST from which all actual code lives
class ModuleAST {
public:
	string name;
	unique_ptr<ScopeAST> scope;
	ModuleAST(
		string name,
		unique_ptr<ScopeAST> scope
	) : name(name), scope(move(scope)) {}

	void codegen();
};