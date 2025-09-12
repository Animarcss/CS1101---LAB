#include <stdio.h>

int main()
{	
	float ppr, booked, nights, food;
	printf("\n\n\n==== Welcome to XYZ Hotels! ====\n\n\n");
	printf("Enter the base price of room per night per room: ");
	scanf("%f", &ppr);
	printf("\nEnter the number of rooms booked: ");
	scanf("%f", &booked);
	printf("\nEnter the number of nights of stay: ");
	scanf("%f", &nights);
	printf("\nEnter the total food bill without GST: ");
	scanf("%f", &food);
	printf("\n\nThe total bill amount (including GST) is Rs %d.\n\n==== End of Program ===\n\n", (int)(ppr*booked*nights*118/100+food*112/100));
	return 0;
}
