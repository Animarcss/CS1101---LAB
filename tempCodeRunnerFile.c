#include <stdio.h>

void read_array(int a[], int n	) {
	printf("\nEnter the array: ");
	for (int i=0;i<n;i++) scanf("%d",a+i); }

int reverse_array(int a[], int n) {
	int b[n/2];
	printf("The reversed array is: ");
	for (int i=0;i<n/2;i++) {
		b[i]=a[n-i-1]; }
	for (int i=0;i<n/2;i++) {
		a[n-i-1]=a[i];
		a[i]=b[i]; } }

void print_array(int *a, int n) {
	for (int i=0;i<n;i++) {
		printf("%d ",a[i]); } }

int main() {
	printf("Enter the size of array: ");
	int n;
	scanf("%d",&n);
	int a[n];
	read_array(a,n);
	reverse_array(a,n);
	print_array(a,n);
	return 0; }