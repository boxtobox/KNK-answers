#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50	/* maximum number of reminders */
#define MSG_LEN 60	/* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
	char reminders[MAX_REMIND][MSG_LEN + 13];	// MSG_LEN+1�� ��¥(3����), �ð�(6����)�� �������� MSG_LEN+10
	char day_str[12], time_str[6], msg_str[MSG_LEN + 1];
	int month, day, i, j, hh, mm, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {	// �޸��� ������ ������ ������ �� �̻� �Է� ���� ����
			printf("-- No space left --\n");
			break;
		}
		printf("Enter day, time and reminder: ");
		scanf("%2d/%2d", &month, &day);	// ��, ��¥ �κ��� �ִ� 2�ڸ��� ������ �Է¹���. �䱸����(c)
		if (month == 0)
			break;
		else if (month < 0 || month>12 || day < 0 || day>31) {	// �䱸���� (a) / (c)
			printf("Wrong day input!\n");
			continue;
		}
		sprintf(day_str, "%2d/%2d ", month, day);	// �Է¹��� ��¥�� string type���� ��ȯ

		scanf("%d:%d", &hh, &mm);	// �ð� �Է� - �䱸���� (b)
		if (hh < 0 || hh>23 || mm < 0 || mm>59) {
			printf("Wrong time input!\n");
			continue;
		}

		sprintf(time_str, "%2d:%.2d", hh, mm);	//�ð� -> string type
		/* �� ����ǥ �� �� �ڿ� �����̽��� �ϳ� ���� �� ������ ����� ������ �߻��߾���.
		�����̽��� ������ null character�� �����ؼ� �ڸ��� �� 7���� �ʿ��ߴµ� ������ 6���� �Ǿ� �־���.
		stack around the variable 'time_str' was corrupted.*/
		strcat(day_str, time_str);

		read_line(msg_str, MSG_LEN);	// �޸��� ������ �Է¹޴� �Լ� ȣ��

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)	// ���� �����ͺ��� ��¥�� �۰ų� ���������� i++
				break;

		for (j = num_remind; j > i; j--)	// i�ڸ� ������ �����͸� ���ڸ��� �ڷ� �о
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);	// ��¥ �κ��� ���ڿ��� �迭�� �Է�
		strcat(reminders[i], msg_str);	// �޸� �κ��� ���ڿ��� ��¥ �ڿ� ���ؼ� �迭�� �Է�

		num_remind++;
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n) {
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
