int find_largest(int a[], int n) {
	int *p, max;
	p = a;
	max = *p;
	for (p = a + 1; p < p + n; p++)
		if (*p > max)
			max = *p;
	return max;
}
