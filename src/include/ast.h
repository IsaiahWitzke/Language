#pragma once

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "llvm/IR/Value.h"

//===----------------------------------------------------------------------===//
// Abstract Syntax Tree (aka Parse Tree)
//===----------------------------------------------------------------------===//

using namespace std;

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
class TermAST;



/// ModuleAST - The parent AST from which all actual code lives
class ModuleAST {
public:
	string name;
	unique_ptr<ScopeAST> scope;
	ModuleAST(
		string name,
		unique_ptr<ScopeAST> scope
	) : name(name), scope(move(scope)) {}
};

class StmtAST {
public:
	StmtAST() {}
	
	virtual llvm::Value *codegen() { return nullptr; };
};

class ExprStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ExprStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	llvm::Value *codegen() override { return nullptr; };
};


class VarDecStmtAST : public StmtAST {
public:
	unique_ptr<VarDecAST> varDec;

	VarDecStmtAST(
		unique_ptr<VarDecAST> varDec
	) : varDec(move(varDec)) {}

	llvm::Value *codegen() override { return nullptr; }
};

class VarDefStmtAST : public StmtAST {
public:
	unique_ptr<VarDefAST> varDef;
	VarDefStmtAST(
		unique_ptr<VarDefAST> varDef
	) : varDef(move(varDef)) {}

	llvm::Value *codegen() override { return nullptr; }
};

class ReturnStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ReturnStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	llvm::Value *codegen() override { return nullptr; }
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
};

class TypeAST {
	// can be just a "normal" type
	int basicType;
	// or we can store the type of a function
	unique_ptr<FunctionTypeAST> functionType;
public:
	TypeAST(
		int basicType,
		unique_ptr<FunctionTypeAST> functionType
	) : basicType(basicType), functionType(move(functionType)) {}
};

class FunctionTypeAST {
	vector<unique_ptr<VarDecAST>> params;
	unique_ptr<TypeAST> returnType;
public:
	FunctionTypeAST(
		vector<unique_ptr<VarDecAST>> params,
		unique_ptr<TypeAST> returnType
	) : params(move(params)), returnType(move(returnType)) {}
};

class ExprAST {
public:
	ExprAST() {}
	virtual llvm::Value *codegen() = 0;
};

class OpExprAST : public ExprAST {
public:
	unique_ptr<ExprAST> lhsExpr;
	char opcode;
	unique_ptr<TermAST> rhsTerm;
	OpExprAST(
		unique_ptr<ExprAST> lhsExpr,
		char opcode,
		unique_ptr<TermAST> rhsTerm
	) : lhsExpr(move(lhsExpr)), opcode(opcode), rhsTerm(move(rhsTerm)) {}

	llvm::Value *codegen() override;
};

class TermExprAST : public ExprAST {
public:
	unique_ptr<TermAST> term;
	TermExprAST(
		unique_ptr<TermAST> term
	) : term(move(term)) {}

	llvm::Value *codegen() override;
};

class TermAST {
public:
	TermAST() {}
	virtual llvm::Value *codegen() { return nullptr; };
};

class NumLiteralTermAST : public TermAST {
public:
	int num;
	NumLiteralTermAST(
		int num
	) : num(num) {}
	llvm::Value *codegen() override;
};

class ParenExprTermAST : public TermAST {
public:
	unique_ptr<ExprAST> expr;
	ParenExprTermAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}
	llvm::Value *codegen() override;
};

class IdTermAST : public TermAST {
public:
	string id;
	IdTermAST(
		string id
	) : id(id) {}
	llvm::Value *codegen() override;
};

class FuncCallTermAST : public TermAST {
public:
	unique_ptr<TermAST> callee;
	vector<unique_ptr<ExprAST>> args;
	FuncCallTermAST(
		unique_ptr<TermAST> callee,
		vector<unique_ptr<ExprAST>> args
	) : callee(move(callee)), args(move(args)) {}
};


/// Every {<sequence of statements>} has a 1:1 relation with its own "scope"
/// The scope holds the variable/function names, and holds pointers to parent
/// scopes so that when codegen'ing we can reference "in-scope" variables/functions
class ScopeAST {
public:
	/// Used while constructing the AST
	static const ScopeAST *curScope;

	vector<unique_ptr<StmtAST>> stmts;
	std::map<std::string, const VarDecAST*> namedValues;	// populated as stmts are added to the scope
	const ScopeAST *parentScope;
	ScopeAST(
		const ScopeAST *parentScope
	) : parentScope(parentScope) {}

	void addStmt(unique_ptr<StmtAST> stmt);

	const VarDecAST *search(const string &name) const;

	llvm::Value *codegen() { return nullptr; };
};