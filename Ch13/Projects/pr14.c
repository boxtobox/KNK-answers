#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2) {
	int count_word1[26] = { 0, };
	int count_word2[26] = { 0, };
	int i;
	char *p = word1;
	while (*p)
		count_word1[toupper(*p++) - 'A']++;
	p = word2;
	while (*p)
		count_word2[toupper(*p++) - 'A']++;

	for (i = 0; i < 26; i++)
		if (count_word1[i] != count_word2[i])
			return false;

	return true;
}

int main(void) {
	char word1[50], word2[50];
	printf("Enter first word: ");
	scanf("%s", &word1);
	printf("Enter second word: ");
	scanf("%s", &word2);
	if (are_anagrams(word1, word2))
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");
}
