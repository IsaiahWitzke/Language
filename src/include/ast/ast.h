#pragma once

#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "codegen.h"
#include "assignment_stmt.h"
#include "expr_stmt.h"
#include "expr.h"
#include "func_call.h"
#include "id_expr.h"
#include "module.h"
#include "num_literal.h"
#include "op_expr.h"
#include "return_stmt.h"
#include "scope.h"
#include "stmt.h"
#include "type.h"
#include "var_dec_stmt.h"
#include "var_dec.h"
#include "var_def_stmt.h"
#include "var_def.h"

using namespace std;
using namespace llvm;

