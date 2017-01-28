#include <stdio.h>
int main(void)
{
	char c, input[80];
	int n, i, len;
	i = 0;
	printf("Enter message to be encrypted: ");
	while ((c = getchar()) != '\n')		{
		input[i] = c;
		i++;
	}
	len = i;
	do {
		printf("Enter shift amount (1-25): ");
		scanf("%d", &n);
	}	while (n < 1 || n > 25);

    printf("Encrypted message: ");
	for (i = 0; i < len; i++)
	{
		c = input[i];
		if (c >= 65 && c <= 90)
			c = (c - 65 + n) % 26 + 65;
		else if (c >= 97 && c <= 122)
			c = (c - 97 + n) % 26 + 97;
		printf("%c", c);
	}
	printf("\n");
	return 0;
}
