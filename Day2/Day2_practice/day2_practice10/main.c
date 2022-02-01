#include <stdio.h>

void test_global(void);   // 다른 소스의 함수 호출을 위해서는 함수 선언 필요

extern int global;		// global 변수가 있다라는 명시

void main() {
	test_global();
	printf("global = %d\n", global);
}