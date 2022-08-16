#pragma once

#include <memory>
#include <string>
#include <vector>

//===----------------------------------------------------------------------===//
// Abstract Syntax Tree (aka Parse Tree)
//===----------------------------------------------------------------------===//

using namespace std;

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


class BaseAST {
public:

	virtual void codegen();

};

/// ModuleAST - The parent AST from which all actual code lives
class ModuleAST {
public:
	string name;
	vector<unique_ptr<StmtAST>> topLevelStmts;
	ModuleAST(
		string name,
		vector<unique_ptr<StmtAST>> topLevelStmts
	) : name(name), topLevelStmts(move(topLevelStmts)) {}
};

class StmtAST {
public:
	StmtAST() {}
	
	virtual void codegen() {};
};

class ExprStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ExprStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	void codegen() override {};
};


class VarDecStmtAST : public StmtAST {
public:
	unique_ptr<VarDecAST> varDec;

	VarDecStmtAST(
		unique_ptr<VarDecAST> varDec
	) : varDec(move(varDec)) {}

	void codegen() override {};
};

class VarDefStmtAST : public StmtAST {
public:
	unique_ptr<VarDefAST> varDef;
	VarDefStmtAST(
		unique_ptr<VarDefAST> varDef
	) : varDef(move(varDef)) {}

	void codegen() override {};
};

class ReturnStmtAST : public StmtAST {
public:
	unique_ptr<ExprAST> expr;
	ReturnStmtAST(
		unique_ptr<ExprAST> expr
	) : expr(move(expr)) {}

	void codegen() override {};
};

class VarDecAST {
	string name;
	unique_ptr<TypeAST> type;
	// unique_ptr<FunctionDecAST> funcDec;	// variables can "hold functions"
public:
	VarDecAST(
		string name,
		unique_ptr<TypeAST> type
	) : name(name), type(move(type)) {}
};

class VarDefAST {
	unique_ptr<VarDecAST> varDec;
	unique_ptr<ExprAST> initExpr;
	vector<unique_ptr<StmtAST>> initFuncStmts;
public:
	VarDefAST(
		unique_ptr<VarDecAST> varDec,
		unique_ptr<ExprAST> initExpr,
		vector<unique_ptr<StmtAST>> initFuncStmts
	) : varDec(move(varDec)), initExpr(move(initExpr)), initFuncStmts(move(initFuncStmts)) {}
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
	unique_ptr<TermAST> term;
	unique_ptr<ExprAST> lhsExpr;
	char opcode;
	unique_ptr<TermAST> rhsTerm;
public:
	ExprAST(
		unique_ptr<TermAST> term,
		unique_ptr<ExprAST> lhsExpr,
		char opcode,
		unique_ptr<TermAST> rhsTerm
	) : term(move(term)), lhsExpr(move(lhsExpr)), opcode(opcode), rhsTerm(move(rhsTerm)) {}

};

/// Expression class for function calls.
class FunctionCallAST {
	unique_ptr<TermAST> callee;
	vector<unique_ptr<ExprAST>> args;

public:
	FunctionCallAST(
		unique_ptr<TermAST> callee,
		vector<unique_ptr<ExprAST>> args
	) : callee(move(callee)), args(move(args)) {}
};

class TermAST {
	int num;
	string id;
	unique_ptr<FunctionCallAST> funcCall;
	unique_ptr<ExprAST> expr;

public:
	TermAST(
		int num,
		string id,
		unique_ptr<FunctionCallAST> funcCall,
		unique_ptr<ExprAST> expr
	) : num(num), id(id), funcCall(move(funcCall)), expr(move(expr)) {}
};
