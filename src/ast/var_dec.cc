#include "var_dec.h"
#include "variable.h"
#include "type.h"
#include <cassert>

VarDecAST::VarDecAST(string name, unique_ptr<TypeAST> type) : name(name), type(move(type)) {
	ScopeAST::curScope->addVar(
		make_unique<Variable>(
			name,
			nullptr,	// no llvm value yet, we update that when we codegen
			this->type.get()
			)
	);
}

Value* VarDecAST::codegen() {
	assert(type);
	assert(ScopeAST::curScope->searchVar(name));
	if (isFuncType()) {
		auto& args = getFunctionType()->params;
		auto& returnType = getFunctionType()->returnType;
		// TODO: make generic... right now only int64 works
		vector<Type*> intArgs(args.size(), Type::getInt64Ty(*TheContext));
		FunctionType* funcType = FunctionType::get(
			Type::getInt64Ty(*TheContext),
			intArgs,
			false
		);

		Function* llvmFunc = Function::Create(
			funcType,
			Function::ExternalLinkage,
			name,
			TheModule.get()
		);

		// Set names for all arguments.
		unsigned idx = 0;
		for (auto& arg : llvmFunc->args())
			arg.setName(args[idx++]->name);

		// update the function's value to the named values
		ScopeAST::curScope->searchVar(name)->value = llvmFunc;

		// AllocaInst* allocaInst = Builder->CreateAlloca(funcType, nullptr, name);
		// Builder->CreateStore(llvmFunc, allocaInst, false);

		// return allocaInst;
		return nullptr;
	}
	else {
		if (ScopeAST::curScope->isGlobal) {
			// global vars
			TheModule->getOrInsertGlobal(name, type->toBasicType()->toLlvmType());
			GlobalVariable* gVar = TheModule->getNamedGlobal(name);

			ScopeAST::curScope->searchVar(name)->value = gVar;

			gVar->setAlignment(Align(8));
			return gVar;
		}
		else {
			// scoped variables allocated on the stack
			AllocaInst* allocaInst = Builder->CreateAlloca(type->toBasicType()->toLlvmType(), nullptr, name);
			ScopeAST::curScope->searchVar(name)->value = allocaInst;

			Value* initVal;
			if (isBasicTypeInt(type->toBasicType()->basicType))
				initVal = ConstantInt::get(*TheContext, APInt(
					type->toBasicType()->size,
					0,
					type->toBasicType()->isSigned
				));
			else if (isBasicTypeFloat(type->toBasicType()->basicType))
				initVal = ConstantFP::get(*TheContext, APFloat(0.0));
			else
				cout << "ERROR: could not find initial value for " << name << endl;
			Builder->CreateStore(initVal, allocaInst);
			return allocaInst;
		}
	}
}

bool VarDecAST::isFuncType() {
	if (!type) {	// the type has yet to be determined... maybe bad to return false here, but o well - suck it future me
		return false;
	}
	return type->isFunc;
	// return (bool) dynamic_cast<FunctionTypeAST*>(type.get());
}

FunctionTypeAST* VarDecAST::getFunctionType() {
	return dynamic_cast<FunctionTypeAST*>(type.get());
}

BasicTypeAST* VarDecAST::getBasicType() {
	return dynamic_cast<BasicTypeAST*>(type.get());
}