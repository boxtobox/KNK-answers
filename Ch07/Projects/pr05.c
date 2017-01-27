/* getting score of scrabble game */
#include <stdio.h>
int main(void)
{
	char c;
	int value = 0;
	printf("Enter a word: ");
	scanf("%c", &c);
	while (c != '\n')
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
		scanf("%c", &c);
	}
	printf("Scrabble value: %d\n", value);
	return 0;

}
