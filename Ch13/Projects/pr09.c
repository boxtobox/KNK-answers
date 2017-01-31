#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);
int main(void)
{
	char word[90];
	int count;
	printf("Enter a sentence: ");
	gets(word);
	count = compute_vowel_count(word);
	printf("Your sentence contains %d vowels.\n", count);
	return 0;
}
int compute_vowel_count(const char *sentence) {
	int count = 0;
	char c, *p = sentence;
	while (*p) {
		c = toupper(*p);
		switch (c) {
		case 65: case 69: case 73: case 79: case 85: // A E I O U
			count++;		break;
		}
		p++;
	}
	return count;
}
