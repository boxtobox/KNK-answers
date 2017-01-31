#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define NUM_PLANETS 9

bool strcmp_case_ignored(const char *str1, const char *str2);
int main(int argc, char *argv[]) {
	char *planets[] = { "Mercury", "Venus", "Earth",
		"Mars", "Jupiter", "Saturn",
		"Uranus", "Neptune", "Pluto" };
	int i, j;

	for (i = 1; i < argc; i++) {
		for (j = 0; j < NUM_PLANETS; j++)
			if (strcmp_case_ignored(argv[i], planets[j])) {
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		if (j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}
	return 0;
}

bool strcmp_case_ignored(const char *str1, const char *str2) {
	char p1[50], p2[50];
	int i;
	strcpy(p1, str1);
	strcpy(p2, str2);
	for (i = 0; p1[i] != 0; i++)
		p1[i] = toupper(p1[i]);
	for (i = 0; p2[i] != 0; i++)
		p2[i] = toupper(p2[i]);

	if (strcmp(p1, p2) == 0)
		return true;
	else
		return false;
}
