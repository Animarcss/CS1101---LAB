#include <stdio.h>
#include <math.h>
 
/* ---------- Utilities (no pointers) ---------- */
 
/* (a) Sum of digits (works for negatives too) */
long long sum_of_digits(long long n) {
    if (n < 0) n = -n;
    long long s = 0;
    while (n) { s += n % 10; n /= 10; }
    return s;
}
 
/* (b) Primality */
int is_prime(long long n) {
    if (n < 2) return 0;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
 
/* Simple insertion sort (ascending). Works on a VLA; no qsort, no pointers. */
void sort_array(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
 
/* (c) Stats */
double mean(int a[], int n) {
    long long s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return (double)s / n;
}
 
double median(int a[], int n) {
    /* Make a local copy on the stack; no malloc */
    int b[n];
    for (int i = 0; i < n; i++) b[i] = a[i];
    sort_array(b, n);
    if (n % 2) return (double)b[n / 2];
    return 0.5 * (b[n / 2 - 1] + b[n / 2]);
}
 
/* Return both mode value and frequency without out-params */
typedef struct { int value; int freq; } Mode;
 
Mode mode(int a[], int n) {
    int b[n];
    for (int i = 0; i < n; i++) b[i] = a[i];
    sort_array(b, n);
 
    int best_val = b[0], best_cnt = 1;
    int cur_val = b[0], cur_cnt = 1;
 
    for (int i = 1; i < n; i++) {
        if (b[i] == cur_val) {
            cur_cnt++;
        } else {
            if (cur_cnt > best_cnt || (cur_cnt == best_cnt && cur_val < best_val)) {
                best_cnt = cur_cnt;
                best_val = cur_val;
            }
            cur_val = b[i];
            cur_cnt = 1;
        }
    }
    if (cur_cnt > best_cnt || (cur_cnt == best_cnt && cur_val < best_val)) {
        best_cnt = cur_cnt;
        best_val = cur_val;
    }
    Mode m = { best_val, best_cnt };
    return m;
}
 
double stddev(int a[], int n) {
    /* population stddev */
    double m = mean(a, n), acc = 0.0;
    for (int i = 0; i < n; i++) {
        double d = a[i] - m;
        acc += d * d;
    }
    return sqrt(acc / n);
}
 
/* (d) Membership */
int index_of(int a[], int n, int key) {
    for (int i = 0; i < n; i++) if (a[i] == key) return i;
    return -1;
}
 
/* (e) Binary (32-bit print) */
void print_binary_unsigned(unsigned x) {
    char s[33]; s[32] = '\0';
    for (int i = 31; i >= 0; i--) s[31 - i] = (x & (1u << i)) ? '1' : '0';
    printf("%s\n", s);
}
 
int main(void) {
    int choice;
    for (;;) {
        puts("\n=== MENU ===");
        puts("1) Sum of digits");
        puts("2) Primality check");
        puts("3) Mean/Median/Mode/StdDev of array");
        puts("4) Search number in array");
        puts("5) Integer to binary");
        puts("0) Exit");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) return 0;
 
        if (choice == 0) break;
 
        if (choice == 1) {
            long long n;
            printf("Enter integer: "); scanf("%lld", &n);
            printf("Sum of digits = %lld\n", sum_of_digits(n));
        }
        else if (choice == 2) {
            long long n;
            printf("Enter integer >= 0: "); scanf("%lld", &n);
            printf("%lld is %s\n", n, is_prime(n) ? "prime" : "not prime");
        }
        else if (choice == 3) {
            int n; printf("Enter n (1..1000): "); scanf("%d", &n);
            if (n < 1 || n > 1000) { puts("Invalid n"); continue; }
            int a[n];                             /* VLA on stack */
            printf("Enter %d integers: ", n);
            for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
            Mode m = mode(a, n);
            printf("Mean   = %.6f\n", mean(a, n));
            printf("Median = %.6f\n", median(a, n));
            printf("Mode   = %d (freq %d)\n", m.value, m.freq);
            printf("StdDev = %.6f\n", stddev(a, n));
        }
        else if (choice == 4) {
            int n; printf("Enter n (1..1000): "); scanf("%d", &n);
            if (n < 1 || n > 1000) { puts("Invalid n"); continue; }
            int a[n];                             /* VLA on stack */
            printf("Enter %d integers: ", n);
            for (int i = 0; i < n; i++) scanf("%d", &a[i]);
            int key; printf("Enter key: "); scanf("%d", &key);
            int idx = index_of(a, n, key);
            if (idx == -1) printf("%d not found\n", key);
            else           printf("%d found at index %d\n", key, idx);
        }
        else if (choice == 5) {
            int x; printf("Enter integer: "); scanf("%d", &x);
            printf("Binary (32-bit two's complement of %d):\n", x);
            print_binary_unsigned((unsigned)x);
        }
        else {
            puts("Invalid choice.");
        }
    }
    return 0;
}
