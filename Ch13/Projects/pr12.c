#include <stdio.h>
#include <string.h>
#define MAX_WORDS 30
#define MAX_CH 20


void read_sentence(char *input) {
	char sentence[MAX_WORDS][MAX_CH], temp[100] = "";
	char end_of_sentence[2] = "\0";
	char *p = input;
	int wrd = 0, ch = 0;

	for (;;) {
		if (*p == 63 || *p == 46 || *p == 33) {
			sentence[wrd][ch] = 0;
			end_of_sentence[0] = *p;
			break;
		}
		else if (*p == ' ') {
			sentence[wrd++][ch] = 0;
			ch = 0;
		}
		else
			sentence[wrd][ch++] = *p;

		p++;
		}

	while (wrd >= 0) {
		strcat(temp,sentence[wrd]);
		if (wrd)
			strcat(temp, " ");
		else
			strcat(temp, end_of_sentence);
		wrd--;
	}
	strcpy(input, temp);
}

int main(void) {

	char input[200];

	//while (c != 63 && c != 46 && c != 33) {
	printf("Enter a sentence: ");
	gets(input);
	read_sentence(input);
	puts(input);
}
