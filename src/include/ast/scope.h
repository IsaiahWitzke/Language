#pragma once
#include "ast.h"

class VarDecAST;

/// Every {<sequence of statements>} has a 1:1 relation with its own "scope"
/// The scope holds the variable/function names, and holds pointers to parent
/// scopes so that when codegen'ing we can reference "in-scope" variables/functions
class ScopeAST {
private:
	void tryAddVarDecToNamedValues(StmtAST* stmt);

public:
	/// Used while constructing the AST during the parsing stage
	static ScopeAST* curScope;

	vector<unique_ptr<StmtAST>> stmts;
	map<string, Value*> namedValues;	// populated as stmts are added to the scope while parsing

	ScopeAST* parentScope;
	const bool isGlobal;


	ScopeAST(
		ScopeAST* parentScope
	) : parentScope(parentScope), isGlobal(parentScope == nullptr) {}

	void addStmt(unique_ptr<StmtAST> stmt);

	// const VarDecAST* search(const string& name) const;
	Value* searchVal(const string& name);

	void codegen() {
		ScopeAST* oldScope = curScope;
		curScope = this;
		for (auto& s : stmts) {
			s->codegen();
		}
		curScope = oldScope;
	}
};