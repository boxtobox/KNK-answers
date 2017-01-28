#include <stdio.h>
#include <ctype.h>
#define LEN 100
/* (b) */
int main(void) {
	char ch, a[LEN], *p = a, *q;
	int i = 0;
	printf("Enter a message: ");

	while((ch=getchar())!='\n') {
		if (isalpha(ch))
			*p++ = tolower(ch);
		else if (ch == '\n')
			break;
	}

	q = a;
	for (p--; p >= a; p--) {
		if (*q++ != *p) {
			printf("Not a palindrome\n");
			return 0;
		}
	}
	printf("Palindrome\n");
	return 0;
}
