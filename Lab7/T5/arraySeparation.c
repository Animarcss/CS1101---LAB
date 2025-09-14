#include <stdio.h>

void sepOdd(int *a, int n) {
	printf("\nOdd numbers: ");
	for (int i=0;i<n;i++) {
		if (a[i]%2==1) printf("%d ",a[i]); } }

void sepEven(int *a, int n) {
	printf("\nEven numbers: ");
	for (int i=0;i<n;i++) {
		if (a[i]%2==0) printf("%d ",a[i]); } }

void sepNeg(int *a, int n) {
	printf("\nNegative numbers: ");
	for (int i=0;i<n;i++) {
		if (a[i]<0) printf("%d ",a[i]); } }

void sepPos(int *a, int n) {
	printf("\nPositive numbers: ");
	for (int i=0;i<n;i++) {
		if (a[i]>0) printf("%d ",a[i]); } }

int main() {
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array: ");
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sepOdd(a,n);
	sepEven(a,n);
	sepNeg(a,n);
	sepPos(a,n);
	printf("\n");
	return 0; }