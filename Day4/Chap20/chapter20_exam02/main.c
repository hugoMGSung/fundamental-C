/* �ݹ��Լ� */
#include <stdio.h>

// PrintValue �Լ��� ���̺귯������ ������!
void PrintValue(int a_value, void (*ap_modify)(int*));

// ModifyValue �Լ��� ���̺귯�� ����ڰ� �ʿ信 ���ؼ� �������!
void ModifyValue(int* ap_value)
{
    // ap_value �����Ͱ� ����Ű�� ����� �����̸� ����� �����Ѵ�.
    if (*ap_value < 0) *ap_value = *ap_value * (-1);
}

int main()
{
    int value = -5;

    PrintValue(value, NULL);   // -5��� ��µ�!
    // PrintValue �Լ����� �Լ� �����Ϳ� ���� ModifyValue �Լ��� ȣ��Ǿ�
    // -5���� 5���� ����˴ϴ�. �׷��� 5��� ��µ�!
    PrintValue(value, ModifyValue);
    return 0;
}