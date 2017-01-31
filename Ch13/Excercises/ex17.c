bool test_extension(const char *file_name, const char *extension) {
	char *s = file_name, *p, *extstart, ext1[10], ext2[10];
	while (*s)
		if (*s++ == '.')
			extstart = s;
	p = ext1;
	s = extstart;
	while (*p++ = toupper(*s++));

	p = ext2;	// input extension
	s = extension;
	while (*p++ = toupper(*s++));

	if (strcmp(ext1, ext2))
		return false;
	else
		return true;
}
