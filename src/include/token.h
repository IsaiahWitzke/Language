#pragma once

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token {
	tok_eof = -1,

	// commands
	tok_func = -2,
	tok_extern = -3,

	// primary
	tok_identifier = -4,
	tok_number = -5,

	// control
	tok_if = -6,
	tok_then = -7,
	tok_else = -8,
	tok_for = -9,
	tok_in = -10,

	// operators
	tok_binary = -11,
	tok_unary = -12,

	// var definition
	tok_var = -13,

	// types
	tok_i128 = -15,
	tok_i64 = -16,
	tok_i32 = -17,
	tok_i16 = -18,
	tok_f128 = -19,
	tok_f64 = -20,
	tok_f32 = -21,
	tok_f16 = -22,
	// tok_u16 = -23,
	// tok_u32 = -23,
	// tok_u128 = -23,

	tok_unknown = -100
};

unsigned basicTypeToSize(Token t);

bool isBasicTypeInt(Token t);

bool isBasicTypeFloat(Token t);

bool isBasicTypeSigned(Token t);