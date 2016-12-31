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

void merge(const struct part *inv1, const int num_parts1, const struct part *inv2, const int num_parts2, struct part **merged);
void add_data_to_merged(struct part *merged, int *idx_merged, struct part data);
void print(void);
void restore(void);
void dump(struct part *output, int num_part, char *filename);

int main(int argc, char *argv[])
{
    struct part *inv1, *inv2, *merged;
    FILE *fp_input1, *fp_input2, *fp_merged;
    int read1, read2;
    int num_parts1, num_parts2;   /* number of parts currently stored. num_merged is defined inside of merge function body */

    if(argc != 4) {
        printf("usage: merge inputfile1 inputfile2 mergedfile\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_input1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
        }
    if ((fp_input2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Error: can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
        }

    read1 = fread(&num_parts1, sizeof(num_parts1), 1, fp_input1);
    read2 = fread(&num_parts2, sizeof(num_parts2), 1, fp_input2);
    if (read1 != 1 || read2 != 1) {
        fprintf(stderr, "Error: input files don't have proper num_parts information.\n");
        exit(EXIT_FAILURE);
    }

    if((inv1 = malloc(sizeof(struct part) * num_parts1)) == NULL) {
        fprintf(stderr, "Malloc error\n");
        exit(EXIT_FAILURE);
    }
    read1 = fread(inv1, sizeof(*inv1), num_parts1, fp_input1);
    if (read1 != num_parts1) {
        fprintf(stderr, "Error occured reading %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if((inv2 = malloc(sizeof(struct part) * num_parts2)) == NULL) {
        fprintf(stderr, "Malloc error\n");
        exit(EXIT_FAILURE);
    }
    read2 = fread(inv2, sizeof(*inv2), num_parts2, fp_input2);
    if (read2 != num_parts2) {
        fprintf(stderr, "Error occured reading %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    fclose(fp_input1);
    fclose(fp_input2);

    merge(inv1, num_parts1, inv2, num_parts2, &merged);

    printf("merge completed.\n");
    dump(merged, num_parts1 + num_parts2, argv[3]);
    return 0;
}

void dump(struct part *output, int num_part, char *filename)
{
    int n;
    FILE *fp_merged;
    if ((fp_merged = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Error: can't write %s\n", filename);
        exit(EXIT_FAILURE);
        }
    printf("debugging: value of num_part: %d\n", num_part);
    fwrite(&num_part, sizeof(int), 1, fp_merged); // storing number of part of merged in the output file

    n = fwrite(output, sizeof(struct part), num_part, fp_merged);
    printf("return value of fwrite: %d\n", n);
    fclose(fp_merged);
    return;
}

void merge(const struct part *inv1, const int num_parts1, const struct part *inv2, const int num_parts2, struct part **merged)
{
    int idx_parts1, idx_parts2, idx_merged, num_merged = num_parts1 + num_parts2;
    *merged = malloc(sizeof(struct part) * num_merged);
    idx_merged = 0;
    for (idx_parts1 = 0, idx_parts2 = 0, idx_merged = 0;
         idx_parts1 < num_parts1 || idx_parts2 < num_parts2; ) {
        if (idx_parts1 == num_parts1) {
            for (; idx_parts2 < num_parts2; idx_parts2++)
                add_data_to_merged(*merged, &idx_merged, *(inv2 + idx_parts2++));
        }
        else if (idx_parts2 == num_parts2) {
            for(; idx_parts1 < num_parts1; idx_parts1++)
                add_data_to_merged(*merged, &idx_merged, *(inv1 + idx_parts1++));
        }
        else {
            if ((inv1 + idx_parts1)->number < (inv2 + idx_parts2)->number)
                add_data_to_merged(*merged, &idx_merged, *(inv1 + idx_parts1++));
            else
                add_data_to_merged(*merged, &idx_merged, *(inv2 + idx_parts2++));
        }
    }
}

void add_data_to_merged(struct part *merged, int *idx_merged, const struct part data)
{
    if (*idx_merged > 0) {
        if ((merged + *idx_merged - 1)->number == data.number) {
            if (!strcmp((merged + *idx_merged - 1)->name, data.name))
                (merged + (*idx_merged)++ - 1)->on_hand += data.on_hand;
            else {
                fprintf(stderr, "Two input files have unmatched parts\n");
                exit(EXIT_FAILURE);
            }
        }
        else {
            (merged + *++idx_merged)->number = data.number;
            (merged + *idx_merged)->on_hand = data.on_hand;
            strcpy((merged + *idx_merged)->name, data.name);
        }
    }
}
