#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char period;
	int h, m;

	printf("Enter 12-hour time: ");
	scanf("%d:%d", &h, &m);
	while ((period = getchar()) == ' ');
	if (toupper(period) == 'A')
	{
		printf("24-hour: %d:%.2d\n", h, m);
		return 0;
	}
	else if (toupper(period) == 'P')
	{
		printf("24-hour: %d:%.2d\n", h + 12, m);
		return 0;
	}
	return 0;
}
