#include <stdio.h>
int main(void)
{
	int i, n, start;
	printf("Enter number of days in month: ");
	scanf("%d", &n);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start);

	printf("\n Sun Mon Tue Wed Thu Fri Sat\n");

	for (i = 1; i < start; i++)  // prints empty space before 1st
		printf("    ");
	for (i = 1; i <= n; i++)
	{
		printf("%4d", i);
		if ((i + start - 1) % 7 == 0)	printf("\n");
	}
	printf("\n\n");
return 0;
}
