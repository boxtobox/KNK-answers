#include <stdio.h>
int main(void)
{
	int num;
	const char *num_11_19[9] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char *num_tens[8] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const char *num_ones[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	printf("Enter a two-digit number: ");
	scanf("%d", &num);
	if (num < 9 || num > 99)
	{
		printf("Invalid input\n");
		return 0;
	}
	printf("You entered the number ");
	if (num >= 10 && num < 20)	// from 11 to 19
		printf("%s.\n", num_11_19[num - 11]);
	else
	{
		printf("%s", num_tens[num / 10 - 2]);
		if (num % 10)
			printf("-%s", num_ones[num % 10 - 1]);
	}
	printf(".\n");
	return 0;
}
