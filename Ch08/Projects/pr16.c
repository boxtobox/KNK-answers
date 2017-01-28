#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(void)
{
	int word1[26] = { 0 };
	int word2[26] = { 0 };
	char c;
	int i;
	bool is_anagram = 1;
	printf("Enter first word: ");
	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		if (c >= 65 && c <= 90)
			word1[c - 65]++;
	}
	printf("Enter second word: ");
	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		if (c >= 65 && c <= 90)
			word2[c - 65]++;
	}
	for (i = 0; i < 26; i++)
	{
		if (word1[i] != word2[i]) {
			is_anagram = 0;
			break;
		}
	}

	if (is_anagram == 1)
		printf("The words are anagrams.\n");
	else
		printf("The words are NOT anagrams.\n");
	return 0;
}
