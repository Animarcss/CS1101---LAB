#include <stdio.h>

int main()
{
	int num, i, j, k;
	printf("Enter the number of rows you want the Number Pyramid to comprise of: ");
	if (scanf("%d", &num)!=1) {puts("Invalid input"); return 0;}
	for (i=1; i<=num; ++i) {
		for (j=num-i; j>=1; --j) {
			printf(" "); }
		for (k=1; k<=i; ++k) {
			printf("%d ", k); }
		printf("\n"); }
	printf("\n\nDone!\n\n");
	return 0;
}
