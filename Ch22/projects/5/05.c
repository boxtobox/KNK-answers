/* Performs XOR encrpytion
original version is xor.c from 20.1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *fp_r, *fp_w;
	int orig_char, new_char;

    if (argc != 3) {
        printf("usage: 05 filename(input) filename(output)\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_r = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: %s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp_w = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Error: %s can't be written.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int chars_wrote = 0;
	while ((orig_char = getc(fp_r)) != EOF) {
		new_char = orig_char ^ KEY;
		putc(new_char, fp_w);
		chars_wrote++;
	}
	printf("work completed. %d bytes wrote.\n", chars_wrote);
    fclose(fp_r);
    fclose(fp_w);
	return 0;
}
