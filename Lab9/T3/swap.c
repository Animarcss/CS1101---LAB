#include <stdio.h>
void swapArrays(int *arr1,int *arr2,int n) {
	for (int i=0;i<n;i++) {
		int temp=*(arr1+i);
		*(arr1+i)=*(arr2+i);
		*(arr2+i)=temp; } }

int main() {
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr1[n],arr2[n];
	printf("Enter %d elements of first array: ",n);
	for (int i=0;i<n;i++) scanf("%d",&arr1[i]);
	printf("Enter %d elements of second array: ",n);
	for (int i=0;i<n;i++) scanf("%d",&arr2[i]);
	printf("Arrays before swapping:\nArray 1: ");
	for (int i=0;i<n;i++) printf("%d ",arr1[i]);
	printf("\nArray 2: ");
	for (int i=0;i<n;i++) printf("%d ",arr2[i]);
	swapArrays(arr1,arr2,n);
	printf("\nArrays after swapping:\nArray 1: ");
	for (int i=0;i<n;i++) printf("%d ",arr1[i]);
	printf("\nArray 2: ");
	for (int i=0;i<n;i++) printf("%d ",arr2[i]);
	puts("");
	return 0; }
