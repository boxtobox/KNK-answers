#include <stdio.h>

int main(int argc, char *argv[]) {
	// this prints command-line arguments in reverse order.
	// subscription version
	int i;
	for(i = argc - 1; i > 0; i--)	{
		printf("%s ", argv[i]);
	}
	printf("\n");

	// pointer version
	char **p;
	for (p = argv + argc - 1; p > argv; p--)	{
		printf("%s ", *p);
	}
	return 0;
}
