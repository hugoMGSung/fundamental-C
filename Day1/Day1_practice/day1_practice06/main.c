//
#include <stdio.h>  // printf �Լ��� ����ϱ� ����
#include <conio.h>  // getche �Լ��� ����ϱ� ����

void main()
{
    // �ִ� 31���� ���ڸ� �Է� �޾� ������ �� �ִ�
    char input[32];
    int i = 0, key = 0;

    // ����ڿ��� Ű�� �Է� �ް� Enter Ű�� �۾��� �����Ѵ�.
    while ((key = getche()) != '\r') {
        if (key != 0 && key != 0x00E0) input[i++] = key; // Ȯ�� Ű�� �ƴ� ��쿡�� �ش� Ű�� ���ڿ��� �߰��Ѵ�.
        else key = getche(); // Ȯ�� Ű�� �ΰ��� Ű�� �����Ǳ� ������ �� ��° Ű�� �����Ѵ�.
    }
    // i�� ����Ű�� ��ġ�� �������� �Է��� ���� ���� ��ġ�̱� ������
    // input[i]�� NULL ���ڸ� �־ ���ڿ��� �ϼ��մϴ�.
    input[i] = 0;
    printf("\nInput string : %s\n", input);  // �Էµ� ���ڿ��� ����Ѵ�.
}