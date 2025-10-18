#include <stdio.h>

int findMax(int *arr,int n) {
	int max = *arr;
	for (int i=1;i<n;i++) {
		if (*(arr+i) > max) max=*(arr+i); }
	return max; }

int main() {
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: ",n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("Maximum element: %d\n", findMax(arr,n));
	return 0; }
