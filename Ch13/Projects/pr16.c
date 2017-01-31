#include <stdio.h>
void reverse(char *message) {
	char *s, *e, tmp;
	s = e = message;
	while (*e++);	// e points at place next to the null character
	e -= 2;
	while (s < e) {
		tmp = *s;
		*s = *e;
		*e = tmp;
		s++, e--;
	}
}
int main(void) {
	char a[100];
	printf("Enter a message: ");
	gets(a);
	reverse(a);
	printf("Reversal is: ");
	puts(a);
}
