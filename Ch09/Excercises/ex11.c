float compute_GPA(char grades[], int n) {
	int i, total=0;
	for(i=0;i<n;i++)
		switch (grades[i]) {
		case 'a': case 'A':
			total += 4;
			break;
		case 'b': case 'B':
			total += 3;
			break;
		case 'c': case 'C':
			total += 2;
			break;
		case 'd': case 'D':
			total += 1;
			break;
		case 'f': case 'F':
			break;
		default:
			printf("Invalid input.\n");
			return 1;
		}
	return (float)total / n;
}
