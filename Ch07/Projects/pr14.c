#include <stdio.h>
#include <math.h>
int main(void)
{
	double x, y, diff;
	printf("Input a positive float number: ");
	scanf("%lf", &x);
	y = 1;
	do
	{
		diff = (y - x / y) * .5;
		y = (y + x / y) * .5;
		//printf("Getting Closer: %f\n", y);
	} while (fabs(diff) >= 0.00001);
	printf("Square root: %.5f\n", y);
	return 0;
}
