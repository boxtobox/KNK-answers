#include <stdio.h>
int main()
{
	int speed;
	printf("Enter a wind speed(in knots, int form): ");
	scanf("%d", &speed);

	if (speed > 63)
		printf("Hurricane");
	else if (speed >= 48)
		printf("Storm");
	else if (speed >= 28)
		printf("Gale");
	else if (speed >= 4)
		printf("Breeze");
	else if (speed >= 1)
		printf("Light air");
	else
		printf("Calm");
	printf("\n");
	return 0;

}
