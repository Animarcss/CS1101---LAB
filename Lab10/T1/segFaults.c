/* segfault_examples.c
 gcc -g segFaults.c
 gdb ./a.out to run
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -----------------------------
 * Example 1: NULL dereference
 * -----------------------------
 */
#if 0
int main(void) {
    int *p = NULL;
    /* Write through NULL -> SIGSEGV on practically every modern OS */
    *p = 123;
    printf("wrote to p: %d\n", *p);
    return 0;
}
#endif

/* -----------------------------
 * Example 2: Buffer overflow (stack)
 * -----------------------------
 * Copies a longer string into a small local buffer using strcpy.
 * This demonstrates corruption of stack memory and often causes a crash.
 * -----------------------------
 */
#if 0
int main(void) {
    char buf[8];
    const char *s = "THIS_STRING_IS_WAY_TOO_LONG"; /* > 8 bytes */
    /* unsafe copy -> overflow buf */
    strcpy(buf, s);
    /* Attempt to use buf after overflow - behavior undefined */
    printf("buf = %s\n", buf);
    return 0;
}
#endif

/* -----------------------------
 * Example 3: Use-after-free
 * -----------------------------
 * Free memory and then dereference the freed pointer.
 * Often causes a crash but may sometimes appear to "work" due to reused memory.
 * -----------------------------
 */
#if 0
int main(void) {
    char *p = malloc(16);
    if (!p) return 1;
    strcpy(p, "hello");
    free(p);
    /* Use-after-free: undefined behavior; may SIGSEGV */
    printf("after free: p[0] = %c\n", p[0]);
    return 0;
}
#endif

/* -----------------------------
 * Example 4: Stack overflow via runaway recursion
 * -----------------------------
 * Infinite recursion will eventually exhaust the stack -> crash.
 * -----------------------------
 */
#if 1
int recurse(int n) {

     int x = n;
     return 1 + recurse(n + 1);
}

int main(void) {

    recurse(0);
    return 0;
}
#endif

/* -----------------------------
 * Example 5: Wild pointer (uninitialized) dereference
 * -----------------------------
 * Using an uninitialized pointer commonly causes a crash.
 * -----------------------------
 */
#if 0
int main(void) {
    int *p; /* uninitialized */
    /* Dereferencing an indeterminate pointer -> undefined; likely crash */
    *p = 10;
    printf("p = %d\n", *p);
    return 0;
}
#endif

/* -----------------------------
 * Example 6: Read past end of static array (heap/stack)
 * -----------------------------
 * Sequential read beyond array bounds - may crash or show odd values.
 * -----------------------------
 */
#if 0
int main(void) {
    int arr[3] = {1, 2, 3};
    /* Intentionally go one past the end: arr[3] is out of bounds */
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]); /* arr[3], arr[4] => UB */
    }
    return 0;
}
#endif
