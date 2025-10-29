/*
 * Recursion -based on the provided slides
 * Toggle any block by changing `#if 0` to `#if 1` and compile:
 * Each block is a self-contained program.
 */

#include <stdio.h>
#include <stdlib.h>

/* ----------------------------------------------------------
 * 1) Factorial (basic) — Slides: factorial example & flow
 * ---------------------------------------------------------- */
#if 1
int fact(int n){
    if(n <= 1) return 1;           // base case
    return n * fact(n-1);          // recursive step
}
int main(void){
    int n;
    printf("input a number to computer factorial\n");
    if(scanf("%d",&n)!=1) return 0;
    printf("%d! = %d\n", n, fact(n));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 2) Fibonacci (naive recursive) — Slides: Fibonacci
 *    (Demonstrates inefficiency due to repeated work)
 * ---------------------------------------------------------- */
#if 0
int fib(int n){
    if(n < 2) return n;
    return fib(n-1) + fib(n-2);
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    printf("Fibonacci(%d) = %d\n", n, fib(n));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 3) GCD (Euclid) — Slides: GCD recursion
 * ---------------------------------------------------------- */
#if 0
int gcd(int m, int n){
    if(n == 0) return m;
    return gcd(n, m % n);
}
int main(void){
    int m,n;
    if(scanf("%d %d",&m,&n)!=2) return 0;
    printf("gcd(%d,%d) = %d\n", m, n, gcd(m,n));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 4) nCr via recursion — Slides: Combination relation
 *    nCr(n,r) = nCr(n-1,r) + nCr(n-1,r-1), base: r==0 or r==n
 * ---------------------------------------------------------- */
#if 0
long long nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    if(r == 0 || r == n) return 1;
    return nCr(n-1, r) + nCr(n-1, r-1);
}
int main(void){
    int n,r;
    if(scanf("%d %d",&n,&r)!=2) return 0;
    printf("C(%d,%d) = %lld\n", n, r, nCr(n,r));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 5) Print digits of an integer in reverse — Slides: 11
 *    Example: input 2860 -> prints 0682
 * ---------------------------------------------------------- */
#if 0
void printReverseInt(unsigned int j){
    if(j < 10){
        printf("%u", j);
    } else {
        printf("%u", j % 10);
        printReverseInt(j / 10);
    }
}
int main(void){
    unsigned int x;
    if(scanf("%u",&x)!=1) return 0;
    printReverseInt(x);
    printf("\n");
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 6) Print name (line) in reverse — Slides: 12
 *    Reads a whole line (until '\n'), prints reversed.
 *    Modified output format per homework in slide.
 * ---------------------------------------------------------- */
#if 0
void printReverseChars(void){
    int c = getchar();
    if(c=='\r'){                   // handle CRLF (Windows) gracefully
        int next = getchar();
        if(next!='\n' && next!=EOF) ungetc(next, stdin);
        return;
    }
    if(c=='\n' || c==EOF) return;  // base case
    printReverseChars();
    putchar(c);
}
int main(void){
    printf("Enter your name:");
    fflush(stdout);
    printReverseChars();
    printf("\n");                  // original
    // Homework-style label:
    printf("Name in reverse:");
    // we need to read the same line again; easiest is to buffer first.
    // For demo: ask user again to re-enter to show labeled output.
    printf("\n(Re-enter for labeled output) Enter your name:");
    // Clear pending newline if needed
    int ch;
    while((ch=getchar())!='\n' && ch!=EOF) { /* flush */ }
    printf("Name in reverse:");
    printReverseChars();
    printf("\n");
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 7) Tower of Hanoi — Slides: 18
 * ---------------------------------------------------------- */
#if 0
void toh(int n, char F, char T, char A){
    if(n > 0){
        toh(n-1, F, A, T);
        printf("Move disk %d from %c to %c\n", n, F, T);
        toh(n-1, A, T, F);
    }
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    toh(n,'A','C','B');
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 8) Common mistakes — Slides: 19
 *    These are intentionally WRONG or risky; kept disabled.
 * ---------------------------------------------------------- */
#if 0
/* No base case -> infinite recursion */
int bad_fact(int n){
    return n * bad_fact(n-1);
}
int main(void){
    printf("%d\n", bad_fact(3));   // WARNING: infinite recursion
    return 0;
}
#endif

#if 0
/* Post-decrement in recursive arg + wrong base -> likely never hits base */
int func1(int n){
    if(n==1) return 1;
    return func1(n--);             // n-- passes old n; n never shrinks here
}
int main(void){
    printf("%d\n", func1(5));      // undefined behavior / infinite recursion
    return 0;
}
#endif

#if 0
/* Skips base for odd n */
int func2(int n){
    if(n==0) return 1;
    return n*(n-1)*func2(n-2);     // for odd n, never hits n==0
}
int main(void){
    printf("%d\n", func2(5));      // WARNING
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 9) Data storage / tracing addresses — Slides: 21
 *    Demonstrative: prints local addresses & values across recursion frames.
 * ---------------------------------------------------------- */
#if 0
int fact_trace(int n){
    int val;
    if(n==1) return 1;
    val = n * fact_trace(n-1);
    printf("n: %p,%d  val: %p,%d\n", (void*)&n, n, (void*)&val, val);
    return val;
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    fact_trace(n);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 10) Three input/print-order puzzles — Slides: 22
 * ---------------------------------------------------------- */
#if 0
/* A) Read, then recurse, then print: prints numbers in reverse input order */
void funcA(int n){
    int d;
    if(n==0) return;
    scanf("%d",&d);
    funcA(n-1);
    printf("%d\n",d);
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    funcA(n);
    return 0;
}
#endif

#if 0
/* B) Recurse first, then read, then print: prints in input order but after unwinding */
void funcB(int n){
    int d;
    if(n==0) return;
    funcB(n-1);
    scanf("%d",&d);
    printf("%d\n",d);
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    funcB(n);
    return 0;
}
#endif

#if 0
/* C) Read, print, recurse: prints in input order immediately */
void funcC(int n){
    int d;
    if(n==0) return;
    scanf("%d",&d);
    printf("%d\n",d);
    funcC(n-1);
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    funcC(n);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 11) Running sum 1..n with prints — Slides: 23
 * ---------------------------------------------------------- */
#if 0
int sumPrint(int n){
    int s;
    if(n==0) return 0;
    s = n + sumPrint(n-1);
    printf("%d\n", s);
    return s;
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    sumPrint(n);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 12) Input n numbers, print partial sums in recursion vs tail — Slides: 24
 * ---------------------------------------------------------- */
#if 0
/* Version 1: classic recursion with return sum */
int sumInputsReturn(int n){
    int sum, d;
    if(n==0) return 0;
    scanf("%d",&d);
    sum = sumInputsReturn(n-1);
    sum += d;
    printf("%d\n", sum);
    return sum;
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    sumInputsReturn(n);
    return 0;
}
#endif

#if 0
/* Version 2: tail-recursive style carrying the sum */
void sumInputsTail(int n, int sum){
    int d;
    if(n==0) return;
    scanf("%d",&d);
    sum += d;
    printf("%d\n", sum);
    sumInputsTail(n-1, sum);
}
int main(void){
    int n=5;
    (void)scanf("%d",&n);
    sumInputsTail(n, 0);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 13) Multiplication via repeated sum — Slides: 25
 *    Computes n * m as m + (n-1)*m (assuming n>=1)
 * ---------------------------------------------------------- */
#if 0
int mul_rep(int n, int m){
    if(n==1) return m;
    return m + mul_rep(n-1, m);
}
int main(void){
    int n=13, m=5;
    (void)scanf("%d %d",&n,&m);
    printf("%d\n", mul_rep(n,m));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 14) Largest element in array — two styles — Slides: 26,27
 * ---------------------------------------------------------- */
#if 0
/* Style 1: linear recursion using [low..size-1) */
int max_linear(const int x[], int low, int size){
    if(low == size) return x[low-1];
    int large = max_linear(x, low+1, size);
    return (large > x[low-1]) ? large : x[low-1];
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1 || n<=0) return 0;
    int *a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("max = %d\n", max_linear(a, 1, n));
    free(a);
    return 0;
}
#endif

#if 0
/* Style 2: divide & conquer using [l..h] */
int max_divide(const int x[], int l, int h){
    if(l == h) return x[l];
    int mid = (l+h)/2;
    int maxl = max_divide(x, l,     mid);
    int maxr = max_divide(x, mid+1, h);
    return (maxl > maxr) ? maxl : maxr;
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1 || n<=0) return 0;
    int *a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("max = %d\n", max_divide(a, 0, n-1));
    free(a);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 15) Find element in array (recursive) — Practice
 *     Returns index or -1
 * ---------------------------------------------------------- */
#if 0
int find_rec(const int a[], int n, int key){
    if(n<=0) return -1;
    if(a[n-1]==key) return n-1;
    return find_rec(a, n-1, key);
}
int main(void){
    int n, key;
    if(scanf("%d",&n)!=1 || n<=0) return 0;
    int *a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&key);
    printf("index = %d\n", find_rec(a, n, key));
    free(a);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 16) Print binary representation of an integer — Practice
 * ---------------------------------------------------------- */
#if 0
void print_binary(unsigned int x){
    if(x > 1) print_binary(x>>1);
    putchar('0' + (x & 1));
}
int main(void){
    unsigned int x;
    if(scanf("%u",&x)!=1) return 0;
    print_binary(x);
    putchar('\n');
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 17) Sum of squares of array elements — Practice
 * ---------------------------------------------------------- */
#if 0
long long sumsq_rec(const int a[], int n){
    if(n<=0) return 0;
    long long tail = sumsq_rec(a, n-1);
    return tail + 1LL*a[n-1]*a[n-1];
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1 || n<=0) return 0;
    int *a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%lld\n", sumsq_rec(a, n));
    free(a);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 18) Copy one array to another (recursive) — Practice
 * ---------------------------------------------------------- */
#if 0
void copy_rec(const int src[], int dst[], int n){
    if(n<=0) return;
    copy_rec(src, dst, n-1);
    dst[n-1] = src[n-1];
}
int main(void){
    int n;
    if(scanf("%d",&n)!=1 || n<=0) return 0;
    int *a = malloc(sizeof(int)*n);
    int *b = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    copy_rec(a,b,n);
    for(int i=0;i<n;i++) printf("%d%c", b[i], i+1==n?'\n':' ');
    free(a); free(b);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 19) Power function x^n (float x, int n) — Practice
 *     Handles n>=0, simple recursion (can be optimized with fast pow).
 * ---------------------------------------------------------- */
#if 0
double power(double x, int n){
    if(n==0) return 1.0;
    return x * power(x, n-1);
}
int main(void){
    double x; int n;
    if(scanf("%lf %d",&x,&n)!=2) return 0;
    if(n<0){ puts("n must be >= 0 for this simple version."); return 0; }
    printf("%g\n", power(x,n));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * 20) Fast power x^n (log n recursion) — enrichment
 * ---------------------------------------------------------- */
#if 0
double fast_power(double x, int n){
    if(n==0) return 1.0;
    if(n%2==0){
        double t = fast_power(x, n/2);
        return t*t;
    }else{
        return x * fast_power(x, n-1);
    }
}
int main(void){
    double x; int n;
    if(scanf("%lf %d",&x,&n)!=2) return 0;
    if(n<0){ puts("n must be >= 0 for this demo."); return 0; }
    printf("%g\n", fast_power(x,n));
    return 0;
}
#endif


