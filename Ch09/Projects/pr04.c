#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 26
void read_word(int counts[SIZE]);
bool equal_array(int counts1[SIZE], int counts2[SIZE]);
void read_word(int counts[SIZE]) {
	char c;
	printf("Enter a word: ");
	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		if (c >= 65 && c <= 90)
			counts[c - 65]++;
	}
}
bool equal_array(int counts1[SIZE], int counts2[SIZE]) {
	int i;
	for (i = 0; i < SIZE; i++) {
		if (counts1[i] - counts2[i])
			return false;
	}
		return true;
}
int main(void) {
	int word1[SIZE] = { 0 };
	int word2[SIZE] = { 0 };
	read_word(word1);
	read_word(word2);
	if (equal_array(word1, word2))
		printf("Two words are anagrams.\n");
	else
		printf("Two words are NOT anagrams.\n");
}
