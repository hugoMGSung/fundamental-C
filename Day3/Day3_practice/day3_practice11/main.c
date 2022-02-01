// �Է��� ���ڿ� ����� ���
#include <stdio.h>           // printf �Լ�, scanf_s �Լ��� ����ϱ� ����!
#define MAX_LENGTH     64    // �ִ� 64�ڱ����� �Է� �޴´�.

// a_str ����� ���ڿ��� ������ ����Ѵ�.
void PrintResersedString(char a_str[])
{
    int i, len = 0;
    // a_str�� ����� ���ڿ��� ����� ������ �迭�� �����Ѵ�.
    char resersed_str[MAX_LENGTH];

    // ����ڰ� �Է��� str �迭�� �Էµ� ���ڿ��� ���̸� ���Ѵ�.
    while (a_str[len] != 0) len++;

    // a_str�� ����� ���ڸ� resersed_str�� �ڿ������� �����Ͽ� �����´�.
    for (i = 0; i < len; i++) {
        resersed_str[len - i - 1] = a_str[i];
    }
    // resersed_str ���ڿ��� ���� NULL ���ڸ� �߰��Ѵ�.
    resersed_str[i] = 0;
    // ������ ���ڿ��� ����Ѵ�.
    printf("%s\n", resersed_str);
}

void main()
{
    char str[MAX_LENGTH];

    printf("Input String : ");
    // scanf �Լ��� ����Ϸ��� scanf("%[^\n]s", str); ��� ������ �˴ϴ�.
    // %s��� ������ ������ �����ڷ� ���� �Է��� ��������� �ޱ� ������ 
    // �Ʒ��� ���� '���� ������'�� ����ؾ��� ���鵵 �����ؼ� �Է� �޽��ϴ�.
    scanf_s("%[^\n]s", str, MAX_LENGTH - 1);

    printf("-> ");
    // str ������ ����� ���ڿ��� ������ ����Ѵ�.
    PrintResersedString(str);
}