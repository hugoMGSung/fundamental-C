#include <stdio.h>

void main()
{
    float value = 2.1f;
    printf("%f\n", value);
    /* value 변수 값을 실수 형식과 정수 형식으로 출력 함*/
    printf("%f, %d\n", value, value);

    int data1 = -1;
    unsigned int data2 = 4294967295;
    printf("%d, %u, %d, %u\n", data1, data1, data2, data2);
}