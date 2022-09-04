#pragma once

#include <memory>
#include <string>
#include <map>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Error.h"
#include "ast.h"

using namespace llvm;
using namespace llvm::sys;
using namespace std;

//===----------------------------------------------------------------------===//
// Code Generation
//===----------------------------------------------------------------------===//

extern unique_ptr<LLVMContext> TheContext;
extern unique_ptr<Module> TheModule;
extern unique_ptr<IRBuilder<>> Builder;
// extern map<string, VarDecAST*> FunctionProtos;
extern ExitOnError ExitOnErr;

void InitializeModuleAndPassManager(const string& moduleName);

bool outputObjCode(const string& fName);

/// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
/// the function.  This is used for mutable variables etc.
AllocaInst* CreateEntryBlockAlloca(Function* TheFunction, string& VarName);

Value* LogErrorV(const string& s);