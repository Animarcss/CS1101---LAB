#include <stdio.h>

typedef struct {char title[30]; char author[30]; unsigned short price;} Book;

void bookMaxMin(Book list[], int n, Book results[]) {
    int maxIndex=0;
    for (int i=1;i<n;i++) if (list[i].price>list[maxIndex].price) maxIndex=i;
    results[0]=list[maxIndex];
    int minIndex=0;
    for (int i=1;i<n;i++) if (list[i].price<list[minIndex].price) minIndex=i;
    results[1]=list[minIndex]; }

int main() {
    Book list[5]={
        {"The Palace of Illusions", "Chitra Banerjee Divakaruni", 348},
        {"Looking for Alaska", "John Green", 243},
        {"The Great Gatsby", "F. Scott Fitzgerald", 142},
        {"One Indian Girl", "Chetan Bhagat", 204},
        {"The Alchemist", "Paula Coelho", 167} };
    printf("List of books:\n\n");
    Book results[2];
    bookMaxMin(list,5,results);
    for (int i=0;i<5;i++) printf("%30s | by | %-30s | for | Rs %hu\n",list[i].title,list[i].author,list[i].price);
    printf("\nThe maximum valued book is: %30s | by | %-30s | for | Rs %hu\nThe minimum valued book is: %30s | by | %-30s | for | Rs %hu\n\n",results[0].title,results[0].author,results[0].price,results[1].title,results[1].author,results[1].price); }