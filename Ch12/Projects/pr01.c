#include <stdio.h>

/* (b) */
int main(void) {
	char a[100], ch, *p;
	printf("Enter a message: ");
	p = a;
	while ((ch = getchar()) != '\n') {
		*p++ = ch;
	}

	printf("Reversal is: ");
	for (p--; p >= a; p--)
		printf("%c", *p);
	printf("\n");
}
