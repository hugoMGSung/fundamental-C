// 전역변수, 지역변수 실습
#include <stdio.h>
#include "main.h"

void display_localval(int x);
void display_globalval(void);

int x = 0x0000000f;

void main() {
	int x = 0x0000000e;
	printf("x = %d\n", x);
	display_localval(0x0000000d);
	display_globalval();
}

void display_localval(int x)
{
	printf("local x = %d\n", x);
}

void display_globalval(void) {
	printf("global x = %d\n", x);
}