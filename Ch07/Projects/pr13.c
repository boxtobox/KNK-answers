#include <stdio.h>
int main(void)
{
	int n, total;
	n = total = 0;
	char c;
	printf("Enter a sentence: ");
	while ((c = getchar()) != '\n')
	{
		if (c != ' ')
			total++;
		else
			n++;
	}
	printf("total characters: %d, total words: %d\n", total, n + 1);
	printf("Average word length: %.1f\n", (float) total / (n + 1));
	return 0;

}
