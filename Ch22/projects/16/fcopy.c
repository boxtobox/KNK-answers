/*
fcopy.c
copies from f1.c to f2.c, usage: fcopy source dest
fcopy f1.c f2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 512

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch, val_fread;
    char buffer[BUFFERSIZE];
    fpos_t last_pos;

    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    fseek(source_fp, 0, SEEK_SET);

    while ((val_fread = fread(buffer, BUFFERSIZE, 1, source_fp)) == 1) {
        fwrite(buffer, BUFFERSIZE, 1, dest_fp);
        fgetpos(source_fp, &last_pos);
    }

    fsetpos(source_fp, &last_pos);
    while ((ch = getc(source_fp)) != EOF)
        if (putc(ch, dest_fp) < 0) {
            fprintf(stderr, "An error occured while copying.\n");
            exit(EXIT_FAILURE);
        }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}
