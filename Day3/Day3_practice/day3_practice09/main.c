// 2��°
#include <stdio.h> // printf, gets_s �Լ��� ����ϱ� ����
#define MAX_BIT_COUNT    33

int main()
{
    char str[MAX_BIT_COUNT]; // 2���� ������ ���ڿ��� ������ ����
    char* p = str;           // str �迭�� �����ּҸ� ������ p�� ����
    int num = 0, i;

    printf("Input Bit : ");
    gets_s(str, MAX_BIT_COUNT);  // ���ڿ��� �Է� �޴´�!

    // 2���� ������ ���ڿ��� ������ �����Ѵ�.
    for (i = 0; *p; i++) {
        num = (num << 1) + *p - '0';
        p++;  // ���� ���ڷ� �̵��Ѵ�.
    }

    // ������ �ٲ� ���� 10������ 16���� ���·� ����Ѵ�.
    printf("Decimal = %d, Hexa = 0x%X\n", num, num);
    return 0;
}