#include <stdio.h>
int main()
{
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);
int count,array[size],countedOrNot[size];
for (int i=0;i<size;i++) countedOrNot[i]=0;
printf("Enter the values of the array:\n");
for (int i=0;i<size;i++) scanf("%d",&array[i]);
for (int i=0;i<size;i++) {
	count=0;
	if (countedOrNot[i]==1) continue;
	for (int j=i;j<size;j++) {
		if (array[i]==array[j]) {
			count++;
			countedOrNot[j]=1; } }
	printf("%d occurs %d time(s)\n",array[i],count); }
return 0;
}
