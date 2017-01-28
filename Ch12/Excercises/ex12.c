void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
	int *p = a, *temp = a;
	if (*p > *(p + 1))
		*largest = *p, *second_largest = *(p + 1);
	else
		*largest = *(p + 1), *second_largest = *p;
	for (p = a + 2; p < a + n; p++) {
		if (*p > *second_largest) {
			if (*p > *largest)
			{
				*temp = *largest;
				*largest = *p;
				*second_largest = *temp;
			}
			else
				*second_largest = *p;
		}
	}
}
