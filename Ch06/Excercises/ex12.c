#include <stdio.h>
int main(void)
{
	int d, n;
	printf("input value of n: ");
	scanf("%d", &n);
	for (d = 2; d*d < n; d++)
		if (n % d == 0)
		{
			printf("%d is divisible by %d.\n", n, d);
			return 0;
		}
	printf("%d is a prime number.\n", n);
}
