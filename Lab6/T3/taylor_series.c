#include <stdio.h>
#include <math.h>
int main() {
    int n,k;
    double s;
    long f;
    printf("Enter the number of terms to be used from Taylor series: ");
    scanf("%d",&n);
    printf("Enter the number of divisions in [0,2pi]: ");
    scanf("%d",&k);
    printf("\n\nEvaluating cos(x) with n=%d terms of the Taylor series at (k+1)=%d points in [0,2pi]:\n",n,k+1);
    for (int i=0;i<=k;i++) {
        s=1;
        f=1;
        double x=i*2*3.141592653589793/k;
        for (int j=1;j<n;j++) {
            f*=2*j*(2*j-1);    // f in each iteration is (2j)!
            s+=pow(-1,j)*pow(x,2*j)/f; }
        printf("\nx = %.15lf rad (%.3fpi) -> cos(x) = %.15lf",x,(float)i*2/k,s); }
        return 0; }