#include <stdio.h>

void main()
{
    int data = 7;
    /* �ڸ��� Ȯ���� ���� [ ] ���ڸ� ����� */
    printf("[%d] [%5d] \n", data, data);
    /* �ڸ��� Ȯ���� ���� [ ] ���ڸ� ����� */
    printf("[%5d] [%05d] [%-5d]\n", data, data, data);

    double data1 = 3.141592;
    /* �ڸ��� Ȯ���� ���� [ ] ���ڸ� ����� */
    printf("[%f] [%.4f] [%8.4f] [%-8.4f]\n", data1, data1, data1, data1);
}