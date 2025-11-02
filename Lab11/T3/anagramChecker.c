#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned short letterFreq(char l, char str[]) {                                               // called at CALL_SIGN below
    unsigned short freq=0;
    for (int i=0;i<strlen(str);i++) if (str[i]==l) freq++;
    return freq; }

bool areAnagrams(char str1[], char str2[]) {
    unsigned short freq=0;
    bool isCounted[strlen(str1)];
    for (int i=0;i<strlen(str1);i++) {
        isCounted[i]=false; }
    for (int i=0;i<strlen(str1);i++) {
        if (isCounted[i]==true) continue;
        freq=1;
        for (int j=i+1;j<strlen(str1);j++) if (isCounted[j]==0 && str1[i]==str1[j]) freq++;
        if (letterFreq(str1[i],str2)!=freq) return false; }                                   // CALL_SIGN
    return true; }

int main() {
    char word1[100],word2[100];
    printf("Enter word 1: ");
    scanf("%s",word1);
    printf("Enter word 2: ");
    scanf("%s",word2);
    if (areAnagrams(word1,word2)==true) printf("\nAnagrams\n");
    else printf("Not anagrams.\n");
    return 0; }