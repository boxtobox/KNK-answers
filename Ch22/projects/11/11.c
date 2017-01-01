#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int mm, dd, yyyy, val_parse;
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"};
    if (argc != 2) {
        fprintf(stderr, "usage: 11 date (date format is either mm-dd-yyyy or mm/dd/yyyy\n)");
        exit(EXIT_FAILURE);
    }

    val_parse = sscanf(argv[1], "%d-%d-%d", &mm, &dd, &yyyy);
    if (val_parse != 3) {
        val_parse = sscanf(argv[1], "%d/%d/%d", &mm, &dd, &yyyy);
        if (val_parse != 3) {
            fprintf(stderr, "You entered an invalid format.\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s %d, %d", months[mm-1], dd, yyyy);
    return 0;
}
