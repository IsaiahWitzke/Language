#include "token.h"
#include <iostream>

unsigned basicTypeToSize(Token t) {
	switch (t) {
	case tok_f16:
		return 16;
	case tok_f32:
		return 32;
	case tok_f64:
		return 64;
	case tok_f128:
		return 128;
	case tok_i16:
		return 16;
	case tok_i32:
		return 32;
	case tok_i64:
		return 64;
	case tok_i128:
		return 128;
	default:
		std::cout << "Unknown type, cannot determine size, setting to 64 bits" << std::endl;
		return 64;
	}
}

bool isBasicTypeInt(Token t) {
	return tok_i16 <= t && t <= tok_i128;
}

bool isBasicTypeFloat(Token t) {
	return tok_f16 <= t && t <= tok_f128;
}

bool isBasicTypeSigned(Token t) {
	return true;	// TODO: implement unsigned ints
}