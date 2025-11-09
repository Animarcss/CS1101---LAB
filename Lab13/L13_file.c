

#if 0
/* 1) Create/overwrite a file safely and write a few lines */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fptr = fopen("myfile.dat", "w");  // "w" creates/truncates
    if (fptr == NULL) {
        printf("Error in file creation\n");
        exit(1);
    }
    fprintf(fptr, "First file\n");
    int a = 42, b = 7;
    fprintf(fptr, "%d %d\n", a, b);
    fclose(fptr);
    return 0;
}
#endif


#if 0
/* 2) Read back two integers with fscanf and check result count */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("myfile.dat", "r");
    if (fp == NULL) { perror("myfile.dat"); exit(1); }
    int a, b;
    if (fscanf(fp, "%d%d", &a, &b) == 2)
        printf("Read: a=%d b=%d\n", a, b);
    else
        printf("Could not read two integers.\n");
    fclose(fp);
    return 0;
}
#endif


#if 0
/* 3) Reading ALL integers correctly until EOF (robust pattern) */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) { perror("input.txt"); exit(1); }

    int x, n = 0, sum = 0;
    while (fscanf(fp, "%d", &x) == 1) {      // attempt read; stop when it fails
        ++n; sum += x;
        printf("%d-th integer: %d\n", n, x);
    }
    fclose(fp);
    if (n) printf("Average: %.2f\n", (float)sum/n);
    return 0;
}
#endif


#if 0
/* 4) Read lines safely with fgets()  */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) { perror("input.txt"); exit(1); }

    char buf[1000];
    while (fgets(buf, sizeof buf, fp) != NULL) {
        printf("Line: %s", buf);             // newline kept by fgets()
    }
    fclose(fp);
    return 0;
}
#endif


#if 0
/* 5) Using stdin/stdout/stderr explicitly */
#include <stdio.h>

int main(void) {
    int x;
    fprintf(stdout, "Enter x\n");
    if (fscanf(stdin, "%d", &x) == 1) {
        fprintf(stdout, "x: %d\n", x);
        fprintf(stderr, "No-error\n");
    } else {
        fprintf(stderr, "Input error\n");
    }
    return 0;
}
#endif


#if 0
/* 6) Character I/O � echo and file copy with fgetc/fputc */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // A) echo one character via stdin/stdout
    int c = getchar();
    if (c != EOF) putchar(c);

    // B) copy a file byte-by-byte
    FILE *in = fopen("source.txt", "r");
    if (!in) { perror("source.txt"); exit(1); }
    FILE *out = fopen("copy.txt", "w");
    if (!out) { perror("copy.txt"); fclose(in); exit(1); }

    while ((c = fgetc(in)) != EOF) fputc(c, out);
    fclose(in); fclose(out);
    return 0;
}
#endif


#if 0
/* 7) ftell / fseek demo � in-place overwrite at a byte offset */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // prepare demo file
    FILE *w = fopen("seek_demo.txt", "w");
    if (!w) { perror("seek_demo.txt"); exit(1); }
    fputs("the quick brown fox jumped over the lazy dogs", w);
    fclose(w);

    FILE *fp = fopen("seek_demo.txt", "r+");
    if (!fp) { perror("seek_demo.txt"); exit(1); }

    printf("%ld\n", ftell(fp));            // 0
    fgetc(fp); fgetc(fp);                  // read 2 bytes
    printf("%ld\n", ftell(fp));            // 2
    fseek(fp, 2, SEEK_CUR);                // skip 2 more
    printf("%ld\n", ftell(fp));            // 4
    fputs("fast purple", fp);              // overwrite from byte 4
    printf("%ld\n", ftell(fp));            // new position
    fclose(fp);
    return 0;
}
#endif


#if 0
/* 8) Random access �nth prime� from a fixed-width text file */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("primes.txt", "r");
    if (!fp) { perror("primes.txt"); exit(1); }

    int n, p;
    printf("Which prime (1..1000)? ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) { puts("Out of range."); fclose(fp); return 0; }

    if (n <= 4)         fseek(fp, (n - 1) * 2L, SEEK_SET);
    else if (n <= 25)   fseek(fp, 4L * 2 + (n - 5) * 3L, SEEK_SET);
    else if (n <= 168)  fseek(fp, 4L * 2 + 21L * 3 + (n - 26) * 4L, SEEK_SET);
    else                fseek(fp, 4L * 2 + 21L * 3 + 143L * 4 + (n - 169) * 5L, SEEK_SET);

    fscanf(fp, "%d", &p);
    printf("%d-th prime is %d\n", n, p);
    fclose(fp);
    return 0;
}
#endif


#if 0
/* 9) Copy a file (command-line style: ./a.out <src> <dst>) */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { printf("Usage: %s <src> <dst>\n", argv[0]); return 0; }

    FILE *ifp = fopen(argv[1], "r");
    if (!ifp) { perror(argv[1]); exit(1); }
    FILE *ofp = fopen(argv[2], "w");
    if (!ofp) { perror(argv[2]); fclose(ifp); exit(1); }

    int c;
    while ((c = fgetc(ifp)) != EOF) fputc(c, ofp);
    fclose(ifp); fclose(ofp);
    return 0;
}
#endif


#if 0
/* 10) Fibonacci to TEXT file (human-readable) */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 40, F[41]; F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; ++i) F[i] = F[i-1] + F[i-2];

    FILE *fp = fopen("Fib.txt", "w");
    if (!fp) { perror("Fib.txt"); exit(1); }
    for (int i = 0; i <= n; ++i) fprintf(fp, "%d\n", F[i]);
    fclose(fp);
    return 0;
}
#endif


#if 0
/* 11) Fibonacci to BINARY file, then read back */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 40, F[41]; F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; ++i) F[i] = F[i-1] + F[i-2];

    FILE *wb = fopen("FibB.dat", "wb");
    if (!wb) { perror("FibB.dat"); exit(1); }
    fwrite(F, sizeof(int), 41, wb);
    fclose(wb);

    int R[41] = {0};
    FILE *rb = fopen("FibB.dat", "rb");
    if (!rb) { perror("FibB.dat"); exit(1); }
    fread(R, sizeof(int), 41, rb);
    fclose(rb);

    for (int i = 0; i <= n; ++i) printf("F(%d) = %d\n", i, R[i]);
    return 0;
}
#endif


#if 0
/* 12) Uppercase converter: reads src, writes dst */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { printf("Usage: %s <src> <dst>\n", argv[0]); return 0; }

    FILE *in = fopen(argv[1], "r");  if (!in)  { perror(argv[1]); exit(1); }
    FILE *out = fopen(argv[2], "w"); if (!out) { perror(argv[2]); fclose(in); exit(1); }

    int c;
    while ((c = fgetc(in)) != EOF) fputc(isalpha(c) ? toupper(c) : c, out);
    fclose(in); fclose(out);
    return 0;
}
#endif


#if 0
/* 13) Read a matrix from file and write its transpose back
 * Input format (R C on first line, then R*C ints):
 *   3 2
 *   1 2
 *   3 4
 *   5 6
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("matrix.txt", "r+");
    if (!fp) { perror("matrix.txt"); exit(1); }

    int R, C;
    if (fscanf(fp, "%d %d", &R, &C) != 2) { puts("Bad header"); fclose(fp); exit(1); }

    int *A = (int*)malloc(sizeof(int)*R*C);
    for (int i = 0; i < R*C; ++i) fscanf(fp, "%d", &A[i]);

    int *T = (int*)malloc(sizeof(int)*R*C);
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            T[c*R + r] = A[r*C + c];

    rewind(fp);
    fprintf(fp, "%d %d\n", C, R);
    for (int r = 0; r < C; ++r) {
        for (int c = 0; c < R; ++c) fprintf(fp, "%d ", T[r*R + c]);
        fputc('\n', fp);
    }
    fclose(fp);
    free(A); free(T);
    return 0;
}
#endif


#if 1
/* 14) Tiny demo: I/O redirection (run-time shell feature)
 * Run from your shell (no special code needed):
 *   ./a.out < in.txt > out.txt     // stdout redirected/created
 *   ./a.out < in.txt >> out.txt    // append mode
 */
#include <stdio.h>

int main(void) {
    int x;
    if (scanf("%d", &x) == 1) printf("You typed: %d\n", x);
    return 0;
}
#endif
