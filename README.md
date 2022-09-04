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
- types
	- support more types than just i64
	- global vars are always initialized as 2... need some way of generating const expr code:e
- strings, arrays
- classes/structs/typedefs
- Rust-style borrow-checking
- First-class functions/closures
- Figure out a name for the language


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
