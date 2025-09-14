/* pitfalls_functions.c
 */
#include <stdio.h>
#include <stdlib.h>
 
 
/* ===========================================================
   1) Missing prototype
   Pitfall: calling a function before it is declared/prototyped.
   Modern C treats implicit declaration as an error.
   =========================================================== */
 
#if 0
/*  BAD: No prototype before use */
int main(void) {
    printf("%d\n", square(5));  // implicit declaration (error in modern C)
    return 0;
}
int square(int x) { return x*x; }
#endif
 
/*  GOOD: Provide a prototype before use */
static int square_good(int x);                /* prototype */
static int square_good(int x) { return x*x; } /* definition */
 
/* ===========================================================
   2) Missing return in non-void function (Undefined Behavior)
   =========================================================== */
 
#if 0
/*  BAD: May "fall off" without returning a value (UB) */
int bad_missing_return(int x) {
    if (x > 0) return x;
    /* missing return when x <= 0 */
}
#endif
 
/*  GOOD: Always return something */
static int good_missing_return(int x) {
    return (x > 0) ? x : 0;
}
 
/* ===========================================================
   3) Macro "functions" re-evaluate arguments (side effects)
   =========================================================== */
 
/*  BAD: Macro may evaluate arguments multiple times */
#define MAX_BAD(a,b) ((a) > (b) ? (a) : (b))
 
/* BETTER: inline function (single evaluation, type-checked) */
static inline int max_i(int a, int b) { return (a > b) ? a : b; }
 
/* ===========================================================
   4) Pass-by-value vs. �reference� (pointers needed to modify)
   =========================================================== */
 
#if 0
/*  BAD: No effect on caller because parameters are copies */
void swap_bad(int a, int b) { int t = a; a = b; b = t; }
#endif
 
/* GOOD: Use pointers to modify caller's variables */
static void swap_good(int *a, int *b) { int t = *a; *a = *b; *b = t; }
 
/* ===========================================================
   5) Infinite recursion (no base case)
   =========================================================== */
 
#if 0
/*  BAD: No terminating condition � stack overflow */
int fact_bad(int n) { return n * fact_bad(n - 1); }
#endif
 
/*  GOOD: Base case included */
 int fact_good(int n) { return (n <= 1) ? 1 : n * fact_good(n - 1); }
 
/* ===========================================================
   6) Shadowing globals (confusing which variable is used)
   =========================================================== */
 
 int G = 10;  /* global */
 
#if 0
/*  BAD: Local x shadows global G unintentionally */
void shadow_bad(void) {
    int G = 5;                // shadows global G
    printf("shadow_bad G=%d\n", G);
}
#endif
 
/*  GOOD: Use distinct names or qualify with intent in comments */
static void shadow_good(void) {
    int local_g = 5;
    printf("local_g=%d, global G=%d\n", local_g, G);
}
 
/* ===========================================================
   7) Static vs automatic duration (persisting state)
   =========================================================== */
 
#if 0
/* (Not exactly �bad�, but often misunderstood): automatic reinitializes */
void counter_auto(void) { int c = 0; printf("%d\n", ++c); }  // always prints 1
#endif
 
/*  GOOD: static local persists across calls */
 void counter_static(void) { static int c = 0; printf("%d\n", ++c); }
 
/* ===========================================================
   8) Incorrect parameter types / silent conversions
   =========================================================== */
 
#if 0
/*  BAD: Prototype mismatch or relying on implicit conversions */
int sum_bad(int a, int b) { return a + b; }
/* Calling sum_bad(1.5, 2.5) silently truncates to (1,2) in C */
#endif
 
/*  GOOD: Match types (and use warnings) */
static int sum_int(int a, int b) { return a + b; }
 
/* ===========================================================
   9) Format-specifier mismatch in printf/scanf
   =========================================================== */
 
#if 0
/*  BAD: UB � wrong specifier for double */
void print_double_bad(double d) { printf("%d\n", d); }  // should be %f
#endif
 
/*  GOOD: Use correct specifiers */
static void print_double_good(double d) { printf("%.2f\n", d); }
 
/* ===========================================================
   10) Function overloading (C does NOT support it)
   =========================================================== */
 
#if 0
/*  BAD: Not allowed � duplicate symbol 'add' with different types */
int add(int a,int b){return a+b;}
float add(float x,float y){return x+y;} /* error in C */
#endif
 
/*  GOOD: Either rename, or use different prefixes/suffixes */
static int add_i(int a, int b) { return a + b; }
static double add_d(double x, double y) { return x + y; }
 
/* ===========================================================
   11) Prototype/definition mismatch
   =========================================================== */
 
#if 0
/*  BAD: Declaration doesn't match definition */
int area(int, int);       // takes two ints
int area(int w) { return w*w; }  // conflicting definition
#endif
 
/*  GOOD: Keep declarations and definitions consistent */
 int area_rect(int w, int h) { return w * h; }
 
/* ===========================================================
   MAIN: run all corrected demos + safely illustrate pitfalls
   =========================================================== */
 
int main(void) {
    /* 1) Missing prototype: show corrected call */
    puts("1) Missing prototype (corrected version):");
    printf("square_good(5) = %d\n", square_good(5));
 
 
    /* 2) Missing return: show corrected behavior */
    puts("2) Missing return (corrected version):");
    printf("good_missing_return(5)  = %d\n", good_missing_return(5));
    printf("good_missing_return(-3) = %d\n", good_missing_return(-3));
    getchar();
 
    /* 3) Macro side effects: illustrate danger vs. inline */
    puts("3) Macro side effects (BAD macro vs inline):");
    int i = 5, j = 10;
    /* Demonstrate MAX_BAD with side effect � show the danger */
    int r1 = MAX_BAD(i++, j);   /* i++ may be evaluated twice => value of i can jump */
    printf("After MAX_BAD(i++, j): i=%d, j=%d, result=%d   (DANGER demo)\n", i, j, r1);
    /* Reset and do it right with inline function (single evaluation) */
    i = 5; j = 10;
    int r2 = max_i(i++, j);
    printf("After max_i(i++, j):   i=%d, j=%d, result=%d   (SAFE inline)\n", i, j, r2);
    getchar();
    /* 4) Pass-by-value vs reference */
    puts("4) Pass-by-value vs reference (swap):");
    int a = 3, b = 4;
    printf("Before swap_good: a=%d b=%d\n", a, b);
    swap_good(&a, &b);
    printf("After  swap_good: a=%d b=%d\n", a, b);
    getchar();
    /* 5) Recursion base case */
    puts("5) Recursion base case (factorial):");
    printf("fact_good(5) = %d\n", fact_good(5));
    getchar();
 
    /* 6) Shadowing globals */
    puts("6) Shadowing globals (good style demo):");
    shadow_good();
    getchar();
    /* 7) Static vs automatic */
    puts("7) Static vs automatic duration:");
    printf("counter_static calls: ");
    counter_static(); counter_static(); counter_static();   /* prints 1,2,3 */
    getchar();
 
    /* 8) Parameter types & conversions */
    puts("8) Parameter types & conversions:");
    printf("sum_int(3, 4) = %d\n", sum_int(3, 4));
    /* If you accidentally wrote sum_int(1.5, 2.5), they'd be converted to (1,2) */
    getchar();
 
    /* 9) Format specifiers */
    puts("9) Format specifiers:");
    double d = 3.14159;
    printf("Correct double print: ");
    print_double_good(d);      /* prints 3.14 */
    getchar();
 
    /* 10) No overloading; use distinct names */
    puts("10) No function overloading in C:");
    printf("add_i(2,3) = %d; add_d(2.5,3.5) = %.1f\n", add_i(2,3), add_d(2.5,3.5));
     getchar();
    /* 11) Prototype/definition match */
    puts("11) Prototype/definition match:");
    printf("area_rect(3,4) = %d\n", area_rect(3,4));
    getchar();
 
    puts("\nAll demos complete.");
    return 0;
}
