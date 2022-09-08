# Language

A compiler using LLVM, Bison, and flex

# Guide

## Variables

Functions and variables are treated similar. To define either, the general syntax is:
```
<variable name>: <type> [= <initializer>];
```

For example, to define a 64-bit int:
```
my_int: i64 = 1337;
```

Functions are similar, but a little different in the type and init value:
```
my_func: () -> i64 = {

	//
	// more statements go here
	//

	return 4;
}
```

# TODO
- error messages for compile-time errors
- types
	- <del> support more types than just i64 </del>
		- <del> basic types: `i16, i32, i64, i128, f16, ..., f128` </del>
		- <del> type inference for basic types (`i16, ..., f128`) <del>
		- add `typeof x` unary operator (requires strings to be implemente)
	- global vars are always initialized as 2... need some way of generating const llvm expr code
	- classes/structs/typedefs
- strings, arrays
- rust-style borrow-checking
- first-class functions/closures
- figure out a name for the language


# Known bugs

```
globalVar: i64 = 2;

test_main: () -> i64 = {
	if(globalVar) {
		return 1;
	} else {
		return 2;
	}
}
```
Produces a seg fault in `llvm::BranchProbabilityInfo::getInitialEstimatedBlockWeight`.
Adding a redundant `return x;` to the end of the function resolves the error.
