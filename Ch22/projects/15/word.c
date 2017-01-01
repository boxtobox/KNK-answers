#include <stdio.h>
#include "word.h"

int read_char(FILE *fp)
{
	int ch = getc(fp);
	if (ch == '\n' || ch == '\t')
		return ' ';
	return ch;
}

void read_word(FILE *fp, char *word, int len)
{
	int ch, pos = 0;
	while ((ch = read_char(fp)) == ' ')
		;
	while (ch != ' ' && ch != EOF) {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char(fp);
	}
	word[pos] = '\0';
}
