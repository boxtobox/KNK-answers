/* Formats a file of text */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
    FILE *fp_in, *fp_out;

    if (argc != 3) {
        fprintf(stderr, "usage: justify infile outfile\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp_out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();
	for (;;) {
		read_word(fp_in, word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line(fp_out);
			return 0;
		}
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line(fp_out);
			clear_line();
		}
		add_word(word);
	}
}
