#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,c;
	printf("\n\n\n==== Quadratic Solver ====\n\n\n");
	printf("Enter values of a, b and c as in the equation - ax^2 + bx + c = 0.\n\na = ");
	scanf("%f", &a);
	printf("\nb = ");
	scanf("%f", &b);
	printf("\nc = ");
	scanf("%f", &c);
	printf("\n\nThe solution of the quadratic equation (%f)x^2 + (%f)x + (%f) = 0 is:\n\nx = %f, %f\n\n==== End of Program ====\n\n", a,b,c,(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
	return 0;
}
