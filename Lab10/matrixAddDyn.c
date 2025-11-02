#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void) {
    int *A = malloc(N * N * sizeof(int));
    int *B = malloc(N * N * sizeof(int));
    int *C = malloc(N * N * sizeof(int));

    if (!A || !B || !C) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize and compute C = A + B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i * N + j] = i + j;
            B[i * N + j] = i - j;
            C[i * N + j] = A[i * N + j] + B[i * N + j];
        }
    }

    // Print A
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", A[i * N + j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print B
    printf("Matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", B[i * N + j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print C
    printf("Matrix C = A + B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", C[i * N + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}
