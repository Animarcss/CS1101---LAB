// 2Darray_DynamicMemory_demos.c
// Toggle exactly ONE block to `#if 1` (leave all others `#if 0`).

#include <stdio.h>
#include <stdlib.h>

/* ----------------------------------------------------------
 * EX1: Print row-major addresses of a 2D array
 * Slide idea: x[i][j] laid out contiguously row-wise.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    int x[3][5];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("&x[%d][%d] = %p\n", i, j, (void*)&x[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX2: Read & print a matrix (two styles)
 * Slide idea: element-wise read; print one-line or row-per-line.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    int row = 3, col = 4;
    int x[3][4];
    // Read
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            scanf("%d", &x[i][j]);
    // One row per line
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
            printf("%d ", x[i][j]);
        printf("\n");
    }
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX3: Matrix addition z = x + y
 * Slide idea: classic double loop addition.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    int n = 3, m = 4;
    int x[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int y[3][4] = {{2,2,2,2},{1,1,1,1},{3,3,3,3}};
    int z[3][4];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            z[i][j] = x[i][j] + y[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%3d ", z[i][j]);
        printf("\n");
    }
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX4: sizeof & pointer arithmetic with 2D array
 * Slide idea: show sizeof(x), x vs x+1, *x vs *x+1, &x vs &x+1.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    int x[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

    // Addresses to visualize strides
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j)
            printf("%p ", (void*)&x[i][j]);
        printf("\n");
    }

    printf("sizeof(x)  = %zu,      x    = %p,   x+1   = %p\n",
           sizeof(x),  (void*)x,     (void*)(x+1));
    printf("sizeof(*x) = %zu,     *x    = %p,  *x+1  = %p\n",
           sizeof(*x), (void*)(*x),  (void*)((*x)+1));
    printf("sizeof(&x) = %zu,     &x    = %p,  &x+1  = %p\n",
           sizeof(&x), (void*)(&x),  (void*)(&x+1));
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX5: In-place transpose (3x3) — CORRECT (upper-triangle only)
 * Slide idea: wrong vs correct; correct uses j = i..n-1 to avoid double swap.
 * ---------------------------------------------------------- */
#if 0
static void transpose3(int a[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = i; j < 3; ++j) {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
}
static void print3(const int a[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) printf("%3d ", a[i][j]);
        printf("\n");
    }
}
int main(void) {
    int m[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    printf("Before:\n"); print3(m);
    transpose3(m);
    printf("After:\n");  print3(m);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX6: Dynamic 2D with ONE malloc (pointer to array) — p
 * Slide idea: int (*p)[COLS]; single allocation; single free.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    enum { ROWS = 3, COLS = 4 };
    int (*p)[COLS] = (int (*)[COLS])malloc(ROWS * COLS * sizeof(int));
    if (!p) return 1;

    int v = 1;
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            p[i][j] = v++;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) printf("%3d ", p[i][j]);
        printf("\n");
    }

    free(p); // single-shot free
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX7: Fully dynamic 2D with int ** — q
 * Slide idea: allocate row headers, then each row; free in reverse.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    int M = 3, N = 5;
    int **q = (int**)malloc(M * sizeof(int*));
    if (!q) return 1;

    for (int i = 0; i < M; ++i) {
        q[i] = (int*)malloc(N * sizeof(int));
        if (!q[i]) return 1;
    }

    // Fill and print
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            q[i][j] = i*10 + j;

    printf("Values:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) printf("%3d ", q[i][j]);
        printf("\n");
    }

    // Addresses to show non-contiguous rows
    printf("\nRow pointers:\n");
    for (int i = 0; i < M; ++i) printf("q[%d]=%p\n", i, (void*)q[i]);

    printf("\nCell addresses:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            printf("&q[%d][%d]=%p  ", i, j, (void*)&q[i][j]);
        printf("\n");
    }

    for (int i = 0; i < M; ++i) free(q[i]);
    free(q);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX8: Fixed rows, variable columns via array-of-pointers r[ROWS]
 * Slide idea: read column sizes and malloc each row accordingly.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    enum { ROWS = 5 };
    int *r[ROWS];
    int cols[ROWS] = {3, 1, 4, 2, 5}; // example column counts
    for (int i = 0; i < ROWS; ++i) {
        r[i] = (int*)malloc(cols[i] * sizeof(int));
        if (!r[i]) return 1;
        for (int j = 0; j < cols[i]; ++j) r[i][j] = (i+1)*100 + j;
    }

    for (int i = 0; i < ROWS; ++i) {
        printf("Row %d (%d cols): ", i, cols[i]);
        for (int j = 0; j < cols[i]; ++j) printf("%d ", r[i][j]);
        printf("\n");
    }

    for (int i = 0; i < ROWS; ++i) free(r[i]);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX9: Helper: allocate(M,N) like in slide; show header & cell addresses
 * Slide idea: separate allocator returning int** and printing addresses.
 * ---------------------------------------------------------- */
#if 0
static int **allocate(int M, int N) {
    int **p = (int**)malloc(M * sizeof(int*));
    if (!p) return NULL;
    // show header addresses
    for (int i = 0; i < M; ++i) printf("%p ", (void*)&p[i]);
    printf("\n");
    for (int i = 0; i < M; ++i) {
        p[i] = (int*)malloc(N * sizeof(int));
        if (!p[i]) return NULL;
    }
    return p;
}
int main(void) {
    int M = 3, N = 4;
    int **p = allocate(M, N);
    if (!p) return 1;

    // show cell addresses
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%p ", (void*)&p[i][j]);
        printf("\n");
    }
    for (int i = 0; i < M; ++i) free(p[i]);
    free(p);
    return 0;
}
#endif

/* ----------------------------------------------------------
 * EX10: “Four types” summary (compiles, shows sizes only)
 * Slide idea: static/static, dynamic/static, static/dynamic, dynamic/dynamic.
 * ---------------------------------------------------------- */
#if 0
int main(void) {
    int a[5][10];                // static rows, static cols
    int (*b)[10];                // dynamic rows, static cols (allocate later)
    int *c[5];                   // static rows, dynamic cols (each c[i] malloc)
    int **d;                     // dynamic rows, dynamic cols

    printf("sizeof(a)=%zu  (5*10 ints)\n", sizeof(a));
    printf("sizeof(b)=%zu  (pointer to 10-int row)\n", sizeof(b));
    printf("sizeof(c)=%zu  (array of 5 int* headers)\n", sizeof(c));
    printf("sizeof(d)=%zu  (pointer to pointer)\n", sizeof(d));
    return 0;
}
#endif
