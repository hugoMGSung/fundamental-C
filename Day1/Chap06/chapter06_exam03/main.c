#include <stdio.h>

void main()
{
    float value = 2.1f;
    printf("%f\n", value);
    /* value ���� ���� �Ǽ� ���İ� ���� �������� ��� ��*/
    printf("%f, %d\n", value, value);

    int data1 = -1;
    unsigned int data2 = 4294967295;
    printf("%d, %u, %d, %u\n", data1, data1, data2, data2);
}