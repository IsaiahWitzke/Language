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

std::unique_ptr<LLVMContext> TheContext;
std::unique_ptr<Module> TheModule;
std::unique_ptr<IRBuilder<>> Builder;
std::map<std::string, AllocaInst*> NamedValues;
std::map<std::string, VarDecAST*> FunctionProtos;
ExitOnError ExitOnErr;

void InitializeModuleAndPassManager(const string &moduleName) {
	// Open a new module.
	TheContext = std::make_unique<LLVMContext>();
	TheModule = std::make_unique<Module>(moduleName, *TheContext);

	// Create a new builder for the module.
	Builder = std::make_unique<IRBuilder<>>(*TheContext);
}

// void ModuleAST::codegen() {
// 	InitializeModuleAndPassManager(name);
// }

bool outputObjCode(const std::string &fName) {

	// Initialize the target registry etc.
	InitializeAllTargetInfos();
	InitializeAllTargets();
	InitializeAllTargetMCs();
	InitializeAllAsmParsers();
	InitializeAllAsmPrinters();

	auto TargetTriple = sys::getDefaultTargetTriple();
	TheModule->setTargetTriple(TargetTriple);

	std::string Error;
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

	std::error_code EC;
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

Function* getFunction(std::string Name) {
	// First, see if the function has already been added to the current module.
	// if (auto* F = TheModule->getFunction(Name))
	// 	return F;

	// If not, check whether we can codegen the declaration from some existing
	// prototype.
	// auto FI = FunctionProtos.find(Name);
	// if (FI != FunctionProtos.end())
	// 	return FI->second->codegen();

	// If no existing prototype exists, return null.
	return nullptr;
}

/// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
/// the function.  This is used for mutable variables etc.
AllocaInst* CreateEntryBlockAlloca(Function* TheFunction,
	StringRef VarName) {
	IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
		TheFunction->getEntryBlock().begin());
	return TmpB.CreateAlloca(Type::getDoubleTy(*TheContext), nullptr, VarName);
}


Value *NumLiteralTermAST::codegen() {
	return ConstantInt::get(*TheContext, APInt(num, 64));
}

Value *IdTermAST::codegen() {
	return nullptr;
}

Value *ParenExprTermAST::codegen() {
	return nullptr;
}

Value *OpExprAST::codegen() { return nullptr; }

Value *TermExprAST::codegen() { return term->codegen(); }