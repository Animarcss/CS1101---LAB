#include <stdio.h>
int main()
{
int A,B,temp;
printf("Enter two positive integers A and B: ");
scanf("%d %d", &A,&B);
if (A>B) { temp=B; B=A; A=temp; }
if (A<=1) A=2;
if (B>1) {
	printf("\nPrimes numbers in range [A,B] are:\n\n");
	int isPrime=1;
	for (int i=A;i<=B;i++) {
		isPrime=1;
		for (int j=2;j<i;j++) {
			if (i%j==0) { isPrime=0; break; } }
		if (isPrime==1) printf("%d\n",i); } }
else printf("Invalid input. Positive integers needed.");
return 0;
}
