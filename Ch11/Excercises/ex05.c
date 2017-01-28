#include <stdio.h>
#define MINUTES 60
#define SECONDS 60

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void) {
	int hr, min, sec;
	long total_sec;
	printf("enter total seconds: ");
	scanf("%ld", &total_sec);
	split_time(total_sec, &hr, &min, &sec);

	printf("HH: %d, MM: %d, SS: %d\n", hr, min, sec);
	return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
	*sec = total_sec % SECONDS;
	*min = total_sec / SECONDS;
	*hr = *min / MINUTES;
	*min = *min % MINUTES;
}
