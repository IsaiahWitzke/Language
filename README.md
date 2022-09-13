# Language

A compiler using LLVM, Bison, and flex

# Guide

## Variables

Functions and variables are treated similar. To define either, the general syntax is:
```
<variable name>: [<type>] [= <initializer>];
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

## Type inference

The compiler will do it's best to guess a default type when you leave the `<type>` specifier blank:

```
default_int := 2;       // i64
default_float := 2.0;   // f64
small_int: i16 = 2;     // i16
small_float: f16 = 2;   // f16
some_func := { ... }    // ERROR: cannot infer function types
```

## if/else

Any non-zero integer is equivalent to a true value:

```
my_global := 2;

cond_func: () -> i64 {
    if (my_global) {   // 2 is non-zero => true
        return 1;      //               => will always return 1
    } else {
        return 0;
    }
}
```

## Run some code...

The object code that is compiled after `make run` allows for any function to be extern'd in your other C/C++ code and called,
but `make run_test` will compile and run the function `test_main: () -> i64` from `tests/test1.mylang` by default.


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
