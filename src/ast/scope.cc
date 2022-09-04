#include "scope.h"

void ScopeAST::tryAddVarDecToNamedValues(StmtAST* stmt) {
	// const VarDecAST* varDec;	// will be populated with the varDec info (if it exists in the given stmt)
	// const VarDecStmtAST* varDecStmt = dynamic_cast<const VarDecStmtAST*>(stmt);
	// const VarDefStmtAST* varDefStmt = dynamic_cast<const VarDefStmtAST*>(stmt);
	// if (varDecStmt) {
	// 	// can we do the conversion to a varDec? if so, add it to the scoped namedValues map...
	// 	varDec = varDecStmt->varDec.get();
	// }
	// else if (varDefStmt) {
	// 	// what about a def?
	// 	// make sure it's not already been declared earlier in the scope
	// 	if (search(varDefStmt->varDef->varDec->name)) return;
	// 	else varDec = varDefStmt->varDef->varDec.get();
	// }
	// else {
	// 	// ignore every other type of stmt
	// 	return;
	// }

	// namedValues[varDec->name] = varDec;
}

void ScopeAST::addStmt(unique_ptr<StmtAST> stmt) {
	tryAddVarDecToNamedValues(stmt.get());

	// stmt->scope = this;
	this->stmts.push_back(move(stmt));
}

// const VarDecAST* ScopeAST::search(const string& name) const {
// 	if (namedValues.count(name)) 		return nullptr; // (*namedValues.find(name)).second;
// 	else if (parentScope == nullptr)	return nullptr;
// 	else								return parentScope->search(name);
// }

Value* ScopeAST::searchVal(const string& name) {
	if (namedValues.count(name) > 0) {
		return namedValues.find(name)->second;
	} else if (parentScope == nullptr) {
		return nullptr;
	} else {
		return parentScope->searchVal(name);
	}
}