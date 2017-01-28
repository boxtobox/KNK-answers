bool search(const int a[], int n, int key) {
	int *p;
	for (p = a; p < a + n; p++)
		if (*p == key) return true;
	return false;
}
