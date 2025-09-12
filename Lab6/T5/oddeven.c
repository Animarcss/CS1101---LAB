#include <stdio.h>
int main()
{
int size,evenCount=0,oddCount=0;
printf("Enter the size of the array: ");
scanf("%d", &size);
int array[size];
printf("Enter integers one-by-one: \n");
for (int i=0;i<size;i++) {
	scanf("%d",&array[i]); 
	if (array[i]%2==0) evenCount+=1;
	else oddCount+=1; }
int even[evenCount],odd[oddCount];
evenCount=oddCount=0;
for (int i=0;i<size;i++) {
	if (array[i]%2==0) { even[evenCount]=array[i]; evenCount+=1;}
	else { odd[oddCount]=array[i]; oddCount+=1; } }
printf("Even numbers are: ");
for (int i=0;i<evenCount;i++) { printf("%d ",even[i]); }
printf("Odd numbers are: ");
for (int i=0;i<oddCount;i++) { printf("%d ",odd[i]); }
return 0;
}
