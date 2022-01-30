/* 연습문제 3 */
#include <stdio.h>

void Test() {
	static int data = 0;
	printf("%d, ", data++);
}

void main(void) {
	for (int i = 0; i < 5; i++) Test();
}