/*
 * pitfalls_arrays.c
 
 */
 
#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    // 1. Out-of-Bounds Access
    printf("1. Out-of-Bounds Access:\n");
    int arr1[5] = {1, 2, 3, 4, 5};
    printf("arr1[4] = %d (valid)\n", arr1[4]);
    printf("arr1[5] = %d (? out-of-bounds, undefined)\n", arr1[5]); // UB
    getchar();
 
    // 2. Uninitialized Arrays
    printf("\n2. Uninitialized Arrays:\n");
    int arr2[5]; // not initialized
    for (int i = 0; i < 5; i++)
        printf("arr2[%d] = %d (garbage)\n", i, arr2[i]);
    getchar();
 
    // 3. Wrong loop bounds
    printf("\n3. Wrong loop bounds:\n");
    int arr3[100] = {1,2,3,4,5};
    int n = 5; // only first 5 elements valid
    printf("Printing with wrong bound (100):\n");
    for (int i = 0; i < 100; i++)   // ? prints unused/garbage
        printf("%d ", arr3[i]);
    printf("\nCorrect (n=5):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr3[i]);
    printf("\n");
    getchar();
 
    // 4. Assignment between arrays
    printf("\n4. Assignment between arrays:\n");
    int a[3] = {1,2,3}, b[3] = {4,5,6};
    // a = b; // ? not allowed
    for (int i = 0; i < 3; i++) a[i] = b[i]; // ? correct
    printf("a after copying: %d %d %d\n", a[0], a[1], a[2]);
    getchar();
 
    // 5. Comparison between arrays
    printf("\n5. Comparison between arrays:\n");
    int x[3] = {1,2,3}, y[3] = {1,2,3};
    if (x == y)  // ? compares addresses
        printf("x == y (address compare)\n");
    else
        printf("x != y (address compare)\n");
    int equal = 1;
    for (int i=0; i<3; i++) if (x[i] != y[i]) { equal=0; break; }
    printf("Element-wise compare: %s\n", equal ? "Equal" : "Not Equal");
    getchar();
 
    // 6. Forgetting & in scanf
    printf("\n6. Forgetting & in scanf:\n");
    int val[1];
    // scanf("%d", val[0]); // ? wrong, crashes
    printf("Correct: scanf(\"%%d\", &val[0]);\n");
    getchar();
 
    // 7. Array decays into pointer
    printf("\n7. Array decays into pointer:\n");
    int z[10];
    printf("sizeof(z) in main = %lu\n", sizeof(z));
    // in function call, array becomes pointer
    // sizeof lost (cannot demo inline here)
    getchar();
 
    // 8. Variable Length Array (VLA)
    printf("\n8. Variable Length Array (VLA):\n");
    int n2;
    printf("Enter array size (try very large): ");
    scanf("%d", &n2);
    int vla[n2]; // may cause stack overflow if n2 huge
    vla[0] = 42;
    printf("vla[0] = %d\n", vla[0]);
    getchar();
 
    // 9. String Handling Pitfall
    printf("\n9. String handling pitfall:\n");
    char name[4] = "John"; // ? no space for '\0'
    printf("name = %s (may overrun)\n", name);
    char name2[5] = "John"; // ? correct
    printf("name2 = %s\n", name2);
    getchar();
 
    // 10. Memory Overlap
    printf("\n10. Memory Overlap:\n");
    int arr4[3] = {1,2,3};
    int other = 99;
    arr4[3] = 500; // ? writes past array end, may overwrite other
    printf("other = %d (may be corrupted!)\n", other);
    getchar();
 
    printf("\n=== End of Pitfalls Demo ===\n");
    return 0;
}
