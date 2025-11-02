/* strings_examples.c
  * All examples are small and self-contained, mirroring topics in the slide.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


 int my_strlen(const char *s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

 bool is_pal(const char *s) {
    int L = 0, R = my_strlen(s) - 1;
    while (L < R) {
        if (s[L] != s[R]) return false;
        L++; R--;
    }
    return true;
}

/* ============================================================
 * read a single word with scanf %s
 * ============================================================ */
#if 0
int main(void) {
    char str[100];
    scanf("%99s", str);          /* safer: limit width */
    printf("str = %s\n", str);
    return 0;
}
#endif

/* ============================================================
 * EX_STRLEN_MANUAL: manual length (no whitespace in input)
 * ============================================================ */
#if 0
int main(void) {
    char str[100];
    int i, len = 0;
    scanf("%99s", str);
    for (i = 0; str[i] != '\0'; i++) len++;
    printf("str = %s\n", str);
    printf("len = %d\n", len);
    return 0;
}
#endif

/* ============================================================
 *  count occurrences of 'a'
 * ============================================================ */
#if 0
int main(void) {
    char str[100];
    int i, count = 0;
    scanf("%99s", str);
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == 'a')
            count++;
    printf("str = %s\n", str);
    printf("count(a) = %d\n", count);
    return 0;
}
#endif

/* ============================================================
 *  check palindrome (word input)
 * ============================================================ */
#if defined(EX_PALINDROME)
int main(void) {
    char str[100];
    scanf("%99s", str);
    if (is_pal(str)) printf("%s is a palindrome\n", str);
    else             printf("%s is not a palindrome\n", str);
    return 0;
}
#endif

/* ============================================================
 *  count each vowel (lowercase)
 * ============================================================ */
#if defined(EX_VOWELS)
int main(void) {
    char str[100];
    const char vowels[5] = {'a','e','i','o','u'};
    int counts[5] = {0,0,0,0,0};
    scanf("%99s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[i] == vowels[j]) counts[j]++;
        }
    }
    for (int j = 0; j < 5; j++) {
        printf("%c appears %d times\n", vowels[j], counts[j]);
    }
    return 0;
}
#endif

/* ============================================================
 *  read a full line incl. spaces with getchar()
 * ============================================================ */
#if 0
int main(void) {
    char str[100];
    int c = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (c < (int)sizeof(str) - 1) {
            str[c++] = (char)ch;
        }
        /* else: could track overflow and handle as needed */
    }
    str[c] = '\0';
    printf("line: \"%s\"\n", str);
    return 0;
}
#endif

/* ============================================================
 *   read a full line with fgets (safer, simpler)
 * ============================================================ */
#if 0
int main(void) {
    char str[100];
    if (fgets(str, sizeof(str), stdin)) {
        /* strip trailing '\n' if present */
        size_t n = strlen(str);
        if (n && str[n-1] == '\n') str[n-1] = '\0';
        printf("line: \"%s\"\n", str);
    }
    return 0;
}
#endif

/* ============================================================
 *  remove all duplicate characters (keep first occurrences)
 * e.g., "mississippi" -> "misp"
 * ============================================================ */
#if 0
void remDuplicates(char str[]) {
    int idx = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) break;
        }
        if (i == j) {
            str[idx++] = str[i];
        }
    }
    str[idx] = '\0';
}
int main(void) {
    char s[200];
    scanf("%199s", s);
    remDuplicates(s);
    printf("%s\n", s);
    return 0;
}
#endif

/* ============================================================
 * Eremove consecutive duplicates only
 * e.g., "mississippi" -> "misisipi"
 * ============================================================ */
#if 0
static void remConsecDuplicates(char str[]) {
    int idx = 0;
    char prev = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != prev) {
            str[idx++] = str[i];
            prev = str[i];
        }
    }
    str[idx] = '\0';
}
int main(void) {
    char s[200];
    scanf("%199s", s);
    remConsecDuplicates(s);
    printf("%s\n", s);
    return 0;
}
#endif

/* ============================================================
 * EX_COPY_RECURSION: copy string recursively
 * ============================================================ */
#if 0
static void copy_rec(const char *src, char *dest, int idx) {
    dest[idx] = src[idx];
    if (src[idx] == '\0') return;
    copy_rec(src, dest, idx + 1);
}
int main(void) {
    char a[20] = "abcde", b[20];
    copy_rec(a, b, 0);
    printf("%s\n", b);
    return 0;
}
#endif

/* ============================================================
 *  strlen, strcmp, strcat, strcpy
 * ============================================================ */
#if 0
int main(void) {
    char x[20], y[20];
    if (scanf("%19s%19s", x, y) != 2) return 0;
    printf("lenx=%zu leny=%zu\n", strlen(x), strlen(y));
    int val = strcmp(x, y);
    if (val == 0) printf("Same\n");
    else if (val < 0) printf("%s < %s\n", x, y);
    else             printf("%s < %s\n", y, x);

    char a[] = "IIT";
    char b[32] = "Patna ";
    strcat(b, a);               /* ensure b is large enough */
    printf("concat: %s\n", b);

    char z[20];
    strcpy(z, "Ayesha");        /* ensure z is large enough */
    printf("copied: %s\n", z);
    return 0;
}
#endif

/* ============================================================
 *  demonstrate width limit for scanf %s
 * ============================================================ */
#if 0
int main(void) {
    char small[6];              /* can hold up to 5 chars + '\0' */
    scanf("%5s", small);        /* protects against overflow */
    printf("[%s]\n", small);
    return 0;
}
#endif

/* ============================================================
 * REVERSE_STRING  reverse in place
 * ============================================================ */
#if 0
static void reverse_in_place(char *s) {
    int L = 0, R = my_strlen(s) - 1;
    while (L < R) {
        char t = s[L]; s[L] = s[R]; s[R] = t;
        L++; R--;
    }
}
int main(void) {
    char s[200];
    scanf("%199s", s);
    reverse_in_place(s);
    printf("%s\n", s);
    return 0;
}
#endif

/* ============================================================
 *  count words in a full line
 * (words are runs of non-space characters)-A word is defined as a continuous sequence
 * ============================================================ */
#if 0
int main(void) {
    char line[256];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    int count = 0, in_word = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (!isspace((unsigned char)line[i])) {
            if (!in_word) { count++; in_word = 1; }
        } else {
            in_word = 0;
        }
    }
    printf("words = %d\n", count);
    return 0;
}
#endif

/* ============================================================
 * EX_SUBSTRING_SEARCH  naive strstr
 * ============================================================ */
#if 0
static int find_substr(const char *hay, const char *needle) {
    int n = my_strlen(hay), m = my_strlen(needle);
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
        int j = 0;
        while (j < m && hay[i + j] == needle[j]) j++;
        if (j == m) return i;   /* found at i */
    }
    return -1;
}
int main(void) {
    char hay[256], needle[128];
    scanf("%255s %127s", hay, needle);
    int pos = find_substr(hay, needle);
    if (pos >= 0) printf("found at %d\n", pos);
    else          printf("not found\n");
    return 0;
}
#endif

/* ============================================================
 * EX_TOLOWER_TOUPPER
 * ============================================================ */
#if 0
int main(void) {
    char s[200];
    scanf("%199s", s);
    for (int i = 0; s[i] != '\0'; i++) s[i] = tolower((unsigned char)s[i]);
    printf("lower: %s\n", s);
    for (int i = 0; s[i] != '\0'; i++) s[i] = toupper((unsigned char)s[i]);
    printf("upper: %s\n", s);
    return 0;
}
#endif
