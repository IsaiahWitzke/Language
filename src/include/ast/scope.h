#pragma once
#include "ast.h"
#include "variable.h"

class VarDecAST;

/// Every {<sequence of statements>} has a 1:1 relation with its own "scope"
/// The scope holds the variable/function names, and holds pointers to parent
/// scopes so that when codegen'ing we can reference "in-scope" variables/functions
class ScopeAST {
public:
	/// Used while constructing the AST during the parsing stage
	static ScopeAST* curScope;

	vector<unique_ptr<StmtAST>> stmts;
	map<string, unique_ptr<Variable>> namedValues;	// populated as stmts are added to the scope while parsing

	ScopeAST* parentScope;
	const bool isGlobal;


	ScopeAST(
		ScopeAST* parentScope
	) : parentScope(parentScope), isGlobal(parentScope == nullptr) {}

	void addStmt(unique_ptr<StmtAST> stmt);

	// const VarDecAST* search(const string& name) const;
	Variable* searchVar(const string& name);

	void addVar(unique_ptr<Variable> v);

	void codegen();
};