/* int�� ������ ����� �� 1����Ʈ ������ ��� */
#include <stdio.h>

void main()
{
    int data = 0x12345678, i;
    char* p = (char*)&data;

    /* 4����Ʈ �����͸� ����Ʈ ������ ���� ����ϱ� ���ؼ� 4�� �ݺ��� */
    for (i = 0; i < 4; i++) {
        /* p�� char *���̶� ����� ���� �ּҿ��� 1����Ʈ ũ�⸸ ��� */
        printf("%X, ", *p);
        p++;  /* p�� char *���̶� 1����Ʈ �ڿ� �ִ� �ּҷ� ���� ����� */
    }
}