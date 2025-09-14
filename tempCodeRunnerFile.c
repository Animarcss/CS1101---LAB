#include <stdio.h>
void main() { 
    int f=1;
    for (int j=1;j<5;j++) {
    printf("%d ",f);
    f*=2*j*(2*j-1);    // f in each iteration is (2j)!
    } }