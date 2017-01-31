void capitalize_a(char *str) {
	int i = 0;
	do
		str[i] = toupper(str[i]);
	while (str[i++] != '\0');
}

void capitalize_b(char *str) {
	char *p = str;
	while (*p)
		*p++ = toupper(*p);
}
