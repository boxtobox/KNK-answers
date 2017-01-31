#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50	/* maximum number of reminders */
#define MSG_LEN 60	/* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
	char reminders[MAX_REMIND][MSG_LEN + 13];	// MSG_LEN+1에 날짜(3글자), 시간(6글자)이 더해져서 MSG_LEN+10
	char day_str[12], time_str[6], msg_str[MSG_LEN + 1];
	int month, day, i, j, hh, mm, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {	// 메모의 갯수가 제한을 넘으면 더 이상 입력 받지 않음
			printf("-- No space left --\n");
			break;
		}
		printf("Enter day, time and reminder: ");
		scanf("%2d/%2d", &month, &day);	// 월, 날짜 부분은 최대 2자리의 정수로 입력받음. 요구사항(c)
		if (month == 0)
			break;
		else if (month < 0 || month>12 || day < 0 || day>31) {	// 요구사항 (a) / (c)
			printf("Wrong day input!\n");
			continue;
		}
		sprintf(day_str, "%2d/%2d ", month, day);	// 입력받은 날짜를 string type으로 변환

		scanf("%d:%d", &hh, &mm);	// 시간 입력 - 요구사항 (b)
		if (hh < 0 || hh>23 || mm < 0 || mm>59) {
			printf("Wrong time input!\n");
			continue;
		}

		sprintf(time_str, "%2d:%.2d", hh, mm);	//시간 -> string type
		/* 이 따옴표 안 맨 뒤에 스페이스를 하나 넣은 것 때문에 디버그 에러가 발생했었다.
		스페이스를 넣으면 null character를 포함해서 자리가 총 7개가 필요했는데 선언은 6으로 되어 있었음.
		stack around the variable 'time_str' was corrupted.*/
		strcat(day_str, time_str);

		read_line(msg_str, MSG_LEN);	// 메모의 내용을 입력받는 함수 호출

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)	// 기존 데이터보다 날짜가 작거나 같을때까지 i++
				break;

		for (j = num_remind; j > i; j--)	// i자리 이후의 데이터를 한자리씩 뒤로 밀어냄
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);	// 날짜 부분의 문자열을 배열에 입력
		strcat(reminders[i], msg_str);	// 메모 부분의 문자열을 날짜 뒤에 더해서 배열에 입력

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
