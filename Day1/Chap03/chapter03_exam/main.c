/* 자료형 */
#include <stdio.h>

void main(void) {
	printf("정수타입\n");

	signed char temp = -2;
	printf("signed char %d\n", temp);
	unsigned char age;
	age = 52;
	printf("unsigned char %d\n", age);

	signed short int dday;
	dday = -20;
	printf("signed short int %d\n", dday);
	unsigned short int seconds;
	seconds = 35000;
	printf("unsigned short int %d\n", seconds);

	signed long int money;
	money = 7000000;
	printf("signed long int %d\n", money);
	unsigned long int time_seconds;
	time_seconds = 1453100624;
	printf("unsigned long int %d\n", time_seconds);
	
	printf("실수타입\n");
	float pi;
	pi = 3.141592654;
	printf("float %2.9f\n", pi);
	double dpi;
	dpi = 3.141592654;
	printf("double %2.9f\n", dpi);
}