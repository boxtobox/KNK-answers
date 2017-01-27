#include <stdio.h>
int main()
{
	int i;
	printf("Enter a number: ");
	scanf("%d", &i);

	printf("Reversed number is ");
	do	{
		printf("%d", i % 10);
		i /= 10;
	} while (i > 0);
	printf("\n");
	return 0;
}
