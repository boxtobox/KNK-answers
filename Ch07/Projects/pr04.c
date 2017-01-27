#include <stdio.h>
int main(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		if (65 <= c && c <= 67)
			c = 50;		// 2
		else if (68 <= c && c <= 70)
			c = 51;		// 3
		else if (71 <= c && c <= 73)
			c = 52;		// 4
		else if (74 <= c && c <= 76)
			c = 53;		// 5
		else if (77 <= c && c <= 79)
			c = 54;		// 6
		else if (c == 80 || c == 82 || c == 83)
			c = 55;		// 7
		else if (84 <= c && c <= 86)
			c = 56;		// 8
		else if (87 <= c && c <= 89)
			c = 57;		// 9

		printf("%c", c);
		scanf("%c", &c);
	}
	printf("\n");
}
