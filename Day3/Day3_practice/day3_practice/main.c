// ���ڿ� �迭�� ����Ͽ� day1_practice06�� �Լ� �߰�
#include <stdio.h>
#include <conio.h>

void MyGetString(char a_string[])
{
    int i = 0, key = 0;

    // ����ڿ��� Ű�� �Է� �ް� Enter Ű�� �۾��� �����Ѵ�.
    while ((key = _getche()) != '\r') {
        if (key != 0 && key != 0x00E0) a_string[i++] = key; // Ȯ�� Ű�� �ƴ� ��쿡�� �ش� Ű�� ���ڿ��� �߰��Ѵ�.
        else key = _getche(); // Ȯ�� Ű�� �ΰ��� Ű�� �����Ǳ� ������ �� ��° Ű�� �����Ѵ�.
    }
    // i�� ����Ű�� ��ġ�� �������� �Է��� ���� ���� ��ġ�̱� ������
    // input[i]�� NULL ���ڸ� �־ ���ڿ��� �ϼ��մϴ�.
    a_string[i] = 0;
}

void main()
{
    // �ִ� 31���� ���ڸ� �Է� �޾� ������ �� �ִ�
    char input[32];
    MyGetString(input);  // ���ڿ��� �Է� �޴� �Լ�
    printf("\nInput string : %s\n", input);  // �Էµ� ���ڿ��� ����Ѵ�.
}