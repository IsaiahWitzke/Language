#include "var_def.h"

Value* VarDefAST::codegen() {
	// codegen the declaration first
	Value* varValue = varDec->codegen();
	if (varDec->isFuncType()) {
		// if this is a function, we need to actually make the llvm function object
		Function* llvmFunc = TheModule->getFunction(varDec->name);
		BasicBlock* entryBB = BasicBlock::Create(*TheContext, "entry", llvmFunc);
		Builder->SetInsertPoint(entryBB);
		functionScope->codegen();
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