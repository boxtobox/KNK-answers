void remove_filename(char *url) {
	char *s, *end = url;
	while (*end++);
	end -= 1;
	s = end;
	while (s > url) {
		if (*s == '/')
			break;
		s--;
	}	// s points at last slash now
	*s = '\0';
}
