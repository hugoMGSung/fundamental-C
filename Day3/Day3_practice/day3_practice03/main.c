// ���ڿ� ����üũ �Լ� �����
#include <stdio.h>

// MyStringLength �Լ��� strlen �Լ��� ������ ����� �ϴ� �Լ��Դϴ�.
size_t MyStringLength(const char* ap_string)
{
    size_t count = 0;
    while (*ap_string++) count++;

    return count;
}

void main()
{
    char* p = "tipssoft.com";   // üũ�� ���ڿ�
    size_t length = MyStringLength(p);  // p�� ����Ű�� ���ڿ��� ���̸� ���Ѵ�.
    printf("123456789ABCDEF\n");  // ���ڿ��� ���̸� Ȯ���� �� �ֵ��� ȭ�鿡 ����Ѵ�.
    printf("%s\n", p);  // üũ�� ���ڿ� ���
    printf("\ndata length = %d\n", length); // ���ڿ� ���̸� ǥ������
}