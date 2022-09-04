#include "var_dec.h"

Value* VarDecAST::codegen() {
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

		// AllocaInst* allocaInst = Builder->CreateAlloca(funcType, nullptr, name);
		// Builder->CreateStore(llvmFunc, allocaInst, false);

		// return allocaInst;
		return nullptr;
	}
	else {
		if (ScopeAST::curScope->isGlobal) {
			// global vars
			TheModule->getOrInsertGlobal(name, Type::getInt64Ty(*TheContext));
			GlobalVariable* gVar = TheModule->getNamedGlobal(name);
			// gVar->setLinkage(GlobalVariable::CommonLinkage);
			ScopeAST::curScope->namedValues[name] = gVar;
			gVar->setAlignment(Align(8));
			return gVar;
		} else {
			// scoped variables allocated on the stack
			Function* TheFunction = Builder->GetInsertBlock()->getParent();
			AllocaInst* allocaInst = Builder->CreateAlloca(Type::getInt64Ty(*TheContext), nullptr, name);

			if (ScopeAST::curScope->namedValues.count(name))
				LogErrorV("Already defined in this scope: " + name);
			else
				ScopeAST::curScope->namedValues[name] = allocaInst;

			// TODO: change bitsize/type to match type
			Value* initVal = ConstantInt::get(*TheContext, llvm::APInt(64, 0, true));
			Builder->CreateStore(initVal, allocaInst);
			return allocaInst;
		}
	}
}

bool VarDecAST::isFuncType() {
	return (bool) dynamic_cast<FunctionTypeAST*>(type.get());
}

FunctionTypeAST* VarDecAST::getFunctionType() {
	return dynamic_cast<FunctionTypeAST*>(type.get());
}

BasicTypeAST* VarDecAST::getBasicType() {
	return dynamic_cast<BasicTypeAST*>(type.get());
}