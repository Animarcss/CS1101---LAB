#include <stdio.h>
#include <string.h>



// Example : Unsafe scanf without width specifier
#if 1
int main() {
    char buf[8];
    printf("Enter string: ");
    scanf("%s", buf); // no limit ? overflow
    printf("Input: %s\n", buf);
    return 0;
}
#endif



// Example 1: Writing past end of array
#if 0
int main() {
    char buf[5];
    strcpy(buf, "This is too long!"); // buffer overflow
    printf("%s\n", buf);
    return 0;
}
#endif

// Example 2: Unsafe gets() usage
#if 0
int main() {
    char buf[10];
    printf("Enter input: ");
    gets(buf); // stack smashing if input > 9 chars
    printf("You entered: %s\n", buf);
    return 0;
}
#endif


// Example 4: sprintf without bounds check
#if 0
int main() {
    char buf[10];
    int x = 12345;
    sprintf(buf, "Value: %d", x); // may overflow
    printf("%s\n", buf);
    return 0;
}
#endif
