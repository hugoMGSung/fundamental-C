/* scanf함수를 사용, 정수와 실수값 입력 */
#include <stdio.h>

void main()
{
    int int_data;
    float float_data;

    scanf("%d", &int_data);    /* 정수 값을 입력 받는다 */
    scanf("%f", &float_data);  /* 실수 값을 입력 받는다 */

    printf("input : %d, %f\n", int_data, float_data);
}