#include <stdio.h>

void build_index_url(const char *domain, char *index_url);

int main(void) {
	char domain[100], index_url[120];
	printf("Enter domain: ");
	scanf("%s", domain);
	build_index_url(domain, index_url);
	puts(index_url);
}

void build_index_url(const char *domain, char *index_url) {
	char temp[100] = "http://www.";
	strcpy(index_url, strcat(strcat(temp, domain), "/index.html"));
}
