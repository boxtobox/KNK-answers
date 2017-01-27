#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c;
	int sum = 0;

	printf("Enter a sentence: ");
	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		switch (c)
		{
		case 65: case 69: case 73: case 79: case 85:
			sum++;		break;
		}
	}
	printf("Your sentence contains %d vowels.\n", sum);
	return 0;
}
