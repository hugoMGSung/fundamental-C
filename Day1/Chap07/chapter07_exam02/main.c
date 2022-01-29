/* 산술연산자를 사용하여 사칙연산하기 */
#include <stdio.h>

void main()
{
	int data1 = 5, data2 = 3;   /* 두 변수에 초기값을 5와 3으로 설정 */

	int result1 = data1 + data2;       /* 덧셈           */
	int result2 = data1 * data2;       /* 뺄셈            */
	int result3 = data1 / data2;       /* 나눗셈 (몫)     */
	int result4 = data1 % data2;       /* 나눗셈 (나머지) */

	printf("result : %d, %d, %d, %d\n", result1, result2, result3, result4);
}