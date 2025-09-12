/*
 * format_specifier_switch.c

 * Compile: gcc  L5_FormatSwitch_Tut.c
 */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int main(void) {
    int choice;
    int ch; /* buffer clear */

    int i = -42;
    unsigned int u = 42u;
    double d = 123.456;
    char c = 'A';

    do {
        printf("\n=== FORMAT SPECIFIER TUTORIAL MENU ===\n");
        printf("1. %%d / %%i   (signed int)\n");
        printf("2. %%u / %%o / %%x / %%X (unsigned int in different bases)\n");
        printf("3. %%c (character)\n");
        printf("4. %%f / %%e / %%E / %%g / %%G (floating point)\n");
        printf("5. %%lld / %%llu (long long)\n");
        printf("6. %%Lf (long double)\n");
        printf("7. %%zu / %%td / %%jd (size_t, ptrdiff_t, intmax_t)\n");
        printf("8. %%%% (literal percent)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            puts("Invalid input. Exiting.");
            return 0;
        }
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        switch (choice) {
            case 1:
                printf("Demo %%d : %d\n", i);
                printf("Demo %%i : %i\n", i);
                break;

            case 2:
                printf("Demo %%u (unsigned decimal): %u\n", u);
                printf("Demo %%o (octal): %o\n", u);
                printf("Demo %%x (hex lowercase): %x\n", u);
                printf("Demo %%X (hex uppercase): %X\n", u);
                break;

            case 3:
                printf("Demo %%c (char): %c\n", c);
                break;

            case 4:
                printf("Demo %%f (fixed)   : %f\n", d);
                printf("Demo %%e (sci)     : %e\n", d);
                printf("Demo %%E (sci, up) : %E\n", d);
                printf("Demo %%g (compact) : %g\n", d);
                printf("Demo %%G (compact) : %G\n", d);
                break;

            case 5: {
                long long ll = -1234567890123LL;
                unsigned long long ull = 12345678901234567890ULL;
                printf("Demo %%lld : %lld\n", ll);
                printf("Demo %%llu : %llu\n", ull);
                break;
            }

            case 6: {
                long double ld = 3.141592653589793238L;
                printf("Demo %%Lf (long double): %Lf\n", ld);
                break;
            }

            case 7: {
                size_t z = sizeof(double);
                printf("Demo %%zu (size_t): %zu\n", z);

                break;
            }

            case 8:
                printf("Demo %%%% prints a percent sign: 100%% complete\n");
                break;

            case 0:
                puts("Exiting tutorial.");
                break;

            default:
                puts("Invalid choice.");
        }
    } while (choice != 0);

    return 0;
}
