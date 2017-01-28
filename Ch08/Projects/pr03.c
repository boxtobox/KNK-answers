#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int digits_checker[10] = { 0 };
	int digit;
	long n;
	for (;;) {
		printf("Enter a number: ");
		scanf("%ld", &n);
		if (!(n > 0))
			break;
		while (n > 0)
		{
			digit = n % 10;
			digits_checker[digit]++;
			n /= 10;
		}

		printf("Digit:\t\t");
		for (int i = 0; i < 10; i++)
			printf("%3d", i);
		printf("\n");

		printf("Occuerence:\t");
		for (int i = 0; i < 10; i++)
		{
			printf("%3d", digits_checker[i]);
		}
		printf("\n");
        for (int i = 0; i < 10; i ++)
            digits_checker[i] = 0;
	}
	return 0;
}
