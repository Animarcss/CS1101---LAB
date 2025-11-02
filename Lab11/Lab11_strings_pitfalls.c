// string_pitfalls.c


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
#if 0
    // 1. Forgetting the null terminator
    char str[5] = {'h','e','l','l','o'}; // no '\0'
    printf("String without null terminator: %s\n", str); // UB
#endif

#if 0
    // 2. Array too small (missing space for '\0')
    char str[5] = "hello"; // UB: needs 6
    printf("%s\n", str);
#endif

#if 0
    // 3. Modifying string literals
    char *p = "hello";   // points to read-only memory
    p[0] = 'H';          // UB: may crash
    printf("%s\n", p);
#endif

#if 0
    // 4. Using gets() (removed from C11)
    char buf[10];
    printf("Enter string: ");
    // gets(buf); // DANGEROUS, buffer overflow possible
    // Correct: fgets(buf, sizeof(buf), stdin);
#endif

#if 0
    // 5. Confusing sizeof and strlen
    char str[] = "hello";
    printf("sizeof(str) = %zu\n", sizeof(str)); // 6
    printf("strlen(str) = %zu\n", strlen(str)); // 5
#endif

#if 0
    // 6. Forgetting to null-terminate
    char src[] = "hello";
    char dst[3];
    strncpy(dst, src, 3); // does not add '\0'
    printf("Copied string: %s\n", dst); // UB
#endif

#if 0
    // 7. Buffer overflow with scanf("%s")
    char buf[5];
    printf("Enter string (try longer than 4 chars): ");
    scanf("%s", buf); // UB if >4 chars
    printf("%s\n", buf);
#endif

#if 0
    // 8. Pointers vs arrays
    char arr[] = "hello";  // writable
    arr[0] = 'H';          // ok
    printf("%s\n", arr);

    char *ptr = "hello";   // read-only
    ptr[0] = 'H';          // UB
#endif

#if 0
    // 9. Comparing strings with ==
    char a[] = "hello";
    char b[] = "hello";
    if (a == b) // compares addresses, not contents
        printf("Equal\n");
    else
        printf("Not equal\n");
    // Correct: strcmp(a,b)==0
#endif

#if 0
    // 10. Char vs string literal
    char c = 'a';   // a single char
    char s[] = "a"; // array with 'a' and '\0'
    printf("c = %c, s = %s\n", c, s);
#endif

    return 0;
}
