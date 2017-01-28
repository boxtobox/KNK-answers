#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char a[50];
	char ch;
	int len, i = 0;
	printf("Input any sentence: ");
	ch = getchar();
	while (ch != '\n')
	{
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':	ch = '4';	break;
		case 'B':	ch = '8';	break;
		case 'E':	ch = '3';	break;
		case 'I':	ch = '1';	break;
		case 'O':	ch = '0';	break;
		case 'S':	ch = '5';	break;
		}
		a[i] = ch;
		i++;
		ch = getchar();
	}
	len = i;
	for (i = len; i < len + 10; i++)
		a[i] = '!';
	for (i = 0; i < len + 10; i++)
		printf("%c", a[i]);
	printf("\n");
	return 0;
}
