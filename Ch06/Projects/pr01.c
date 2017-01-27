#include <stdio.h>
int main(void)
{
	float max, n;
	n = 1, max = -1;
	while (n > 0) {
		printf("Enter a number: ");
		scanf("%f", &n);
		if (n > max)
			max = n;
	}
	if (max >= 0)
		printf("The largest number entered was %.2f\n", max);
	else
		printf("There is no nonnegative number entered.\n");
return 0;
}
