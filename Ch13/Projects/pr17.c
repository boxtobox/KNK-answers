#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_palindrome(const char *msg) {

	char *cur1, *cur2, *start, *end;
	start = cur1 = end = msg;
	while (*cur1)
        cur1++;
	end = cur1 - 1;

    for (cur1 = start, cur2 = end; cur1 <= cur2; cur2--) {
        if (*cur1++ != *cur2)
            return false;
    }

	return true;
}

int main(void) {
	char msg[100], *p = msg;
	int ch;
	printf("Enter a message: ");

	while ((ch = getchar()) != '\n')
        *p++ = ch;
    *p = 0;

	if (is_palindrome(msg))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	return 0;
}
