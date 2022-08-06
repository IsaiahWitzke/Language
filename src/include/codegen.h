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

//===----------------------------------------------------------------------===//
// Code Generation
//===----------------------------------------------------------------------===//

extern std::unique_ptr<LLVMContext> TheContext;
extern std::unique_ptr<Module> TheModule;
extern std::unique_ptr<IRBuilder<>> Builder;
extern std::map<std::string, AllocaInst*> NamedValues;
extern std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;
extern ExitOnError ExitOnErr;

/// to set up the codegen globals
void InitializeModuleAndPassManager();

bool outputObjCode(const std::string &fName);