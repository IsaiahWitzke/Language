#include "var_dec.h"

AllocaInst* VarDecAST::codegen() {
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


		// return llvmFunc;
		// TODO: return pointer to where function is stored in memory
		return nullptr;
	}
	else {
		Function* TheFunction = Builder->GetInsertBlock()->getParent();

		// AllocaInst* allocaInst = CreateEntryBlockAlloca(TheFunction, name);

		AllocaInst* allocaInst = Builder->CreateAlloca(Type::getInt64Ty(*TheContext), nullptr, name);

		if(ScopeAST::curScope->namedValues.count(name)) {
			LogErrorV("Already defined in this scope: " + name);
		} else {
			ScopeAST::curScope->namedValues[name] = allocaInst;
		}

		// TODO: change bitsize/type to match type
		Value* initVal = ConstantInt::get(*TheContext, llvm::APInt(64, 0, true));

		Builder->CreateStore(initVal, allocaInst);

		return allocaInst;
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