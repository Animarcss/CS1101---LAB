/*
 * Compile: gcc L5_demo.c -lm
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void){
    printf("Loops & Iteration —  L5 demos (\n");
    printf("Follow the prompts. After each demo, press Enter to continue.\n\n");

    /* Utility: we'll reuse 'ch' to clear input and pause between demos */
    int ch;

    /* ====================== [1] while: print line numbers ====================== */
    {
        int i = 1, n;
        printf("[1] WHILE — Print line numbers up to n. Enter n: ");
        if (scanf("%d", &n) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        while (i <= n) {
            printf("Line no : %d\n", i);
            i = i + 1;
        }
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ======================== [2] Input-controlled sum ======================== */
    {
        long long sum = 0;
        long long n;
        printf("\n[2] INPUT-CONTROLLED — Sum non-negative numbers; negative ends.\n");
        printf("Enter a number (negative to stop): ");
        if (scanf("%lld", &n) != 1) { puts("Invalid input"); return 0; }
        while (n >= 0) {
            sum += n;
            printf("Enter a number (negative to stop): ");
            if (scanf("%lld", &n) != 1) { puts("Invalid input"); return 0; }
        }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Sum = %lld\n", sum);
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* =================== [3] Counter-controlled: sum of first N =================== */
    {
        int N, count = 1;
        long long sum = 0;
        printf("\n[3] COUNTER-CONTROLLED — Sum of first N natural numbers. Enter N: ");
        if (scanf("%d", &N) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        while (count <= N) {
            sum = sum + count;
            count = count + 1;
        }
        printf("Sum = %lld\n", sum);
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ===================== [4] Sum of squares (while version) ===================== */
    {
        int N, i = 1;
        long long sumsq = 0;
        printf("\n[4] WHILE — Sum of squares 1^2 + ... + N^2. Enter N: ");
        if (scanf("%d", &N) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        while (i <= N) {
            sumsq += 1LL * i * i;
            ++i;
        }
        printf("Sum of squares = %lld\n", sumsq);
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ====================== [5] GCD using Euclid's algorithm ====================== */
    {
        int A, B, t;
        printf("\n[5] WHILE — GCD (Euclid). Enter A B: ");
        if (scanf("%d%d", &A, &B) != 2) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        if (A == 0 && B == 0) { puts("GCD undefined for (0,0)"); }
        else {
            if (A == 0) { printf("GCD = %d\n", B<0?-B:B); }
            else if (B == 0) { printf("GCD = %d\n", A<0?-A:A); }
            else {
                if (A > B) { t=A; A=B; B=t; }
                /* invariant: B >= A > 0 */
                while (B % A != 0) {
                    t = B % A; B = A; A = t;
                }
                printf("GCD = %d\n", A<0?-A:A);
            }
        }
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ====================== [6] Max of positive stream (input-controlled) ====================== */
    {
        double max = 0.0, x;
        int seen = 0;
        printf("\n[6] INPUT-CONTROLLED — Enter +ve numbers (end with a -ve):\n");
        if (scanf("%lf", &x) != 1) { puts("Invalid input"); return 0; }
        while (x >= 0.0) {
            if (!seen || x > max) { max = x; seen = 1; }
            if (scanf("%lf", &x) != 1) { puts("Invalid input"); return 0; }
        }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        if (seen) printf("Maximum = %.6f\n", max);
        else      printf("No positive numbers were entered.\n");
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ===================== [7] Sum of digits (while over integer) ===================== */
    {
        long long n, sum = 0;
        printf("\n[7] WHILE — Sum of digits. Enter integer n: ");
        if (scanf("%lld", &n) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        long long m = (n < 0) ? -n : n;
        while (m != 0) {
            sum += (m % 10);
            m /= 10;
        }
        printf("Sum of digits of %lld = %lld\n", n, sum);
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* =========================== [8] for: factorial =========================== */
    {
        int n, i;
        long long prod = 1;
        printf("\n[8] FOR — Factorial. Enter n: ");
        if (scanf("%d", &n) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        if (n < 0) puts("Factorial undefined for negative n.");
        else {
            for (i = 1; i <= n; ++i) prod *= i;
            printf("Factorial(%d) = %lld\n", n, prod);
        }
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ================== [9] for: e^x series up to n terms ================== */
    {
        int n, count;
        double x, term = 1.0, sum = 0.0; /* start with 1 (count = 1 will add it) */
        printf("\n[9] FOR — e^x series up to n terms. Enter x then n: ");
        if (scanf("%lf%d", &x, &n) != 2) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        for (count = 1; count <= n; ++count) {
            sum += term;
            term *= x / count;
        }
        printf("Exp(x, n terms) ˜ %.6f\n", sum);
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* =========== [10] do-while: validate month in [1,12] =========== */
    {
        int month;
        printf("\n[10] DO-WHILE — Keep prompting until month in [1,12].\n");
        do {
            printf("Please input month [1-12]: ");
            if (scanf("%d", &month) != 1) { puts("Invalid input"); return 0; }
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        } while (month < 1 || month > 12);
        printf("Accepted month = %d\n", month);
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ================== [11] do-while: decimal ? reverse binary ================== */
    {
        int dec;
        printf("\n[11] DO-WHILE — Decimal to reverse binary. Enter decimal: ");
        if (scanf("%d", &dec) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        if (dec == 0) {
            printf("0\n");
        } else {
            int n = (dec < 0) ? -dec : dec;
            printf("Reverse binary: ");
            do {
                printf("%d", n % 2);
                n /= 2;
            } while (n != 0);
            printf("\n");
        }


        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ===================== [12] do-while: echo until newline ===================== */
    {
        char echo;
        printf("\n[12] DO-WHILE — Echo characters until newline. Type some text then Enter:\n");
        do {
            echo = (char)getchar();
            if (echo == (char)EOF) break;
            putchar(echo);
        } while (echo != '\n');
        printf("Press Enter to continue (if needed)...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* =========================== [13] break example =========================== */
    {
        int fact = 1, i = 1;
        printf("\n[13] BREAK — Smallest i with i! > 100.\n");
        while (i < 20) {
            fact = fact * i;
            if (fact > 100) {
                printf("Factorial of %d exceeds 100 (value=%d)\n", i, fact);
                break; /* exit loop immediately */
            }
            ++i;
        }
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* =========================== [14] Prime check =========================== */
    {
        int n, i = 2, is_composite = 0;
        printf("\n[14] WHILE — Prime test up to sqrt(n). Enter n: ");
        if (scanf("%d", &n) != 1) { puts("Invalid input"); return 0; }
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        if (n < 2) {
            printf("%d is not prime\n", n);
        } else {
            double limit = sqrt((double)n);
            while (i <= (int)limit) {
                if (n % i == 0) { is_composite = 1; break; }
                ++i;
            }
            if (is_composite) printf("%d is not a prime\n", n);
            else              printf("%d is a prime\n", n);
        }
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ========================= [15] continue example ========================= */
    {
        int i;
        printf("\n[15] CONTINUE — Print 1..20 skipping multiples of 3:\n");
        for (i = 1; i <= 20; ++i) {
            if (i % 3 == 0) continue;  /* skip printing */
            printf("%d ", i);
        }
        printf("\nPress Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }


    /* ======================== [17] Nested loops: 2D figures ======================== */
    {
        int ROWS = 3, COLS = 5;
        int row, col;

        printf("\n[17] NESTED LOOPS — Rectangle %dx%d of '*':\n", ROWS, COLS);
        for (row = 1; row <= ROWS; ++row) {
            for (col = 1; col <= COLS; ++col) {
                printf("*");
            }
            printf("\n");
        }

        printf("\nRight triangle of height 5:\n");
        ROWS = 5;
        for (row = 1; row <= ROWS; ++row) {
            for (col = 1; col <= row; ++col) printf("*");
            printf("\n");
        }

        printf("\nRight-aligned triangle of height 5:\n");
        ROWS = 5;
        for (row = 1; row <= ROWS; ++row) {
            for (col = 1; col < row; ++col) printf(" ");
            for (col = 1; col <= ROWS - row + 1; ++col) printf("*");
            printf("\n");
        }

        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* =================== [18] break/continue with nested loops =================== */
    {
        int i, j, hit = 0;
        int low = 2, high = 10, desired = 1; /* example condition: j % i == desired */
        printf("\n[18] NESTED with break/continue — Find first (i,j) in [%d,%d] with j%%i==%d\n",
               low, high, desired);
        for (i = low; i < high; ++i) {
            for (j = i + 1; j <= high; ++j) {
                if (j % i == desired) { hit = 1; break; } /* break inner */
            }
            if (hit) break; /* break outer */
        }
        if (hit) printf("Found i=%d, j=%d\n", i, j);
        else     printf("No pair found\n");
        printf("Press Enter to continue...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    /* ============================ [19] Comma operator ============================ */
    {
        int i, j, sum = 0;
        int N = 5;
        printf("\n[19] COMMA OPERATOR — multiple init/update in 'for'.\n");
        /* Example 1: factorial with multiple init/update (simple) */
        {
            int fact = 1;
            for (fact = 1, i = 1; i <= 5; ++i)
                fact = fact * i;
            printf("  5! = %d\n", fact);
        }
        /* Example 2: sum squares with two indices moving */
        sum = 0;
        j = N; /* not used in formula here—just to show multiple updates */
        for (i = 1, j = N; i <= N; ++i, --j) {
            sum += i * i;
        }
        printf("  Sum of squares 1..%d = %d\n", N, sum);

        printf("Press Enter to finish...");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    puts("\nAll demos done. Goodbye!");
    return 0;
}
