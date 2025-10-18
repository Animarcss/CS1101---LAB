/*

#include <stdio.h>
#include <string.h>

int main() {
	char str1[50], str2[50];
	printf("Enter first string: ");
	scanf("%s",str1);
	printf("Enter second string: ");
	scanf("%s",str2);
	char* p1=str1;
	char* p2=str2;
	for (int i=0;i<strlen(p1)+strlen(p2);i++) *(p1+strlen(p1)+i)=*(p2+i);

*/

#include <stdio.h>
void concatenate(char *s1, char *s2, char *result) {
	while(*s1) {
		*result=*s1;
		result++; s1++; }
	while(*s2) {
		*result=*s2;
		result++; s2++; }
	*result='\0'; }

int main() {
	char str1[1000], str2[100], result[200];
	printf("Enter string 1: ");
	scanf("%s", str1);
	printf("Enter string 2: ");
	scanf("%s", str2);
	concatenate(str1,str2,result);
	printf("The concatenated string is: %s\n",result);
	return 0; }
