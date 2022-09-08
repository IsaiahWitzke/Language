#include "scope.h"

void ScopeAST::addStmt(unique_ptr<StmtAST> stmt) {
	// stmt->scope = this;
	this->stmts.push_back(move(stmt));
}

// const VarDecAST* ScopeAST::search(const string& name) const {
// 	if (namedValues.count(name)) 		return nullptr; // (*namedValues.find(name)).second;
// 	else if (parentScope == nullptr)	return nullptr;
// 	else								return parentScope->search(name);
// }

Variable* ScopeAST::searchVar(const string& name) {
	if (namedValues.count(name) > 0) {
		return namedValues.find(name)->second.get();
	} else if (parentScope == nullptr) {
		return nullptr;
	} else {
		return parentScope->searchVar(name);
	}
}

void ScopeAST::addVar(unique_ptr<Variable> v) {
	if (curScope->namedValues.count(v->name))
		LogErrorV("Already defined in this scope: " + v->name);
	else
		curScope->namedValues[v->name] = move(v);
}

void ScopeAST::codegen() {
	ScopeAST* oldScope = curScope;
	curScope = this;
	for (auto& s : stmts) {
		s->codegen();
	}
	curScope = oldScope;
}
