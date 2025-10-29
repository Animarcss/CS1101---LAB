// CODE FOR MAKING PALINDROME OF A WORD BY - PARTH BILAYE (2501CT27)



#include <stdio.h>
#include <string.h>

void concatenate(char *s1, char *s2, char *result) {
	while(*s1) {
		*result=*s1;
		result++; s1++; }
	while(*s2) {
		*result=*s2;
		result++; s2++; }
	*result='\0'; }
	
void reverse(char *s) {
    int len = strlen(s);
    for (int i=0;i<strlen(s)/2;i++) {
        char temp=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=temp; } }

int main() {
	char str[100],rev[100],result[200];
	printf("Enter string: ");
	scanf("%s", str);
	for (int i=0;i<strlen(str);i++) rev[i]=str[i];
	reverse(rev);
	concatenate(str,rev,result);
	printf("The concatenated palindrome is: %s\n",result);
	return 0; }
