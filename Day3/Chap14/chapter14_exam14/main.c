/* 공백문자로 구분 scanf 함수로 8,10,16진수 입력 */
#include <stdio.h>

void main()
{
	int num1, num2, num3;
	scanf("%o %d %x", &num1, &num2, &num3); /* 8, 10, 16진수 값 입력받음 */
	printf("input : %d, %d, %d \n", num1, num2, num3);
}