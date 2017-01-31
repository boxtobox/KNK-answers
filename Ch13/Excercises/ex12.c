#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);
int main(void) {
	char filename[30], ext[10];
	printf("Enter file name: ");
	scanf("%s", filename);
	get_extension(filename, ext);
	puts(ext);
	return 0;
}

void get_extension(const char *file_name, char *extension) {
	char *dot, *p;
	int len = strlen(file_name);
	for (p = file_name + len - 1; p >= file_name; p--) {
		if (*p == '.') {
			dot = p + 1;
			strcpy(extension, dot);
			return;
		}
	}
	strcpy(extension, "\0");
}
