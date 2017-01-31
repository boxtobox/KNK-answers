#include <stdio.h>

double compute_average_word_length(const char *sentence) {
	int word_count = 0, ch_count = 0;
	char *p = sentence;
	while (*p++) {
		if (*p == ' ')
			word_count++;
		else
			ch_count++;
	}
	word_count++;
	return (double)ch_count / word_count;
}
int main(void) {
	char str[50];
	double avg;
	printf("Enter a sentence: ");
	gets(str);
	avg = compute_average_word_length(str);
	printf("Average word length: %.1f\n", avg);
}
