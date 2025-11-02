#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

// Function to add two complex numbers
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Function to divide two complex numbers
Complex divide(Complex a, Complex b) {
    Complex result;
    float denominator = b.real * b.real + b.imag * b.imag;

    if (denominator == 0) {
        printf("Error: Division by zero!\n");
        result.real = result.imag = 0;
        return result;
    }

    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

// Function to display a complex number
void display(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main() {
    Complex c1, c2, result;
    int choice;

    printf("Enter first complex number (real and imaginary): ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter second complex number (real and imaginary): ");
    scanf("%f %f", &c2.real, &c2.imag);

    printf("\nChoose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = add(c1, c2);
            printf("Result of Addition: ");
            display(result);
            break;
        case 2:
            result = subtract(c1, c2);
            printf("Result of Subtraction: ");
            display(result);
            break;
        case 3:
            result = multiply(c1, c2);
            printf("Result of Multiplication: ");
            display(result);
            break;
        case 4:
            result = divide(c1, c2);
            printf("Result of Division: ");
            display(result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
