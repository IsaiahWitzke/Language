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
	vector<unique_ptr<StmtAST>> topLevelStmts;
	string name;
public:
	ModuleAST(string name = "") : name(name) {}

	void codegen();
};

/// ExprAST - Base class for all expression nodes.
class ExprAST {
public:
	virtual ~ExprAST() = default;

	virtual Value* codegen() = 0;
};

/// NumberExprAST - Expression class for numeric literals like "1.0".
class NumberExprAST : public ExprAST {
	double Val;

public:
	NumberExprAST(double Val) : Val(Val) {}

	Value* codegen() override;
};

/// VariableExprAST - Expression class for referencing a variable, like "a".
class VariableExprAST : public ExprAST {
	string name;
	Type::BasicType type;

public:
	VariableExprAST(const string& name, const Type::BasicType type)
		: name(name), type(type) {}

	Value* codegen() override;
	const string& getName() const { return name; }
	const Type::BasicType& getType() const { return type; }
};

/// UnaryExprAST - Expression class for a unary operator.
class UnaryExprAST : public ExprAST {
	char Opcode;
	unique_ptr<ExprAST> Operand;

public:
	UnaryExprAST(char Opcode, unique_ptr<ExprAST> Operand)
		: Opcode(Opcode), Operand(move(Operand)) {}

	Value* codegen() override;
};

/// BinaryExprAST - Expression class for a binary operator.
class BinaryExprAST : public ExprAST {
	char Op;
	unique_ptr<ExprAST> LHS, RHS;

public:
	BinaryExprAST(char Op, unique_ptr<ExprAST> LHS,
		unique_ptr<ExprAST> RHS)
		: Op(Op), LHS(move(LHS)), RHS(move(RHS)) {}

	Value* codegen() override;
};

/// CallExprAST - Expression class for function calls.
class CallExprAST : public ExprAST {
	string Callee;
	vector<unique_ptr<ExprAST>> Args;

public:
	CallExprAST(const string& Callee,
		vector<unique_ptr<ExprAST>> Args)
		: Callee(Callee), Args(move(Args)) {}

	Value* codegen() override;
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

/// VarExprAST - Expression class for variable declaration
class VarExprAST : public ExprAST {
	string name;
	Type::BasicType type;
	unique_ptr<ExprAST> initAst;
	unique_ptr<FunctionAST> funcAst;

public:
	VarExprAST(string name, Type::BasicType type, unique_ptr<ExprAST> init)
		: name(name), type(type), init(move(init)) {}

	VarExprAST(string name, Type::BasicType type, unique_ptr<FunctionAST> func)
		: name(name), type(type), init(move(init)) {}

	Value* codegen() override;
};

/// PrototypeAST - This class represents the "prototype" for a function,
/// which captures its name, and its argument names (thus implicitly the number
/// of arguments the function takes), as well as if it is an operator.
class PrototypeAST {
	string Name;
	vector<string> Args;
	bool IsOperator;
	unsigned Precedence; // Precedence if a binary op.

public:
	PrototypeAST(const string& Name, vector<string> Args,
		bool IsOperator = false, unsigned Prec = 0)
		: Name(Name), Args(move(Args)), IsOperator(IsOperator),
		Precedence(Prec) {}

	Function* codegen();
	const string& getName() const { return Name; }

	bool isUnaryOp() const { return IsOperator && Args.size() == 1; }
	bool isBinaryOp() const { return IsOperator && Args.size() == 2; }

	char getOperatorName() const {
		assert(isUnaryOp() || isBinaryOp());
		return Name[Name.size() - 1];
	}

	unsigned getBinaryPrecedence() const { return Precedence; }
};

/// FunctionAST - This class represents a function definition itself.
class FunctionAST {
	unique_ptr<PrototypeAST> Proto;
	unique_ptr<ExprAST> Body;

public:
	FunctionAST(unique_ptr<PrototypeAST> Proto,
		unique_ptr<ExprAST> Body)
		: Proto(move(Proto)), Body(move(Body)) {}

	Function* codegen();
};
