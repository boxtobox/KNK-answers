int exer10_a(int a[], int n) {
	// (a) largest element in a
	int max = a[0], i;
	for (i = 1; i < n; i++) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}
float exer10_b(int a[], int n) {
	int total = 0, i;
	float average;
	for (i = 0; i < n; i++)
		total += a[i];
	average = (float)total / n;
	return average;
}
int exer10_c(int a[], int n) {
	int i, p = 0;
	for (i = 0; i < n; i++)
		if (a[i] > 0)	p++;
	return p;
}
