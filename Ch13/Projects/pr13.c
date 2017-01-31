#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *msg, int shift) {
	char a, *p = msg;
	while (*p) {
		if (isalpha(*p)) {
			if (isupper(*p))
				a = 'A';
			else if (islower(*p))
				a = 'a';
			*p = ((*p - a) + shift) % 26 + a;
		}
		p++;
	}
}

int main(void) {
	char msg[80];
	int shift;
	printf("Enter message to be encrypted: ");
	gets(msg);
	printf("Enter shift amount (1-25): ");

	scanf("%d", &shift);
	encrypt(msg, shift);

	printf("Encrypted message: ");
	printf("%s\n", msg);
}
