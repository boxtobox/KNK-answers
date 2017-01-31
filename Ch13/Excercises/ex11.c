int my_strcmp_pt(char *s, char *t) {
	char *x = s, *y = t;
	while (*x == *y) {
		if (!*x)
			return 0;
		*x++, *y++;
	}
	return (*x - *y);
}
