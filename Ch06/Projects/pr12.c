#include <stdio.h>
int main()
{
	int i;
	float fac, sum, eps;
	fac = 1, sum = 1;
	printf("Enter a small floating number: ");
	scanf("%f", &eps);
	for (i = 1; 1/fac >= eps; i++)
	{
		fac *= i;
		sum += 1 / fac;
		printf("%f\n", sum);
	}
	return 0;
}
