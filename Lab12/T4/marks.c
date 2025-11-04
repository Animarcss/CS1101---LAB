// ================ CODE BY: PARTH BILAYE - 2501CT27 ================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {char name[20]; unsigned short roll_no; unsigned short marks[5];} Result;

void input(Result list[], int n) {
    for (int i=0;i<n;i++) {
        printf("\n\nStudent %d:\nName: ",i+1);
        scanf("%s",&list[i].name);
        printf("Roll no.: ");
        scanf("%hu",&list[i].roll_no);
        printf("Marks: ");
        for (int j=0;j<5;j++) scanf("%hu",&list[i].marks[j]); } }

float median(unsigned short list[], int n) {
	for (int i=n;i>(n-1)/2;i--) {  // bubble sort
		for (int j=0;j<i-1;j++) {
			if (list[j]>list[j+1]) {
				list[j]+=list[j+1];
				list[j+1]=list[j]-list[j+1]; // swapping two elements
				list[j]-=list[j+1]; } } }
	if (n%2==0) return (float)(list[n/2-1]+list[n/2])/2;
	else return (float)list[n/2]; }

short mode(unsigned short list[], int n) {
	bool isCounted[n];
	unsigned short maxFreq=1, freq, maxIndex;
	for (int i=0;i<n;i++) isCounted[i]=false;
	for (int i=0;i<n;i++) {
		if (isCounted[i]==true) continue;
		freq=1;
		for (int j=i+1;j<n;j++) {
			if (isCounted[j]==true) continue;
			if (list[j]==list[i]) {
			freq++;
			isCounted[j]=true; } }
		isCounted[i]=true;
		if (freq>maxFreq) {
			maxFreq=freq;
			maxIndex=i; } }
	if (maxFreq==1) return -1;
	return list[maxIndex]; }

void calcTotAvgMedMod(Result list[], int n) {
    unsigned short tot;
	short mod;
    float avg,med;
    for (int i=0;i<n;i++) {

        tot=0;
        for (int j=0;j<5;j++) tot+=list[i].marks[j];
        avg=(float)tot/5;
		med=median(list[i].marks,5);
		mod=mode(list[i].marks,5);
        printf("\n\n%s:\n\n",list[i].name);
		printf("Total Marks: %hu\n",tot);
        printf("Average Marks: %.2f\n",avg);
		printf("Median Marks: %.2f\n",med);
		if (mod==-1) printf("Mode Marks: No Mode\n");
		else printf("Mode Marks: %hu\n",mod); } }	

void calcAllAvgMedMod(Result list[], int n) {
	unsigned short tot=0;
	short mod;
	float avg,med;
	for (int i=0;i<n;i++) for (int j=0;j<5;j++) tot+=list[i].marks[j];
	avg=(float)tot/(n*5);
	unsigned short *markList=(unsigned short*)malloc(sizeof(unsigned short)*n*5); // dynamic (pseudo-)	array containing all marks of all students
	for (int i=0;i<n;i++) for (int j=0;j<5;j++) *markList++=list[i].marks[j];
	markList-=n*5;
	med=median(markList,n*5);
	mod=mode(markList,n*5);
	printf("\n\nOverall Statistics:\n\n");
	printf("Average Marks: %.2f\n",avg);
	printf("Median Marks: %.2f\n",med);
	if (mod==-1) printf("Mode Marks: No Mode\n\n\n");
	else printf("Mode Marks: %hu\n\n\n",mod); }

int main() {
	unsigned short n;
	printf("Enter the number of students you wish to list: ");
	scanf("%hu",&n);
	Result *studList=(Result*)malloc(sizeof(Result)*n);
	input(studList,n);
	calcTotAvgMedMod(studList,n);
	calcAllAvgMedMod(studList,n); }