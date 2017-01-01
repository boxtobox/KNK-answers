#include <stdio.h>
#include <stdlib.h>
#define LINE_MAX 99

int main(int argc, char *argv[])
{
    FILE *fp;
	int item, m, d, y, ret_sscanf;
	float price;
    char line[LINE_MAX+1];
    char *ret_fgets;

	if(argc != 2) {
        fprintf(stderr, "usage: 12 filename\n");
        exit(EXIT_FAILURE);
	}
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");

	while((ret_fgets = fgets(line, LINE_MAX, fp)) != NULL) {
        ret_sscanf = sscanf(line, "%d,%f,%d/%d/%d\n", &item, &price, &m, &d, &y);
        if (ret_sscanf != 5) {
            fprintf(stderr, "%s has wrong format\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        printf("%d\t\t$%7.2f\t%.2d/%.2d/%.4d\n", item, price, m, d, y);
	}
	return 0;
}

