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