#include <stdio.h>

float a;
float b;
float c;
float d;

int main() {

	printf("\nHello, World! This is Parth's C program to evaluate the product of two complex numbers. (2501CT27\n\n)");
	printf("Enter the real and imaginary part of the FIRST complex number:\n");
	scanf("%f %f", &a, &b);
	printf("Enter the real and imaginary part of the SECOND complex number:\n");
	scanf("%f %f", &c, &d);
	float real = (a * c) - (b * d);
	float img = (a * d) + (b * c);

		printf("\n\nThe product of the two complex numbers is %f + %fi.\n\n", real, img);
return 0;
}
