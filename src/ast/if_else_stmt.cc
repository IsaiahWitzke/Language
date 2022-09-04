#include "if_else_stmt.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/BasicBlock.h"

Value* IfElseStmtAST::codegen() {
	Value* condV = cond->codegen();
	// TODO: error checking
	// Convert condition to a bool by comparing non-equal to 0.
	condV = Builder->CreateICmpNE(
		condV,
		ConstantInt::get(*TheContext, APInt(64, 0, true)),
		"ifcond"
	);

	Function* f = Builder->GetInsertBlock()->getParent();

	BasicBlock* thenBB = BasicBlock::Create(*TheContext, "then", f);
	BasicBlock* elseBB = BasicBlock::Create(*TheContext, "else");
	BasicBlock* mergeBB = BasicBlock::Create(*TheContext, "ifcont");

	Builder->CreateCondBr(condV, thenBB, elseBB);

	// build the "then"
	Builder->SetInsertPoint(thenBB);
	// TODO: error checking
	thenScope->codegen();
	Builder->CreateBr(mergeBB);

	// Codegen of 'Then' can change the current block, update ThenBB for the PHI.
	thenBB = Builder->GetInsertBlock();

	// build the "else" block.
	f->getBasicBlockList().push_back(elseBB);
	Builder->SetInsertPoint(elseBB);

	if(elseScope)
		elseScope->codegen();
	// TODO: error checking

	Builder->CreateBr(mergeBB);
	// Codegen of 'else' can change the current block, update ElseBB for the PHI.
	elseBB = Builder->GetInsertBlock();

	// Emit merge block.
	f->getBasicBlockList().push_back(mergeBB);
	Builder->SetInsertPoint(mergeBB);
	// PHINode* PN = Builder->CreatePHI(Type::getDoubleTy(*TheContext), 2, "iftmp");

	// PN->addIncoming(ThenV, ThenBB);
	// PN->addIncoming(ElseV, ElseBB);
	// return PN;
	return nullptr;
}