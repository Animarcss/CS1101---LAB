#include <stdio.h>
 
int main() {
    int i;
 
    // === 1. Declaring and initializing arrays ===
    int numbers[5] = {10, 20, 30, 40, 50};
   // int numbers[5];
    printf("Array Initialization Demo:\n");
    for (i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    for (i = 0; i < 5; i++) {
    printf("address = %p\n",  numbers+i);
	}
    getchar();
 
    // === 2. Reading into an array and printing ===
    int data[5];
    printf("\nEnter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &data[i]);
    }
    printf("You entered:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    getchar(); getchar();  // flush newline and pause
 
    // === 3. Reverse printing ===
    printf("\nPrinting numbers in reverse:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", data[i]);
    }
    printf("\n");
    getchar();
 
    // === 4. Sum and Average ===
    int sum = 0;
    for (i = 0; i < 5; i++) {
        sum += data[i];
    }
    printf("\nSum = %d, Average = %.2f\n", sum, (float)sum / 5);
    getchar();
 
    // === 5. Finding Minimum ===
    int min = data[0];
    for (i = 1; i < 5; i++) {
        if (data[i] < min)
            min = data[i];
    }
    printf("\nMinimum value = %d\n", min);
    getchar();
 
    // === 6. Copying arrays ===
    int copy[5];
    for (i = 0; i < 5; i++) {
        copy[i] = data[i];
    }
    printf("\nCopied array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", copy[i]);
    }
    printf("\n");
    getchar();
 
    // === 7. Address of array elements ===
    printf("\nAddresses of array elements:\n");
    for (i = 0; i < 5; i++) {
        printf("&data[%d] = %p\n", i, &data[i]);
    }
    getchar();
 
    // === 8. Small practice: find max ===
    int max = data[0];
    for (i = 1; i < 5; i++) {
        if (data[i] > max)
            max = data[i];
    }
    printf("\nMaximum value = %d\n", max);
 
    return 0;
}
