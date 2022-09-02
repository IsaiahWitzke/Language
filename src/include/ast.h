#pragma once

#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "codegen.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"

//===----------------------------------------------------------------------===//
// Abstract Syntax Tree (aka Parse Tree)
//===----------------------------------------------------------------------===//

using namespace std;
using namespace llvm;

class ScopeAST;
class StmtAST;
class ExprStmtAST;
class VarDecStmtAST;
class VarDefStmtAST;
class ReturnStmtAST;
class ExprAST;
class VarDecAST;
class VarDefAST;
class TypeAST;
class FunctionTypeAST;
class BasicTypeAST;

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

class StmtAST {
public:
	StmtAST() {}

	ScopeAST* scope;

	virtual llvm::Value* codegen() { return nullptr; };
};

class ExprStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ExprStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	llvm::Value* codegen() override { return nullptr; };
};


class VarDecStmtAST : public StmtAST {
public:
	unique_ptr<VarDecAST> varDec;

	VarDecStmtAST(
		unique_ptr<VarDecAST> varDec
	) : varDec(move(varDec)) {}

	Value* codegen() override;
};

class VarDefStmtAST : public StmtAST {
public:
	unique_ptr<VarDefAST> varDef;
	VarDefStmtAST(
		unique_ptr<VarDefAST> varDef
	) : varDef(move(varDef)) {}

	Value* codegen() override;
};

class ReturnStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ReturnStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	llvm::Value* codegen() override;
};

class VarDecAST {
public:
	string name;
	unique_ptr<TypeAST> type;
	// unique_ptr<FunctionDecAST> funcDec;	// variables can "hold functions"
	VarDecAST(
		string name,
		unique_ptr<TypeAST> type
	) : name(name), type(move(type)) {}
	bool isFuncType();
	FunctionTypeAST* getFunctionType();
	BasicTypeAST* getBasicType();
	Value* codegen();
};

class VarDefAST {
public:
	unique_ptr<VarDecAST> varDec;
	unique_ptr<ExprAST> initExpr;
	unique_ptr<ScopeAST> functionScope;
	VarDefAST(
		unique_ptr<VarDecAST> varDec,
		unique_ptr<ExprAST> initExpr,
		unique_ptr<ScopeAST> functionScope
	) : varDec(move(varDec)), initExpr(move(initExpr)), functionScope(move(functionScope)) {}

	Value* codegen();
};

class TypeAST {
public:
	TypeAST() {}
	virtual ~TypeAST() = default;
};

class BasicTypeAST : public TypeAST {
public:
	int basicType;
	BasicTypeAST(int basicType) : basicType(basicType) {}
};

class FunctionTypeAST : public TypeAST {
public:
	vector<unique_ptr<VarDecAST>> params;
	unique_ptr<TypeAST> returnType;
	FunctionTypeAST(
		vector<unique_ptr<VarDecAST>> params,
		unique_ptr<TypeAST> returnType
	) : params(move(params)), returnType(move(returnType)) {}
};

class ExprAST {
public:
	ExprAST() {}
	virtual llvm::Value* codegen() = 0;
};

class OpExprAST : public ExprAST {
public:
	unique_ptr<ExprAST> lhsExpr;
	char opcode;
	unique_ptr<ExprAST> rhsExpr;
	OpExprAST(
		unique_ptr<ExprAST> lhsExpr,
		char opcode,
		unique_ptr<ExprAST> rhsExpr
	) : lhsExpr(move(lhsExpr)), opcode(opcode), rhsExpr(move(rhsExpr)) {
		cout << "OP EXPR: " << opcode << endl;
	}

	Value* codegen() override;
};

class NumLiteralAST : public ExprAST {
public:
	int num;
	NumLiteralAST(
		int num
	) : num(num) {}

	Value* codegen() override;
};


class IdExprAST : public ExprAST {
public:
	string id;
	IdExprAST(
		string id
	) : id(id) {}

	Value* codegen() override;
};

class FuncCallAST : public ExprAST {
public:
	unique_ptr<ExprAST> callee;
	vector<unique_ptr<ExprAST>> args;
	FuncCallAST(
		unique_ptr<ExprAST> callee,
		vector<unique_ptr<ExprAST>> args
	) : callee(move(callee)), args(move(args)) {}

	llvm::Value* codegen() override {
		return nullptr;
	}
};


/// Every {<sequence of statements>} has a 1:1 relation with its own "scope"
/// The scope holds the variable/function names, and holds pointers to parent
/// scopes so that when codegen'ing we can reference "in-scope" variables/functions
class ScopeAST {
private:
	void tryAddVarDecToNamedValues(StmtAST* stmt);

public:
	/// Used while constructing the AST during the parsing stage
	static const ScopeAST* curScope;

	vector<unique_ptr<StmtAST>> stmts;
	std::map<std::string, const AllocaInst*> namedValues;	// populated as stmts are added to the scope while parsing

	const ScopeAST* parentScope;
	const bool isGlobal;


	ScopeAST(
		const ScopeAST* parentScope
	) : parentScope(parentScope), isGlobal(parentScope != nullptr) {}

	void addStmt(unique_ptr<StmtAST> stmt);

	const VarDecAST* search(const string& name) const;

	void codegen() {
		for (auto& s : stmts) {
			s->codegen();
		}
	}
};
