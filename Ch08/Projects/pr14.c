#include <stdio.h>
int main(void)
{
	char c, term_char, sentence[60];
	int i, j, start, end, len;
	i = 0;

	printf("Enter a sentence: ");
	c = getchar();
	while (c != '.' && c != '!' && c != '?')
	{
		sentence[i] = c;
		i++;
		c = getchar();
	}
	term_char = c;

	printf("Reversal of sentence: ");
	len = end = i - 1;
	for (i = end; i >= 0; i--)
	{
		if (sentence[i] == ' ')
		{
			start = i + 1;
			for (j = start; j <= end; j++)
				printf("%c", sentence[j]);
			printf(" ");
			end = start - 2;
		}
	}

	for (i = 0; i <= end; i++)
		printf("%c", sentence[i]);
	printf("%c\n", term_char);

	return 0;
}
