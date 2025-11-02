#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned short vowCount(char str[]) {
    unsigned short count=0;
    for (int i=0;str[i]!='\0';i++) if ((isalpha(str[i])!=0) && (tolower(str[i])=='a' || tolower(str[i])=='e' || tolower(str[i])=='i' || tolower(str[i])=='o' || tolower(str[i])=='u')) count++;
    return count; }

unsigned short conCount(char str[]) {
    unsigned short count=0;
    for (int i=0;str[i]!='\0';i++) if ((isalpha(str[i])!=0) && tolower(str[i])!='a' && tolower(str[i])!='e' && tolower(str[i])!='i' && tolower(str[i])!='o' && tolower(str[i])!='u' && tolower(str[i])!='y') count++;
    return count; }

int main() {
    char str[100];
    printf("Enter a string: ");
    for (int i=0;i<99;i++) {
        str[i]=getchar();
        if (str[i]=='\n') {
            str[i]='\0';
            break; } }
    unsigned short vCount=vowCount(str),cCount=conCount(str);
    printf("%s",str);
    printf("\nVowels: %hu\nConsonants: %hu\n",vCount,cCount); }