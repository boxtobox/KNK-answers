#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int digits_checker[10] = { 0 };
	int digit;
	long n;
	bool any_repeated_digit = false;
	printf("Enter a number: ");
	scanf("%ld", &n);
	while (n>0)
	{
		digit = n % 10;
		digits_checker[digit]++;
		n /= 10;
	}

	printf("Repeated digit(s):");
	for (int i = 0; i < 10; i++)
	{
		if (digits_checker[i] > 1)
		{
			printf(" %d", i);
			any_repeated_digit = true;
		}
	}
	if (!any_repeated_digit)
		printf (" None");
	printf("\n");
	return 0;
}
