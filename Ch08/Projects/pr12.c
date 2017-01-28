#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int score_table[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	int score = 0;
	char c;
	printf("Enter a word: ");
	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		if (c < 65 || c>90) {
			printf("Only alphabetical input is allowed.\n");
			return 0;
		}
		score += score_table[c - 65];
	}
	printf("Scrabble value: %d\n", score);
	return 0;
}
