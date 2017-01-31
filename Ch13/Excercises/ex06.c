void censor(char *str) {
	char *p = str;
	while (*p)	{
		if (*p == 'f' && *(p + 1) == 'o' && *(p + 2) == 'o')
			*p = *(p + 1) = *(p + 2) = 'x';
		*p++;
	}
}
