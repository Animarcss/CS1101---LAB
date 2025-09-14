// ================ TASK 3 ================

#include <stdio.h>

void read_array(int *a, int n) {
	printf("\nEnter the array: ");
	for (int i=0;i<n;i++) scanf("%d",a+i); }

int reverse_array(int *a, int n) {
	int temp;
	printf("The reversed array is: ");
	for (int i=0;i<n/2;i++) {
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp; } }

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



// ================ TASK 4 ================

#include <stdio.h>
#include <math.h>

int isPrime(int n,int printOrNot) {
    int isPrime=1;
    if (n<2) isPrime=0;
    for (int i=2;i<=(int)sqrt(n);i++) {                // sqrt() returns a double
        if (n%i==0) {
            isPrime=0;
            break; } }
    if (isPrime==1) {
        if (printOrNot==1) printf("%d is a prime number.",n);
        return 1; }
    else { 
        if (printOrNot==1) printf("%d is NOT a prime number.",n);
        return 0; } }

void listPrime(int n) {
    for (int i=2;i<=n;i++) {
        if (isPrime(i,0)==1) printf("%d ",i); } }

void countPrime(int n) {
    int count=0;
    for (int i=2;i<=n;i++) {
        if (isPrime(i,0)==1) count++; }
    printf("pi(%d) = %d",n,count); }

int listPrimeRange(int a,int b) {
    if (b<a) {
        int temp;
        temp=b;
        b=a;
        a=temp; }
    int exist=0;
    for (int i=a;i<=b;i++) {
        if (isPrime(i,0)==1) {
        	printf("%d ",i);
        	exist=1; } }
    if (exist=1) return 1;
    return 0; }

int collect(int *n) {
    printf("n = ");
    if (scanf("%d",n)!=1) {                                    // & (ampersand not necessary as n is already a pointer)
        printf("Invalid input. Enter a positive integer.\n");
        return 0; }
    else return 1; }

int collectDuo(int *a,int *b) {
    printf("Enter A and B: ");
    if (scanf("%d %d",a,b)!=2) {                               // same as previous comment ^^^^^^^^
        printf("Invalid input(s). Enter positive integers.\n");
        return 0; }
    else return 1; }

int main() {
    while (1) {
        printf("\n\n==== PRIMES' MENU ====\n\n1 - Check primality of n\n2 - List all primes up to n\n3 - Count primes up to n\n4 - List all primes in [A,B]\n0 - Exit\nEnter choice: ");
        int choice,n;
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                if (collect(&n)==0) break;
                isPrime(n,1);
                break;
            case 2:
                if (collect(&n)==0) break;
                listPrime(n);
                break;
            case 3:
                if (collect(&n)==0) break;
                countPrime(n);
                break;
            case 4:
                int m;
                if (collectDuo(&n,&m)==0) break;
                if (listPrimeRange(n,m)==0) printf("No prime numbers.\n");
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n"); }
        if (choice==0) break; }
        return 0; }



// ================ TASK 5 ================

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
