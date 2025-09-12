/* types_demo.c
 * Demonstrates sizes, max values, and examples for C numeric types.
 */
#include <stdio.h>
#include <limits.h>   // CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN, etc.
#include <float.h>    // FLT_MIN, DBL_MIN, LDBL_MIN, FLT_DIG, DBL_DIG, LDBL_DIG
#include <stdint.h>   // optional: fixed-width types (not used in the table)

int main(void) {
    printf("C Numeric Types — Sizes & Maximum Values\n");

    // printf("%-12s is a printf format; 12 ? minimum field width is 12 characters.\n\n");
    /* Table header */
    printf("%-12s %-7s %-28s %-18s\n", "Type", "Bytes", "Maximum Value", "printf specifier(s)");

    printf("-------------------------------------------------------------------------------\n");

    /* Integer-family */
    printf("%-12s %-7zu %-28d %-18s\n", "char",        sizeof(char),        CHAR_MIN,      "%c / %d");
    printf("%-12s %-7zu %-28d %-18s\n", "short",       sizeof(short),       SHRT_MIN,      "%hd / %hu");
    printf("%-12s %-7zu %-28d %-18s\n", "int",         sizeof(int),         INT_MIN,       "%d / %u");
    printf("%-12s %-7zu %-28ld %-18s\n", "long",        sizeof(long),        LONG_MIN,      "%ld / %lu");
    printf("%-12s %-7zu %-28lld %-18s\n", "long long",   sizeof(long long),   LLONG_MIN,     "%lld / %llu");

    /* Floating-point family:
       For floats, the 'minimum' (DBL_MIN etc.) is the smallest positive normal number,
       not the most negative. Since we were asked for maxima, we print *MAX only*.  */
    printf("%-12s %-7zu %-28e %-18s\n", "float",       sizeof(float),       FLT_MIN,       "%f / %e / %g");
    printf("%-12s %-7zu %-28e %-18s\n", "double",      sizeof(double),      DBL_MIN,       "%lf / %e / %g");
    printf("%-12s %-7zu %-28Le %-18s\n", "long double", sizeof(long double), LDBL_MIN,      "%Lf / %Le / %Lg");

    /* A few helpful extras about precision (decimal digits you can trust) */
    printf("\nDecimal precision: float=~%d digits, double˜%d digits, long double˜%d digits\n",
           FLT_DIG, DBL_DIG, LDBL_DIG);

    /* ---------------------- Examples ---------------------- */
    printf("\nExamples:\n");
    /* 1) char as character and as integer code point */
    char ch = 'A';
    printf("char example: ch='%c', numeric code of ch=%d\n", ch, (int)ch);

    /* 2) Correct specifiers for each integer width */
    short s = 12345;
    int   i = 123456789;
    long  l = 1234567890L;
    long long ll = 1234567890123LL;
    printf("short with %%hd: %hd ; unsigned with %%hu: %hu\n", s, (unsigned short)s);
    printf("int with %%d: %d ; unsigned with %%u: %u\n", i, (unsigned)i);
    printf("long with %%ld: %ld ; unsigned with %%lu: %lu\n", l, (unsigned long)l);
    printf("long long with %%lld: %lld ; unsigned with %%llu: %llu\n", ll, (unsigned long long)ll);

    /* 3) Floating printing (note: float arguments promote to double in printf) */
    float  f = 3.1415927f;
    double d = 2.718281828459045;
    long double ld = 1.6180339887498948482L;
    printf("float with %%f: %f ; scientific %%e: %e ; compact %%g: %g\n", f, f, f);
    printf("double with %%lf: %lf ; scientific %%e: %e\n", d, d);
    printf("long double with %%Lf: %Lf ; scientific %%Le: %Le\n", ld, ld);

    /* 4) Integer division vs. floating division */
    int a = 7, b = 2;
    printf("int division 7/2 = %d (int)\n", a / b);
    printf("float division 7/2.0 = %f (double)\n", a / 2.0);

    /* 5) Safe demonstration of wraparound (well-defined only for *unsigned*) */
    unsigned int umax = UINT_MAX;
    printf("Unsigned wraparound example: UINT_MAX=%u ; UINT_MAX+1=%u\n", umax, umax + 1U);

    /* 6) Near-maximum examples (no signed overflow) */
    int near = INT_MAX - 1;
    printf("Near INT_MAX arithmetic: (INT_MAX-1) + 1 = %d (safe)\n", near + 1);

    /* 7) Range reminders for 'char' (implementation dependent) */
    printf("On this compiler: CHAR_MIN=%d, CHAR_MAX=%d (signedness of plain 'char')\n",
           (int)CHAR_MIN, (int)CHAR_MAX);

    return 0;
}
