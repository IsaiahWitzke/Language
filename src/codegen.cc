#include <string>
#include "ast.h"
#include "codegen.h"
#include "parser.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/ADT/APInt.h"

//===----------------------------------------------------------------------===//
// Code Generation... the ast nodes' codegen functions are here
//===----------------------------------------------------------------------===//

using namespace llvm;
using namespace std;

unique_ptr<LLVMContext> TheContext;
unique_ptr<IRBuilder<>> Builder;
unique_ptr<Module> TheModule;
map<string, AllocaInst*> NamedValues;
// map<string, VarDecAST*> FunctionProtos;
ExitOnError ExitOnErr;

void InitializeModuleAndPassManager(const string& moduleName) {
	// Open a new module.
	TheContext = make_unique<LLVMContext>();

	// Create a new builder for the module.
	Builder = make_unique<IRBuilder<>>(*TheContext);

	TheModule = make_unique<Module>(moduleName, *TheContext);
}

bool outputObjCode(const string& fName) {

	// Initialize the target registry etc.
	InitializeAllTargetInfos();
	InitializeAllTargets();
	InitializeAllTargetMCs();
	InitializeAllAsmParsers();
	InitializeAllAsmPrinters();

	string TargetTriple = sys::getDefaultTargetTriple();
	TheModule->setTargetTriple(TargetTriple);

	string Error;
	auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

	// Print an error and exit if we couldn't find the requested target.
	// This generally occurs if we've forgotten to initialise the
	// TargetRegistry or we have a bogus target triple.
	if (!Target) {
		errs() << Error;
		return false;
	}

	auto CPU = "generic";
	auto Features = "";

	TargetOptions opt;
	auto RM = Optional<Reloc::Model>();
	auto TheTargetMachine =
		Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

	TheModule->setDataLayout(TheTargetMachine->createDataLayout());

	error_code EC;
	raw_fd_ostream dest(fName, EC, sys::fs::OF_None);

	if (EC) {
		errs() << "Could not open file: " << EC.message();
		return false;
	}

	legacy::PassManager pass;
	auto FileType = CGFT_ObjectFile;

	if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
		errs() << "TheTargetMachine can't emit a file of this type";
		return false;
	}

	pass.run(*TheModule);
	dest.flush();

	outs() << "Wrote " << fName << "\n";
	return true;
}

Value* LogErrorV(const char* Str) {
	LogErrorV(Str);
	return nullptr;
}

/*
Function* getFunction(string Name) {
	// First, see if the function has already been added to the current module.
	if (auto* F = TheModule->getFunction(Name))
		return F;

	// If not, check whether we can codegen the declaration from some existing prototype.
	auto FI = FunctionProtos.find(Name);
	if (FI != FunctionProtos.end())
		return FI->second->codegen();

	// If no existing prototype exists, return null.
	return nullptr;
}
*/

/// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
/// the function.  This is used for mutable variables etc.
AllocaInst* CreateEntryBlockAlloca(
	Function* TheFunction,
	string& VarName
) {
	IRBuilder<> TmpB(
		&TheFunction->getEntryBlock(),
		TheFunction->getEntryBlock().begin()
	);
	return TmpB.CreateAlloca(
		Type::getDoubleTy(*TheContext),
		nullptr,
		VarName
	);
}

Value* IdExprAST::codegen() { return nullptr; }

/*
Function* VarDecStmtAST::codegen() {
	// Transfer ownership of the prototype to the FunctionProtos map, but keep a
	// reference to it for use below.
	auto& P = *Proto;
	FunctionProtos[Proto->getName()] = move(Proto);
	Function* TheFunction = getFunction(P.getName());
	if (!TheFunction)
		return nullptr;

	// If this is an operator, install it.
	if (P.isBinaryOp())
		BinopPrecedence[P.getOperatorName()] = P.getBinaryPrecedence();

	// Create a new basic block to start insertion into.
	BasicBlock* BB = BasicBlock::Create(*TheContext, "entry", TheFunction);
	Builder->SetInsertPoint(BB);

	// Record the function arguments in the NamedValues map.
	NamedValues.clear();
	for (auto& Arg : TheFunction->args()) {
		// Create an alloca for this variable.
		AllocaInst* Alloca = CreateEntryBlockAlloca(TheFunction, Arg.getName());

		// Store the initial value into the alloca.
		Builder->CreateStore(&Arg, Alloca);

		// Add arguments to variable symbol table.
		NamedValues[string(Arg.getName())] = Alloca;
	}

	if (Value* RetVal = Body->codegen()) {
		// Finish off the function.
		Builder->CreateRet(RetVal);

		// Validate the generated code, checking for consistency.
		verifyFunction(*TheFunction);

		// Run the optimizer on the function.
		TheFPM->run(*TheFunction);

		return TheFunction;
	}

	// Error reading body, remove function.
	TheFunction->eraseFromParent();

	if (P.isBinaryOp())
		BinopPrecedence.erase(P.getOperatorName());
	return nullptr;
}
*/
void ModuleAST::codegen() {
	InitializeModuleAndPassManager("module");
	scope->codegen();
}

Value* VarDecStmtAST::codegen() {
	return nullptr;
	Value* v = varDec->codegen();
	// scope->namedValues[varDec->name] = v;
	return v;
}

Value* VarDefStmtAST::codegen() {
	return varDef->codegen();
}

Value* ReturnStmtAST::codegen() {
	Value* retVal = expr->codegen();
	Builder->CreateRet(retVal);
	verifyFunction(*Builder->GetInsertBlock()->getParent());
	return retVal;	// ??
}

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


		// return llvmFunc;
		return nullptr;
	}
	else {
		Function* TheFunction = Builder->GetInsertBlock()->getParent();

		llvm::AllocaInst* allocaInst = CreateEntryBlockAlloca(TheFunction, name);

		// TODO: change bitsize/type to match type
		Value* initVal = llvm::ConstantInt::get(*TheContext, llvm::APInt(64, 0, true));

		Builder->CreateStore(initVal, allocaInst);

		return allocaInst;
	}
}

Value* VarDefAST::codegen() {
	Value* v = varDec->codegen();
	if (varDec->isFuncType()) {
		Function* llvmFunc = TheModule->getFunction(varDec->name);
		BasicBlock* entryBB = BasicBlock::Create(*TheContext, "entry", llvmFunc);
		Builder->SetInsertPoint(entryBB);
		functionScope->codegen();
	}

	return v;
}


Value* OpExprAST::codegen() {
	Value* l = lhsExpr->codegen();
	Value* r = rhsExpr->codegen();
	if (!l || !r) return nullptr;

	switch (opcode) {
	case '+':
		return Builder->CreateAdd(l, r, "addtmp");
	case '-':
		return Builder->CreateSub(l, r, "sumtmp");
	case '*':
		return Builder->CreateMul(l, r, "multmp");
			// case '/':
			// 	return Builder.CreateDiv(l, r, "addtmp")
			// TODO: more ops here
	default:
		return LogErrorV("invalid binary operator");
	}
}

Value* NumLiteralAST::codegen() {
	// TODO: more types!
	return ConstantInt::get(*TheContext, llvm::APInt(64, num, true));
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