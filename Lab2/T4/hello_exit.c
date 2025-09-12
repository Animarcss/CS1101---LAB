#include<stdio.h>
int main()
{	printf("Hello, World!\n");

	int choice;
	printf("Enter return code (0 for success, non-zero for error): ");
	scanf("%d", &choice);

	return choice; //send this back to the OS
}
