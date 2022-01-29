/* 연습문제1 출력결과 예상 */
#include <stdio.h>

void main()
{
	int m, n;
	for (m = 5; m < 7; m++) {
		for (n = 0; n < 3; n++) {
			if (m == 5 && n == 1) break;
			if (n == 2) continue;
			printf("m(%d)-n(%d)\n", m, n);
		}
	}
}