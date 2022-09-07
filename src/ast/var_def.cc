#include "var_def.h"
#include "llvm/IR/Verifier.h"

Value* VarDefAST::codegen() {
	// type inference...
	if (!varDec->type) {
		if(!initExpr) {
			LogErrorV("Cannot infer type of function or variable declaration with no initial value.");
			return nullptr;
		}
		varDec->type = make_unique<BasicTypeAST>(initExpr->computedType->toBasicType()->basicType);
	} else {
		// otherwise, we check to make sure that the expression type is the same as the variable
		// ... FOR BASIC TYPES ONLY!
		if(
			varDec->type->toBasicType() &&
			!(*varDec->type == *initExpr->computedType)) {
			LogErrorV("Non-matching types!");
			return nullptr;
		}
	}
	// codegen the declaration first
	Value* varValue = varDec->codegen();
	if (varDec->isFuncType()) {	// if varDec doesnt have a type, we assume that it cannot be a function (function defs need explicit types)
		// if this is a function, we need to actually make the llvm function object
		Function* llvmFunc = TheModule->getFunction(varDec->name);
		BasicBlock* entryBB = BasicBlock::Create(*TheContext, "entry", llvmFunc);
		Builder->SetInsertPoint(entryBB);
		functionScope->codegen();
		verifyFunction(*llvmFunc, &outs());
		// TODO: figure out pointers to functions
	} else {
		Value *initVal = initExpr->codegen();
		if(ScopeAST::curScope->isGlobal) {
			// global vars... this seems sketchy
			GlobalVariable *gVar = static_cast<GlobalVariable*>(varValue);
			Constant *initValConst = static_cast<Constant *>(initVal);
			// gVar->setInitializer(initValConst);
			gVar->setInitializer(ConstantInt::get(*TheContext, APInt(64, 2, true)));
			return gVar;
		} else {
			// otherwise, we can just store the initVal into the allocaInst
			// AllocaInst *allocaInst = static_cast<AllocaInst*>(initVal);
			// Builder->CreateStore(initVal, allocaInst);
			return Builder->CreateStore(initVal, varValue);
		}
	}

	// return allocaInst;
}