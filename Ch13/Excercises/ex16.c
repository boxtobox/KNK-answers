int count_spaces(const *str) {
	int count = 0;
	char *p = str;
	while (*p)
		count += (*p++ == ' ');
	return count;
}
