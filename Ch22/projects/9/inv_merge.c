/* Merges a parts database (array version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};
FILE *in_fp1, *in_fp2, *out_fp;

/*
open 2 files
read from each parts, compare them

*/

int main(int argc, char*argv[])
{
    int size1, size2, test_fread, size_output = 0;
    struct part part1, part2, part_out;

    if (argc != 4) {
        fprintf(stderr, "usage: inv_merge infile1 infile2 outfile\n");
        exit(EXIT_FAILURE);
    }
    // opening 3 files
    if ((in_fp1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((in_fp2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    if ((out_fp = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }
    test_fread = fread(&size1, sizeof (int), 1, in_fp1);
    if (test_fread != 1) {
        fprintf(stderr, "fread error: size of %s\n", argv[1]);
    }

    test_fread = fread(&size2, sizeof (int), 1, in_fp2);
    if (test_fread != 1) {
        fprintf(stderr, "fread error: size of %s\n", argv[2]);
    }

    putc(0, out_fp);

    for (;;) {
        printf("size of output: %d, part1.number: %d, part2.number: %d\n", size_output, part1.number, part2.number);

        if ((test_fread = fread(&part1, sizeof(struct part), 1, in_fp1)) == EOF) {
            while((test_fread = fread(&part2, sizeof(struct part), 1, in_fp2) != EOF)) {
                if (size_output > 0 && part2.number == part_out.number) {
                    if (strcmp(part2.name, part_out.name) != 0) {
                        fprintf(stderr, "Aconflicting names: part number %d, names %s and %s\n",
                            part2.number, part_out.name, part2.name);
                        exit(EXIT_FAILURE);
                    }
                part_out = part2;
                fwrite(&part_out, sizeof(struct part), 1, out_fp);
                size_output++;
                }
            } // keep reading from file 2
            break;
        }
        if ((test_fread = fread(&part2, sizeof(struct part), 1, in_fp2)) == EOF) {
            while((test_fread = fread(&part2, sizeof(struct part), 1, in_fp2) != EOF)) {
                if (size_output > 0 && part1.number == part_out.number) {
                    if (strcmp(part1.name, part_out.name) != 0) {
                        fprintf(stderr, "Bconflicting names: part number %d, names %s and %s\n",
                                part1.number, part1.name, part_out.name);
                        exit(EXIT_FAILURE);
                    }
                part_out = part1;
                fwrite(&part_out, sizeof(struct part), 1, out_fp);
                size_output++;
                }
            } // keep reading from file1
            break;
        }

        if (part1.number <= part2.number) {
            if (size_output > 0 && part1.number == part_out.number) {
                if (strcmp(part1.name, part_out.name) != 0) {
                    fprintf(stderr, "Cconflicting names: part number %d, names %s and %s\n",
                            part1.number, part1.name, part_out.name);
                    exit(EXIT_FAILURE);
                }
            }
            part_out = part1;
            printf("%d, %s, %d\n", part_out.number, part_out.name, part_out.on_hand);
            fwrite(&part_out, sizeof(struct part), 1, out_fp);
            fseek(in_fp2, -sizeof(int), SEEK_CUR);
            size_output++;

        } else {
            if (size_output > 0 && part2.number == part_out.number) {
                if (strcmp(part2.name, part_out.name) != 0) {
                    fprintf(stderr, "Dconflicting names: part number %d, names %s and %s\n",
                            part2.number, part_out.name, part2.name);
                    exit(EXIT_FAILURE);
                }
            }
            part_out = part2;
            fwrite(&part_out, sizeof(struct part), 1, out_fp);
            fseek(in_fp1, -sizeof(int), SEEK_CUR);
            size_output++;
        }
    }
    fseek(out_fp, 0, SEEK_SET);
    printf("sizeof final output: %d", size_output);
    fwrite(&size_output, sizeof(int), 1, out_fp);
    fclose(in_fp1);
    fclose(in_fp2);
    fclose(out_fp);
}
