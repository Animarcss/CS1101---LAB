#include <stdio.h>
#include <limits.h>
#include <float.h> // CHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX, etc.
#include <float.h> // FLT_MAX, DBL_MAX, LDBL_MAX, FLT_DIG, DBL_DIG, LDBL_DIG
#include <stdint.h> // optional: fixed-width types (not used in the table)

int main(void) {
	/* Integer-family */
	printf("%-12s %-7zu %-28d %-18s\n", "char", sizeof(char), CHAR_MAX, "%c /%d");
	printf("%-12s %-7zu %-28d %-18s\n", "short", sizeof(short), SHRT_MAX, "%hd / %hu");
	printf("%-12s %-7zu %-28d %-18s\n", "int", sizeof(int), INT_MAX, "%d / %u");
	printf("%-12s %-7zu %-28ld %-18s\n", "long", sizeof(long), LONG_MAX, "%ld / %lu");
	printf("%-12s %-7zu %-28lld %-18s\n", "long long", sizeof(long long), LLONG_MAX, "%lld / %llu");
	/* Floating-point family: For floats, the 'minimum' (DBL_MIN etc.) is the smallest positive normal number, not the most negative. Since we were asked for maxima, we print *MAX only*. */
	printf("%-12s %-7zu %-28e %-18s\n", "float", sizeof(float), FLT_MAX, "%f / %e / %g");
	printf("%-12s %-7zu %-28e %-18s\n", "double", sizeof(double), DBL_MAX, "%lf / %e / %g");
	printf("%-12s %-7zu %-28Le %-18s\n", "long double", sizeof(long double), LDBL_MAX, "%Lf / %Le / %Lg");
