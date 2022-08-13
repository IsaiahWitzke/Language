#pragma once

#include <memory>
#include <string>
#include <vector>

//===----------------------------------------------------------------------===//
// Abstract Syntax Tree (aka Parse Tree)
//===----------------------------------------------------------------------===//

using namespace std;

/// ModuleAST - The parent AST from which all actual code lives
class ModuleAST {
private:
	string name;
	vector<unique_ptr<StmtAST>> topLevelStmts;
public:
	ModuleAST(
		string name,
		vector<unique_ptr<StmtAST>> topLevelStmts
	) : name(name), topLevelStmts(move(topLevelStmts)) {}
};

class StmtAST {
	unique_ptr<ExprAST> expr;
	unique_ptr<VarDecAST> varDec;
	unique_ptr<VarDefAST> varDef;
public:
	StmtAST(
		unique_ptr<ExprAST> e,
		unique_ptr<VarDecAST> varDec,
		unique_ptr<VarDefAST> varDef
	) : expr(move(e)), varDec(move(varDec)), varDef(move(varDef)) {}
};

class VarDecAST {
	string name;
	unique_ptr<TypeAST> type;
	// unique_ptr<FunctionDecAST> funcDec;	// variables can "hold functions"
public:
	VarDecAST(
		string name,
		unique_ptr<TypeAST> type
	) : name(name), type(type), init(move(init)) {}
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
}

class TypeAST {
	// can be just a "normal" type
	Type::BasicType basicType;
	// or we can store the type of a function
	unique_ptr<FunctionTypeAst> functionType;
public:
	TypeAST(
		Type::BasicType basicType,
		unique_ptr<FunctionTypeAst> functionType
	) : basicType(basicType), functionType(move(functionType)) {}
}

class FunctionTypeAst {
	vector<unique_ptr<VarDecAST>> params;
	unique_ptr<TypeAST> returnType;
public:
	FunctionTypeAst(
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
	unique_ptr<ExprAST> callee;
	vector<unique_ptr<ExprAST>> args;

public:
	CallExprAST(
		unique_ptr<ExprAST> callee,
		vector<unique_ptr<ExprAST>> args
	) : callee(move(Callee)), args(move(Args)) {}
};

class TermAST {
	int num;
	string id;
	unique_ptr<FunctionCallAST> funcCall;
public:
	TermAST(
		int num,
		char *id,
		unique_ptr<FunctionCallAST> funcCall
	) : num(num), id(id), funcCall(move(funcCall)) {}
};


/// IfExprAST - Expression class for if/then/else.
class IfExprAST : public ExprAST {
	unique_ptr<ExprAST> Cond, Then, Else;

public:
	IfExprAST(unique_ptr<ExprAST> Cond, unique_ptr<ExprAST> Then,
		unique_ptr<ExprAST> Else)
		: Cond(move(Cond)), Then(move(Then)), Else(move(Else)) {}

	Value* codegen() override;
};

/// ForExprAST - Expression class for for/in.
class ForExprAST : public ExprAST {
	string VarName;
	unique_ptr<ExprAST> Start, End, Step, Body;

public:
	ForExprAST(const string& VarName, unique_ptr<ExprAST> Start,
		unique_ptr<ExprAST> End, unique_ptr<ExprAST> Step,
		unique_ptr<ExprAST> Body)
		: VarName(VarName), Start(move(Start)), End(move(End)),
		Step(move(Step)), Body(move(Body)) {}

	Value* codegen() override;
};

/// VarExprAST - Expression class for variable references
class VarExprAST {
	string name;
	Type::BasicType type;
	unique_ptr<ExprAST> init;
	unique_ptr<FunctionAST> func;	// variables can "hold functions"

public:
	VarExprAST(string name, Type::BasicType type, unique_ptr<ExprAST> init)
		: name(name), type(type), init(move(init), func(move(func))) {}
};
