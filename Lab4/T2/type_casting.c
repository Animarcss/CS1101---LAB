/*
 * type_casting_demos.c
  *   gcc type_casting.c -lm -o type_casting
 * Run:
 *   ./type_casting
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <string.h>
 
int main(void) {
    printf("Type Casting in C � Demonstrations (press Enter between segments)\n");
 
    /* 1) Integer division vs floating result via explicit cast */
    printf("\n[1] Integer vs floating division with casts\n");
    int a = 32, b = 5;
    printf("a=%d, b=%d\n", a, b);
    printf("a/b (int division)           = %d\n", a / b);
    printf("(float)a / b (promote a)     = %.2f\n", (float)a / b);
    printf("a / (float)b (promote b)     = %.2f\n", a / (float)b);
    printf("(float)(a/b) (too late cast) = %.2f\n", (float)(a / b));
    getchar();
 
 
 
    /* 2) Narrowing: floating -> integer (truncates toward zero) */
    printf("\n[3] Narrowing casts: float/double -> int (truncation toward zero)\n");
    float d1 = 3.9, d2 = -2.9;
    printf("d1=%f -> (int)d1=%d\n", d1, (int)d1);
    printf("d2=%f -> (int)d2=%d\n", d2, (int)d2);
    getchar();
 
    /* 3) Widening: integer -> floating; precision caveat beyond 2^53 for double */
    printf("\n[4] Widening casts and precision caveat\n");
    int x= 1073741830; /* 2^25 + 1: not exactly representable in binary64 double */
    float f = (float)x;
    int back = (int)f;
    printf("x=%d -> (float)x=%.0f -> (int)that=%d  (note the possible mismatch)\n", x, f, back);
    getchar();
 
 
    return 0;
}
