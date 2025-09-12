/*
 * L31_demos
 * CS1101: Foundations of Programming � Data types, operators, expressions
 * Single-file; uses getchar() between segments.
 * Build (Linux/Mac):
 *   gcc L31_demos.c -o L31_demos -lm
 * Run:
 *   ./L31_demos
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <string.h>
 
int main(void) { 							//  HERE
    printf("CS1101: Data types, operators, expression � demos \n");
    printf("Press Enter after each segment to continue.\n");
 
    /* Slide 02: Basic data types */
    printf("\n=== Slide 02: Basic data types ===\n");
    printf("char:        size=%zu bytes, CHAR_MIN=%d, CHAR_MAX=%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("int:         size=%zu bytes, INT_MIN=%d, INT_MAX=%d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("float:       size=%zu bytes, FLT_DIG=%d (decimal digits), FLT_MIN=%e, FLT_MAX=%e\n",
           sizeof(float), FLT_DIG, FLT_MIN, FLT_MAX);
    printf("double:      size=%zu bytes, DBL_DIG=%d, DBL_MIN=%e, DBL_MAX=%e\n",
           sizeof(double), DBL_DIG, DBL_MIN, DBL_MAX);
    getchar();
 
    /* Slide 03: Type qualifiers */
    printf("\n=== Slide 03: Type qualifiers ===\n");
    printf("short int:   size=%zu bytes, range ~[%d,%d]\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("long int:    size=%zu bytes, range ~[%ld,%ld]\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long:   size=%zu bytes, range ~[%lld,%lld]\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("unsigned int size=%zu bytes, range ~[0,%u]\n", sizeof(unsigned),  UINT_MAX);
    printf("signed char: size=%zu bytes, range ~[%d,%d]\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char size=%zu bytes, range ~[0,%u]\n", sizeof(unsigned char), UCHAR_MAX);
    getchar();
 
    /* Slides 04�05: Constants */
    printf("\n=== Slides 04�05: Constants ===\n");
    long L = 123456789L;
    unsigned U = 4000000000U; /* may wrap on systems where unsigned is 32-bit */
    unsigned long UL = 4294967295UL;
    printf("Integer constants: L=%ld, U=%u, UL=%lu\n", L, U, UL);
 
    double d1 = 12.34, d2 = 1e-2, d3 = 4.56e2;
    float  f1 = 3.14159f;
    long double ld1 = 1.234L;
    printf("Floating constants: d1=%f, d2=%f, d3=%f, f1=%f, ld1=%Lf\n", d1, d2, d3, f1, ld1);
 
    char newline = '\n', tab = '\t', quote = '\'', backslash='\\', nul = '\0';
    printf("Escapes: newline='\\\\n'=%d, tab='\\\\t'=%d, quote='\\''=%d, backslash='\\\\'=%d, nul='\\\\0'=%d\n",
           (int)newline, (int)tab, (int)quote, (int)backslash, (int)nul);
 
    const char s1[] = "good";
    const char s2[] = "IIT Patna";
    const char s3[] = "9+16";
    const char s4[] = "T";
    printf("Strings: \"%s\", \"%s\", \"%s\", \"%s\"\n", s1, s2, s3, s4);
    getchar();
 
    /* Slide 06: 'T' vs "T" */
    printf("\n=== Slide 06: 'T' vs \"T\" ===\n");
    char ch = 'T'; 									//char test[] ="T";
    const char str[] = "T";
    printf("'T' as char -> value (int)=%d, size=%zu byte\n", (int)ch, sizeof(ch));
    printf("\"T\" as string -> points to NUL-terminated array, strlen=%zu, sizeof literal incl. NUL often=%zu\n",
           strlen(str), sizeof("T"));
    char var = 'A';
    printf("Example: var='A' -> as %%c='%c', as %%d=%d\n", var, var);
    getchar();
 
    /* Slide 07: Value vs address */
    printf("\n=== Slide 07: Variable value vs address ===\n");
    int svar = 100;
    svar = svar + 2;
    printf("var (content) = %d\n", svar);
    printf("&var (address) = %p\n", (void*)&svar);
    printf("scanf(\"%%d\", &var) reads into the address of var; printf(\"%%d\", var) prints its value.\n");
    getchar();
 
    /* Slide 08: Assignment */
    printf("\n=== Slide 08: Assignment examples ===\n");
    int var1 = 0, a, b, c, z;
    var1 = 100;
    z = 40 * 3 * 20;
    a = b = c = 10;
    printf("var1=%d, z=%d, a=%d, b=%d, c=%d\n", var1, z, a, b, c);
    int V, n=2, R=3, T=4, P=5, d, u=7, t=3, f=2;
    V = n * R * T / P;
    d = u * t + 0.5 * f * t; /* implicit double->int truncation! (intentional for demo) */
    printf("V=n*R*T/P -> %d; d=u*t+0.5*f*t (int) -> %d\n", V, d);
    getchar();
 
    /* Slide 09: l-value / r-value types */
    printf("\n=== Slide 09: l-value/r-value type conversion ===\n");
    double dv; dv = 5 * 7;
    int iv; iv = (int)(5.5 * 7);
    printf("double dv = 5 * 7 -> dv=%f\n", dv);
    printf("int iv = 5.5 * 7 -> iv=%d (fraction part lost)\n", iv);
    getchar();
 
    /* Slide 11: Arithmetic operators */
    printf("\n=== Slide 11: Arithmetic operators ===\n");
    int x=23, y=5;
    printf("Given x=%d, y=%d -> x+y=%d, x-y=%d, x*y=%d, x/y=%d, x%%y=%d\n",
           x, y, x+y, x-y, x*y, x/y, x%y);
    double p=5.5, q=2.0;
    printf("Floating: p=%.1f, q=%.1f -> p/q=%f\n", p, q, p/q);
    getchar();
 
    /* Slide 12: Precedence & associativity */
    printf("\n=== Slide 12: Operator precedence & associativity ===\n");
    int aa=2, bb=3, cc=4, dd=8, ee=5, ff=7, xx, yy, zz;
    xx = aa + bb * cc - dd / ee;
    yy = aa * -bb + dd % ee - ff;
    zz = aa - bb + cc - dd;
    printf("a=%d,b=%d,c=%d,d=%d,e=%d,f=%d\n",aa,bb,cc,dd,ee,ff);
    printf("a+b*c-d/e = %d\n", xx);
    printf("a*-b+d%%e-f = %d\n", yy);
    printf("a-b+c-d = %d\n", zz);
    int xyz = aa*bb*cc;
    int sumprod = aa + bb + cc*dd*ee;
    printf("x*y*z -> %d; a+b+c*d*e -> %d\n", xyz, sumprod);
    getchar();
 
    /* Slide 13: Unary minus */
    printf("\n=== Slide 13: Unary minus ===\n");
    int ux = 5;
    printf("x=%d, -x=%d, -(x+2)=%d\n", ux, -ux, -(ux+2));
    getchar();
 
    /* Slide 14: Integer vs real vs mixed arithmetic */
    printf("\n=== Slide 14: Integer/Real/Mixed arithmetic ===\n");
    printf("23 / 5 (int) -> %d\n", 23/5);
    printf("1.0 / 6.0 * 6.0 (double) -> %.10f (rounding)\n", 1.0/6.0*6.0);
    printf("23.0 / 5.0 (double) -> %.2f\n", 23.0/5.0);
    getchar();
 
    /* Slides 15�17: Implicit vs explicit conversion */
    printf("\n=== Slides 15�17: Implicit vs explicit conversion ===\n");
    int ia=32, ib=5, ic;
    float zf;
    ic = ia / ib;
    zf = ia / ib;
    printf("int a=32,b=5; c=a/b -> %d; z=a/b -> %.1f (we want 6.4)\n", ic, zf);
    zf = ((float)ia) / ib;
    printf("With cast: z=((float)a)/b -> %.1f\n", zf);
    float fz = 3.7f;
    int   iz = fz;
    printf("Narrowing example: float 3.7 -> int %d (fraction lost)\n", iz);
    getchar();
 
    /* Slides 18�19: Casting pitfalls & average */
    printf("\n=== Slides 18�19: Casting pitfalls & average of two ints ===\n");
    int ca = 7, cb = 8;
    float avg_bad = (ca + cb) / 2;
    float avg_ok1 = ((float)(ca + cb)) / 2;
    float avg_ok2 = (ca + cb) / 2.0f;
    printf("a=%d, b=%d -> avg_bad=(a+b)/2 -> %.1f (WRONG)\n", ca, cb, avg_bad);
    printf("avg_ok1=((float)(a+b))/2 -> %.1f (RIGHT)\n", avg_ok1);
    printf("avg_ok2=(a+b)/2.0 -> %.1f (RIGHT)\n", avg_ok2);
    double big = 1e20;
    int truncated = (int)big;
    printf("Casting very large double 1e20 to int truncates/wraps -> %d (narrowing!)\n", truncated);
    getchar();
 
    /* Slide 20: Compound assignment */
    printf("\n=== Slide 20: Compound assignment ===\n");
    int caa=12, cbb=3;
    printf("Start: a=%d, b=%d\n", caa, cbb);
    caa += cbb; printf("a += b -> a=%d\n", caa);
    caa -= cbb; printf("a -= b -> a=%d\n", caa);
    caa *= cbb; printf("a *= b -> a=%d\n", caa);
    caa %= cbb; printf("a %%= b -> a=%d\n", caa);
    getchar();
 
    /* Slide 21: ++ and -- */
    printf("\n=== Slide 21: ++ and -- (prefix vs postfix) ===\n");
    int pa=13, pb=7, px;
    px = 5 + ++pa; printf("x=5+++a -> x=%d, a=%d\n", px, pa);
    px = 5 + pa++; printf("x=5+a++ -> x=%d, a=%d\n", px, pa);
    px = pa++ + --pb; printf("x=a+++--b -> x=%d, a=%d, b=%d\n", px, pa, pb);
    printf("Avoid expressions like a++ - ++a (undefined behavior)\n");
    getchar();
 
    /* Slide 22: Relational operators */
    printf("\n=== Slide 22: Relational operators ===\n");
    printf("10 > 20 -> %d\n", 10 > 20);
    printf("34 < 45 -> %d\n", 34 < 45);
    printf("34 == (30 + 5) -> %d\n", 34 == (30 + 5));
    printf("34 != (30 + 5) -> %d\n", 34 != (30 + 5));
    getchar();
 
    /* Slides 23�25: Logical operators */
    printf("\n=== Slides 23�25: Logical operators ===\n");
    int li=7; double lf=5.5; char lc='w';
    printf("(i>=6) && (c=='w') -> %d\n", (li>=6) && (lc=='w'));
    printf("(i>=6) || (c==119) -> %d\n", (li>=6) || (lc==119));
    printf("(f<11) && (i>=100) -> %d\n", (lf<11) && (li>=100));
    printf("(c!='p') || (i+f<=100) -> %d\n", (lc!='p') || (li+lf<=100));
    int la = 2;
    int wrong = ((la != 2) || (la != 3));
    int right = ((la != 2) && (la != 3));
    printf("Trap: a=%d -> ((a!=2)||(a!=3))=%d (WRONG), ((a!=2)&&(a!=3))=%d (RIGHT)\n", la, wrong, right);
    int lx=3, ly=0;
    printf("%d AND %d = %d, %d OR %d = %d\n", lx,ly, lx&&ly, lx,ly, lx||ly);
    getchar();
 
    /* Slide 26: Precedence demo */
    printf("\n=== Slide 26: Precedence demo ===\n");
    int qa=2,qb=3,qc=4;
    int r1 = qa + qb * qc;
    int r2 = (qa + qb) * qc;
    int r3 = qa && qb || 0;
    int r4 = (qa=0) || (qb=0);
    printf("a=%d, b=%d, c=%d\n", qa,qb,qc);
    printf("a + b * c = %d; (a + b) * c = %d\n", r1, r2);
    printf("a&&b||0 = %d; (a=0)||(b=0) -> a=%d,b=%d\n", r3, qa, qb);
    (void)r4; /* suppress unused warning while still performing assignment above */
    getchar();
 
    /* Slides 27�29: Assignment expression values */
    printf("\n=== Slides 27�29: Assignment expression values ===\n");
    int u1=0, v=0, w=0;
    u1 = 3;
    printf("Value of (u1=3) is %d; u now %d\n", (u1=3), u1);
    v = (2*4 - 6);
    printf("v = 2*4 - 6 -> v=%d\n", v);
    w = (u = 5) + (v = 7);
    printf("w = (u=5) + (v=7) -> w=%d, u=%d, v=%d\n", w, u, v);
    int as_a=0, as_b=0;
    as_a = 3 && (as_b = 4);
    printf("a = 3 && (b=4) -> a=%d, b=%d\n", as_a, as_b);
    getchar();
 
    /* Slide 30: Statements & Blocks (scope) */
    printf("\n=== Slide 30: Statements & Blocks (scope) ===\n");
    int sum = 0, ba = 5;
    {
        int ba = 10;
        sum += ba;
        printf("Inside block: a=%d, sum=%d\n", ba, sum);
    }
    sum += ba;
    printf("Outside block: a=%d, sum=%d\n", ba, sum);
    getchar();
 
    /* Slides 31�33: math.h demos (no #define; use acos(-1) for pi) */
    printf("\n=== Slides 31�33: math.h demos (link with -lm) ===\n");
    double xval = 43.0;
    double pi = acos(-1.0);
    printf("sqrt(43.0)=%f, cos(2*pi)=%f\n", sqrt(xval), cos(2*pi));
    printf("exp(1)=%f, log(e)=%f, log10(1000)=%f\n", exp(1.0), log(exp(1.0)), log10(1000.0));
    printf("ceil(2.1)=%f, floor(2.9)=%f, fabs(-3.5)=%f\n", ceil(2.1), floor(2.9), fabs(-3.5));
    printf("pow(2,10)=%f, tan(pi/4)=%f\n", pow(2.0, 10.0), tan(pi/4));
    getchar();
 
    /* Slide 34: Triangle area (Heron's formula) */
    printf("\n=== Slide 34: Triangle area (Heron's formula) ===\n");
    double ta=3, tb=4, tc=5;
    double s = (ta + tb + tc) / 2.0;
    double area = sqrt(s * (s - ta) * (s - tb) * (s - tc));
    printf("For sides a=%.2f, b=%.2f, c=%.2f -> area=%.2f\n", ta, tb, tc, area);
    getchar();
 
    /* Slide 35: Practice problems � sample solutions */
    printf("\n=== Slide 35: Practice problems (sample solutions) ===\n");
    int px1=10, py1=20, pz1=31;
    int ssum = px1+py1+pz1;
    double aavg = ssum / 3.0;
    printf("[Sum/Average] x=%d,y=%d,z=%d -> sum=%d, avg=%.2f\n", px1,py1,pz1,ssum,aavg);
 
    double uu=5.0, ff1=1.2, tt=3.0;
    double ss = uu*tt + 0.5*ff1*tt*tt;
    printf("[Motion] u=%.2f, f=%.2f, t=%.2f -> s=%.2f\n", uu,ff1,tt,ss);
 
    double x1=0, y1=0, x2=4, y2=0, x3=0, y3=3;
    double tarea = fabs( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) ) / 2.0;
    printf("[Triangle area (points)] (%.1f,%.1f), (%.1f,%.1f), (%.1f,%.1f) -> area=%.2f\n",
           x1,y1,x2,y2,x3,y3, tarea);
 
    double A=1, B=-5, C=6;
    double disc = B*B - 4*A*C;
    if (disc >= 0) {
        double r1 = (-B + sqrt(disc))/(2*A);
        double r2 = (-B - sqrt(disc))/(2*A);
        printf("[Quadratic] A=%.1f,B=%.1f,C=%.1f -> roots: %.2f, %.2f\n", A,B,C,r1,r2);
    } else {
        printf("[Quadratic] Imaginary roots (discriminant=%.2f)\n", disc);
    }
    getchar();
 
    printf("\nAll demos finished. Goodbye!\n");
    return 0;
}
