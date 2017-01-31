#include <stdio.h>
#include <string.h>

void reverse_name(char *name) {
	char *p = name, *s, last[25], first[25];
    printf("%s\n", name);

	while (*p == ' ') // skips all spaces before the first letter of first name
		*p++;

    first[0] = *p;
	first[1] = '.';
	first[2] = ' ';
	first[3] = 0;

    while (*p++ != ' '); // skips all letters before blanks(between first letter of first name and first letter of last name)
	while (*p == ' ') // skips all blanks before first letter of last name
	        p++;

    s = last;
	while (*p && *p != ' ') // store characters of last name, exclude possible spaces after the last letter of last name
		*s++ = *p++;
	*s = 0;

    printf("Last name: %s\n", last);

	strcat(first, last);
	strcpy(name, first);
}

int main(void) {
	char name[25], *cur;
	int ch;

	printf("Enter a first and last name: ");
	cur = name;
	while ((ch = getchar()) != '\n') {
        *cur++ = ch;
	}
	*cur = 0;

	reverse_name(name);
	puts(name);
    return 0;
}
