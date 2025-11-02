#include <stdio.h>

typedef struct {char name[20]; unsigned short roll_no; unsigned short marks[5];} Result;

void input(Result list[], int n) {
    for (int i=0;i<n;i++) {
        printf("\n\nStudent 1:\nName: ");
        scanf("%s",&list[i].name);
        printf("Roll no.: ");
        scanf("%hu",&list[i].roll_no);
        printf("Marks: ");
        for (int j=0;j<5;j++) scanf("%hu",&list[i].marks[j]); } }

unsigned short median(unsigned short list[], int n) {
    

void calcTotAvgMedMod(Result list[], int n) {
    int tot,avg,med,mod;
    for (int i=0;i<n;i++) {
        printf("%s",list[i].name);
        tot=0;
        for (int j=0;j<5;j++) tot+=list[i].marks[j];
        printf("Total Marks: %hu",tot);
        avg=(float)tot/5;
        printf("Average Marks: &.2f",avg);
        