#include "lib.h"
#include <cstdio>

/// putchard - putchar that takes a double and returns 0.
double putchard(double X) {
	fputc((char)X, stderr);
	return 0;
}

/// printd - printf that takes a double prints it as "%f\n", returning 0.
double printd(double X) {
	fprintf(stderr, "%f\n", X);
	return 0;
}