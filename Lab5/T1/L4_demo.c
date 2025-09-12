/*
 
 * Compile: gcc L4_demo.c -lm
 */
 
#include <stdio.h>
#include <ctype.h>
#include <math.h>
 
int main(void){
    puts("\n\nCondition & Branching � consolidated demos \n\n");
    printf("Follow prompts. After each demo, press Enter to continue.\n\n");
 
    /* ========================= [1] Basic if ========================= */
    {
        int marks;
        int ch;
        printf("[1] IF: Enter marks: ");
        if (scanf("%d", &marks) != 1) { puts("Invalid input"); }
        /* clear leftover input */
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if (marks >= 90)
            printf("Passed with distinction (marks >= 90)\n");
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* =================== [2] if-else ladder (grading) =================== */
    {
        int m, ch;
        printf("\n[2] IF-ELSE LADDER: Enter marks: ");
        if (scanf("%d", &m) != 1){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if (m >= 90)         printf("Grade: A\n");
        else if (m >= 80)    printf("Grade: B\n");
        else if (m >= 70)    printf("Grade: C\n");
        else                 printf("failed\n");
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ======================== [3] Max of two ======================== */
    {
        int x, y, ch;
        printf("\n[3] MAX OF TWO: Enter x y: ");
        if (scanf("%d%d", &x, &y) != 2){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if (x > y) printf("Largest is %d\n", x);
        else       printf("Largest is %d\n", y);
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* =================== [4] Min of three (two-step) =================== */
    {
        int x, y, z, min, ch;
        printf("\n[4] MIN OF THREE: Enter x y z: ");
        if (scanf("%d%d%d", &x, &y, &z) != 3){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if (x > y) min = y; else min = x;
        if (z > min) printf("Minimum is %d\n", min);
        else         printf("Minimum is %d\n", z);
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ================ [5] Max of three (independent ifs) ================ */
    {
        int x, y, z, ch;
        printf("\n[5] MAX OF THREE: Enter x y z: ");
        if (scanf("%d%d%d", &x, &y, &z) != 3){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if ((x >= y) && (x >= z)) printf("Max is %d\n", x);
        if ((y >= x) && (y >= z)) printf("Max is %d\n", y);
        if ((z >= y) && (z >= x)) printf("Max is %d\n", z);
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* =================== [6] Dangling else demo =================== */
    {
        int a, b, ch;
        printf("\n[6] DANGLING ELSE: Enter a b: ");
        if (scanf("%d%d", &a, &b) != 2){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        puts("-> WRONG style (else binds to inner if):");
        if (a > 0)
            if (b > 0) puts("Both positive");
            else       puts("b not positive");  /* else pairs with (b > 0) */
 
        puts("-> FIXED with braces :");
        if (a > 0) {
            if (b > 0) puts("Both positive");
        } else {
            puts("a not positive");
        }
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ======================= [7] Ternary ?: ======================= */
    {
        int a, b, ch;
        printf("\n[7] TERNARY ?: Enter a b: ");
        if (scanf("%d%d", &a, &b) != 2){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        /* max via ?: */
        int z = (a > b) ? a : b;
        printf("Max via ?: %d\n", z);
 
        /* pretty printing example */
        int n;
        printf("Enter n for line formatting demo: ");
        if (scanf("%d", &n) != 1){ puts("Invalid n"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        for (int i = 0; i < n; ++i){
            printf("%d", i);
            printf("%c", (i%10==9 || i==n-1) ? '\n' : ' ');
        }
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ========== [8] Assignment (=) vs Equality (==) pitfall ========== */
    {
        int age, ch;
        printf("\n[8] '=' vs '==': Enter age: ");
        if (scanf("%d", &age) != 1){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        puts("Bad check: if (age = 18)  // assigns 18; non-zero => ALWAYS true");
        {
            int tmp = age;
            if ( (tmp = 18) )
                puts("You can cast vote!  (Printed because tmp=18 makes condition true)");
        }
 
        puts("Correct check: if (age == 18)");
        if (age == 18)
            puts("Exactly 18.");
        else
            puts("Not 18.");
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ================ [9] switch: fall-through and case-insensitive ================ */
    {
        int ch;
        char choice;
        printf("\n[9] SWITCH: Enter a single character (r/g/R/G/z): ");
        choice = (char)getchar();
        if (choice == '\n') choice = (char)getchar();
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        puts("-> No breaks (shows fall-through):");
        switch (choice) {
            case 'r': puts("RED");
            case 'g': puts("GREEN");
            default:  puts("OTHER");
        }
 
        puts("-> With breaks (distinct outcomes):");
        switch (choice) {
            case 'r': puts("RED");   break;
            case 'g': puts("GREEN"); break;
            default:  puts("OTHER"); break;
        }
 
        puts("-> Case-insensitive using toupper():");
        switch (toupper((unsigned char)choice)) {
            case 'R': puts("RED");   break;
            case 'G': puts("GREEN"); break;
            default:  puts("OTHER"); break;
        }
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ===================== [10] switch fall-through example ===================== */
    {
        int x, ch;
        printf("\n[10] SWITCH BREAK EXAMPLE: Enter an integer: ");
        if (scanf("%d", &x) != 1){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        switch (x) {
            case 1: printf("One\n");
            case 2: printf("Two\n");
            default: printf("Not one or two\n");
        }
        puts("(Above shows fall-through without breaks.)");
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* =================== [11] Second maximum of three =================== */
    {
        int x, y, z, fmax, smax, ch;
        printf("\n[11] SECOND MAX OF THREE: Enter x y z: ");
        if (scanf("%d%d%d", &x, &y, &z) != 3){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if (x > y) { fmax = x; smax = y; }
        else       { fmax = y; smax = x; }
 
        if (z > fmax)      smax = fmax;
        else if (z > smax) smax = z;
 
        printf("Second max = %d\n", smax);
 
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    /* ==================== [12] Quadratic roots classifier ==================== */
    {
        double a,b,c;
        int ch;
        printf("\n[12] QUADRATIC ROOTS (ax^2+bx+c=0): Enter a b c: ");
        if (scanf("%lf%lf%lf", &a, &b, &c) != 3){ puts("Invalid input"); }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
 
        if (a == 0.0){
            puts("Not quadratic. Falling back to linear:");
            if (b == 0.0){
                puts(c == 0.0 ? "Infinitely many solutions" : "No solution");
            } else {
                printf("x = %.6f\n", -c/b);
            }
        } else {
            double D = b*b - 4*a*c;
            if (D > 0){
                double r1 = (-b + sqrt(D)) / (2*a);
                double r2 = (-b - sqrt(D)) / (2*a);
                printf("Real and distinct: x1 = %.6f, x2 = %.6f\n", r1, r2);
            } else if (D == 0){
                double r = (-b) / (2*a);
                printf("Real and equal: x = %.6f\n", r);
            } else {
                double real = (-b) / (2*a);
                double imag = sqrt(-D) / (2*a);
                printf("Complex: x1 = %.6f + i%.6f, x2 = %.6f - i%.6f\n", real, imag, real, imag);
            }
        }
 
        printf("Press Enter to finish...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
 
    puts("\nAll demos done. Goodbye!");
    return 0;
}
