/* using getchar() version. In this version only one character-reading function is used, one less than scanf() version. */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c;
	int value = 0;
	printf("Enter a word: ");
	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		if (c<65 || c>90)	{
			printf("only alphabetical input is allowed.\n");
			return 0;
		}
		switch (c) {
		case 'D': case 'G':
			value += 2;		break;
		case 'B': case 'C': case 'M': case 'P':
			value += 3;		break;
		case 'F': case 'H': case 'V': case 'W': case 'Y':
			value += 4;		break;
		case 'K':
			value += 5;		break;
		case 'J': case 'X':
			value += 8;		break;
		case 'Q': case 'Z':
			value += 10;	break;
		default:
			value += 1;		break;
		}
	}
	printf("Scrabble value: %d\n", value);
	return 0;

}
