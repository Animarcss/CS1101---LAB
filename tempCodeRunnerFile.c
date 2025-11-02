#include<stdio.h>
 void printReverse(){
 char c;
 scanf("%c",&c);
 if(c=='\n')
 return;
 printReverse();
 printf("%c",c);
 }
 int main(){
 printf("Enter your name:");
 printReverse();
 printf("\n");
 return 0;
 }