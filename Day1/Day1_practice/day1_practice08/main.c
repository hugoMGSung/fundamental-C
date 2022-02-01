// 두개 실수 입력받아 정수부만 계산
#include <stdio.h>

void main() {
	float num1, num2;

	printf("두 개의 실수를 입력하세요 : ");
	scanf_s("%f %f", &num1, &num2);

	printf("정수부 더하기 : %d\n", (int)num1 + (int)num2);
}