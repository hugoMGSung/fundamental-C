#include <stdio.h>

void main()
{
    /* %c�� 65�� ¦�� �̷�� ������ 65�� �ش��ϴ� ASCII �ڵ尪
    A �� ��� �˴ϴ�. */
    printf("65�� ASCII ���� %c �Դϴ�.\n", 65);

    char data = 65;
    /*ù ��° data�� %c�� ¦�� �ǰ� �� ��°�� %d�� ¦�� �̷��.*/
    printf("%c �� ASCII ���� %d �Դϴ�.\n", data, data);
}