#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define FILENAME_LEN 99

int main(void)
{
    FILE *fp_in, *fp_out;
	char infile[FILENAME_LEN+1], outfile[FILENAME_LEN+5];
	int c, shift;

    printf("Enter name of file to be encrypted: ");
    scanf("%[^\n]", infile);
    strcpy(outfile, infile);
    strcat(outfile, ".enc");

    if ((fp_in = fopen(infile, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", infile);
        exit(EXIT_FAILURE);
    }

    if ((fp_out = fopen(outfile, "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", outfile);
        exit(EXIT_FAILURE);
    }

	do {
		printf("Enter shift amount (1-25): ");
		scanf("%d", &shift);
	}	while (shift < 1 || shift > 25);

	while ((c = getc(fp_in)) != EOF) {
		if (isupper(c))
			c = (c - 65 + shift) % 26 + 65;
		else if (islower(c))
			c = (c - 97 + shift) % 26 + 97;
		putc(c, fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
