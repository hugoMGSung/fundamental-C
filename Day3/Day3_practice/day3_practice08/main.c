// 2���� ���ڿ��� ���ڷ� ����
#include <stdio.h>    // printf �Լ��� ����ϱ� ����

int main()
{
    char str[5] = "1011"; // 2���� ������ ���ڿ�
    int num = 0, i;

    // 2���� ������ ���ڿ��� ������ �����Ѵ�.
    for (i = 0; i < sizeof(str)-1; i++) {
        num = (num << 1) + str[i] - '0';
    }

    // ������ �ٲ� ���� 10������ 16���� ���·� ����Ѵ�.
    printf("Decimal = %d, Hexa = 0x%02X\n", num, num);
    return 0;
}