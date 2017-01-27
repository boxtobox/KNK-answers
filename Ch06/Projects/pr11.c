#include <stdio.h>
/* calculating approximate value of e(Euler's Number) */
int main()
{
	int i, n;
	float fac, sum;
	fac = 1, sum = 1;
	printf("Enter a positive integeer: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		fac *= i;
		sum += 1 / fac;
		printf("%f\n", sum);
	}
	return 0;
}

