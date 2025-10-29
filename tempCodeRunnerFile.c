#include <stdio.h>

int main() {
    int arr[5]={1,2,3,4,5};
    int *p=arr;
    printf("%d\n",*p);
    int **p1=&p;
    printf("%p\n",p);
    printf("%p\n",arr);
    printf("%p\n",&arr[0]);
    printf("%p\n",p1);
    printf("%p\n",&p);
    printf("%p\n",&p1);
    printf("%p\n",&arr);
}