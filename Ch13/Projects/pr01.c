#include <string.h>
#include <stdio.h>

int main(void) {
	char smallest[21], largest[21], word[21];
	printf("Enter word: ");
	gets(word);
	strcpy(largest, word);
	strcpy(smallest, word);
	while (strlen(word) != 4) {
		printf("Enter word: ");
		gets(word);
		if (strcmp(word, largest) > 0)
			strcpy(largest, word);
		else if (strcmp(word, smallest) < 0)
			strcpy(smallest, word);
	}
	printf("Smallest word: %s\n"
		"Largest word: %s\n", smallest, largest);
	return 0;
}
