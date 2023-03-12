#include <stdio.h>

int main(void) {
	int num1, num2, time;				// num1에는 분류 저장, num2에는 소형 대형 저장, time에는 분 저장

	printf("분류를 선택해주세요 \n");
	printf("1. 단기 (승용차 전용) \n");
	printf("2. 장기 \n");

	scanf_s("%d", &num1);

	printf(" 차 종을 선택해주세요 \n");
	printf("1. 소형 \n");
	printf("2. 대형 \n");

	scanf_s("%d", &num2);

	printf(" 이용한 시간(분)을 입력해주세요 \n");

	scanf_s("%d", &time);

	if (num1 == 1) {				// 단기 주차일 경우

		if (num2 == 1) {			// 소형차를 선택한 경우

			if (time <= 30) {			// 이용시간이 30분 이하일 경우
				printf(" 요금은 1,200원 입니다");		// 기본 요금만 출력
			}

			else if (time > 30 && time < 1440) {		// 30분 초과, 하루 미만 이용한 경우
				time = time - 30;			// 이용시간에 기본이용시간 (30분) 빼고 남은 시간을 time에 저장
				
				if (time % 15 != 0) {		// 15분으로 나눴을 때 나머지가 0이 아니라면
					time = time / 15 + 1;		// 시간을 15분으로 나눈 몫에 1을 더함
				}
				else {
					time = time / 15;			// 시간을 15분으로 나눈 몫 저장
				}

				printf("요금은 %d원 입니다", 1200 + time * 600);		// 이용 요금은 기본요금(1200원)에 15분당 600원 곱함
			}

			else {								// 이용 시간이 하루가 넘는 경우
				
				if (time % 1440 == 0) {			// 이용 시간이 24시간씩 나눠질 경우
					time = time / 1440;			// 하루(1440분)으로 나눈 몫을 저장
					printf("요금은 %d원 입니다", time * 24000);			// 하루당 24000원씩 곱함
				}

				else {
					int day = time / 1440;
					int min = time % 1440;

					if (min % 15 != 0)
						min = min / 15 + 1;

					else
						min = min / 15;

					printf("요금은 %d원 입니다", day * 24000 + min * 600);
				}
			}
		}

		else {						// 소형차(1)이 아닌 다른 번호를 눌렀을 경우
			printf("차 종을 잘못 선택했습니다");			// 잘못 눌렀음을 출력
		}
	}


	else if (num1 == 2) {			// 장기 주차일 경우

		if (num2 == 1) {			// 소형차일 경우

			if (time < 1440) {		// 이용 시간이 하루 미만일 경우
				
				if (time % 60 != 0) {
					time = time / 60 + 1;
					printf("요금은 %d원 입니다", time * 1000);
				}

				else
					printf("요금은 %d원 입니다", time * 1000);
			}

			else {

				if (time % 1440 != 0) {
					int day = time / 1440;
					int hour = time & 1440;

					printf("요금은 %d원 입니다", day * 9000 + hour * 1000);
				}

				else {
					time = time / 1440;
					printf("요금은 %d원 입니다", time * 9000);
				}
			}
		}

		else if (num2 == 2) {		// 대형차일 경우

			if (time < 1440) {			// 이용 시간이 하루가 안될 경우
				
				if (time % 30 != 0) {
					time = time / 30 + 1;

					printf("요금은 %d원 입니다", time * 1200);
				}
				else {
					time = time / 30;
					printf("요금은 %d원 입니다", time * 1200);
				}
			}

			else {
				if (time % 1440 != 0) {
					int day = time / 1440;
					int min = time % 1440;

					if (min % 30 != 0) {
						min = min / 30 + 1;

						printf("요금은 %d원 입니다", day * 12000 + min * 1200);
					}

					else {
						min = min / 30;

						printf("요금은 %d원 입니다", day * 12000 + min * 1200);
					}
				}

				else {
					time = time / 1440;
					printf("요금은 %d원 입니다", time * 12000);

				}
			}
		}

		else {						// 소형(1), 대형(2)이 아닌 다른 번호를 눌렀을 경우
			printf("차 종을 잘못 선택했습니다");			// 잘못 눌렀음을 출력
		}
	}


	else {							// 단기(1), 장기(2)가 아닌 다른 번호를 눌렀을 경우
		printf("분류를 잘못 선택했습니다.");				// 잘못 눌렀음을 출력
	}

	return 0;
}