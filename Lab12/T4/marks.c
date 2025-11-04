#include <stdio.h>
#include <stdbool.h>

typedef struct {char name[20]; unsigned short roll_no; unsigned short marks[5];} Result;

void input(Result list[], int n) {
    for (int i=0;i<n;i++) {
        printf("\n\nStudent 1:\nName: ");
        scanf("%s",&list[i].name);
        printf("Roll no.: ");
        scanf("%hu",&list[i].roll_no);
        printf("Marks: ");
        for (int j=0;j<5;j++) scanf("%hu",&list[i].marks[j]); } }

float median(unsigned short list[], int n) { // using bubble sort
	for (int i=n;i>(n-1)/2;i--) {
		for (int j=0;j<i-1;j++) {
			if (list[j]>list[j+1]) {
				list[j]+=list[j+1];
				list[j+1]=list[j]-list[j+1]; // swapping two elements
				list[j]-=list[j+1]; } } }
	if (n%2==0) return (float)(list[n/2-1]+list[n/2];
	else return (float)list[n/2]; }

unsigned short mode(unsigned short list[], int n) {
	bool isCounted[n];
	unsigned short maxFreq=1, freq, maxIndex;
	for (int i=0;i<n;i++) isCounted[i]=false;
	for (int i=0;i<n;i++) {
		if (isCounted[i]=true) continue;
		freq=1;
		for (int j=i+1;j<n;j++) {
			if (isCounted[j]=true) continue;
			if (list[j]==list[i]) {
			freq++;
			isCounted[j]=true; } }
		isCounted[i]=true;
		if (freq>maxFreq) {
			maxFreq=freq;
			maxIndex=i } }
	if (maxFreq=1) return -1;
	return list[maxIndex]; }

void calcTotAvgMedMod(Result list[], int n) {
    unsigned short tot,mod;
    float avg,med;
    for (int i=0;i<n;i++) {
        printf("%s",list[i].name);
        tot=0;
        for (int j=0;j<5;j++) tot+=list[i].marks[j];
        printf("Total Marks: %hu",tot);
        avg=(float)tot/5;
        printf("Average Marks: %.2f",avg);
		med=median(list[i].marks,5);
		printf("Median Marks: %.2f",med);
		mod=mode(list[i].marks,5);
		if (mod==-1) printf("Mode Marks: No Mode");
		else printf("Mode Marks: %hu",mod); } }

void calcAllAvgMedMod(Result list[], int n) {