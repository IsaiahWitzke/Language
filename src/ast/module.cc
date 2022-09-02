#include "module.h"

void ModuleAST::codegen() {
	InitializeModuleAndPassManager("module");
	scope->codegen();
}