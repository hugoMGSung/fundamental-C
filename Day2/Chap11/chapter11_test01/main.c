/* 연습문제 2 */
#include <stdio.h>

int result;
void Test() {
	int result = 5;
	result++;
}

void main(void) {
	Test();
	printf("result : %d\n", result);
}