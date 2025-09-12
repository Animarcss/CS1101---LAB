#include <stdio.h>
#include <math.h>

int main() {
int choice, num;

do {
	printf("\n\n==== Menu for Mathematical Operations ====\n\n");
	printf("1. Multiplication Table\n2. Even Numbers upto N\n3. Factorial of a Number\n4. Exit\n\n");
	printf("Enter your choice number: ");
	if (scanf("%d",&choice)!=1) { puts("Invalid input"); }
	switch (choice) {
		case 1:
			printf("Enter the number you want the multiplication table of: ");
			if (scanf("%d",&num)!=1) {puts("Invalid input");}
			printf("\n");
			int i;
			for (i=1; i<=10; ++i) {
				printf("%d x %d = %d\n", num, i, num*i); }
			break;
		case 2:
			printf("Enter the number you want to get all the even numbers upto: ");
			if (scanf("%d",&num)!=1) {puts("Invalid input");}
			printf("\n");
			int j=0;
			while (j<=num) {
				printf("%d\n", j);
				j+=2; }
			break;
		case 3:
			printf("Enter the number you want the factorial of: ");
			if (scanf("%d",&num)!=1) {puts("Invalid input");}
			if (num==0) { printf("\n0! is 1.\n"); }
			else {
			printf("\n");
			int k,fac=1;
			for (k=1; k<=num; ++k) {
				fac*=k; }
			printf("\n%d! is %d.\n", num, fac); }
			break;
		case 4:
			printf("\nExiting the program...\n\n");
			break;
		default:
			printf("Invalid choice");
			}
	} while (choice!=4);
return 0;
}
