#include <stdio.h>

typedef struct {unsigned id; char name[20]; unsigned short quantity; double price;} entries;

unsigned addItems(entries x[], int n) {
    unsigned num=0;
    for (int i=0;i<n;i++) num+=x[i].quantity;
    return num; }

double totVal(entries x[], int n) {
    double val=0.00;
    for (int i=0;i<n;i++) val+=x[i].quantity*x[i].price;
    return val; }

int main() {
    entries inventory[5]={
        {58218, "Iron Axe", 16, 8456.7457},
        {81379, "Diamond Chestplate", 33, 50345.2323},
        {64254, "Cooked Porkchop", 125, 1254.777},
        {34234, "Ink Sac", 173, 253.344},
        {63966, "Dirt Block", 3434, 150.32} };
    unsigned short choice;
    do {
        printf("\n======== Inventory ========\n\n");
        printf("Choose your task:\n\n1. Request number of items.\n2. Add all items.\n3. Display total value.\n4. Exit\n\n");
        scanf("%hu",&choice);
        switch (choice) {
            case 1:
                for (int i=0;i<5;i++) printf("%20s - %hu\n",inventory[i].name,inventory[i].quantity);
                break;
            case 2:
                printf("Total items: %u\n",addItems(inventory,5));
                break;
            case 3:
                printf("Total price is: %.2f\n",totVal(inventory,5));
                break;
            case 4: break;
            default: printf("\nCHOOSE A VALID OPTION FROM 1 TO 4\n"); } }
    while (choice!=4); }