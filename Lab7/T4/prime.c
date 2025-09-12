#include <stdio.h>
#include <math.h>

int isPrime(int n,int printOrNot) {
    int isPrime=1;
    if (n<=1) isPrime=0;
    for (int i=2;i<=(int)sqrt(n);i++) {                // sqrt() returns a double ffs
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

void listPrimeRange(int a,int b) {
    if (b<a) {
        int temp;
        temp=b;
        b=a;
        a=temp; }
    for (int i=a;i<=b;i++) {
        if (isPrime(i,0)==1) printf("%d ",i); } }

int collect(int *n) {
    printf("n = ");
    if (scanf("%d",n)!=1) {                                    // & (ampersand not necessary as n is already a pointer)
        printf("Invalid input. Enter a positive integer.\n");
        return 0; }
    else return 1; }

int collectDuo(int *a,int *b) {
    printf("Enter A and B: ");
    if (scanf("%d %d",a,b)!=2) {                             // same as previous comment ^^^^^^^^
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
                listPrimeRange(n,m);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n"); }
        if (choice==0) break; } }