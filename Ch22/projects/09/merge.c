// http://knking.com/books/c2/answers/c22.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int main(int argc, char *argv[])
{
    FILE *in_fp1, *in_fp2, *out_fp;
    int num_read1, num_read2, size_outfile = 0;
    int size_file1, size_file2;

    struct part part1, part2;

    if (argc != 4) {
        fprintf(stderr, "usage: merge infile1 infile2 outfile\n");
        exit(EXIT_FAILURE);
    }

    if ((in_fp1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((in_fp2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((out_fp = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    num_read1 = fread(&part1, sizeof(struct part), 1, in_fp1);
    num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
    while (num_read1 == 1 && num_read2 == 1)
        /* successfully read records from both files */
    if (part1.number < part2.number) {
        fwrite(&part1, sizeof(struct part), 1, out_fp);
        size_outfile++;
        num_read1 = fread(&part1, sizeof(struct part), 1, in_fp1);
    } else if (part1.number > part2.number) {
        fwrite(&part2, sizeof(struct part), 1, out_fp);
        size_outfile++;
        num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
    } else {
        /* part numbers are equal */
        if (strcmp(part1.name, part2.name) != 0)
            fprintf(stderr,
                    "Names don't match for part %d; using the name %s\n",
                    part1.number, part1.name);
        part1.on_hand += part2.on_hand;
        fwrite(&part1, sizeof(struct part), 1, out_fp);
        size_outfile++;
        num_read1 = fread(&part1, sizeof(struct part), 1, in_fp1);
        num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
    }

    /* copy rest of file1 to ouput file */
    while (num_read1 == 1) {
        fwrite(&part1, sizeof(struct part), 1, out_fp);
        num_read1 = fread(&part1, sizeof(struct part), 1, in_fp1);
        size_outfile++;
    }

    /* copy rest of file2 to output file */
    while (num_read2 == 1) {
        fwrite(&part2, sizeof(struct part), 1, out_fp);
        num_read2 = fread(&part2, sizeof(struct part), 1, in_fp2);
        size_outfile++;
    }

    fclose(in_fp1);
    fclose(in_fp2);
    printf("sizeof outfile: %d\n", size_outfile);

    fclose(out_fp);
    return 0;
}
