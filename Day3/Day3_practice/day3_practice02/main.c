// �����ͷ� ���� �Է��ϱ�
#include <stdio.h>
#include <conio.h>

void MyGetString(char* ap_string)
{
    int key = 0;

    // ����ڿ��� Ű�� �Է� �ް� Enter Ű�� �۾��� �����Ѵ�.
    while ((key = _getche()) != '\r') {
        if (key != 0 && key != 0x00E0) *ap_string++ = key; // Ȯ�� Ű�� �ƴ� ��쿡�� �ش� Ű�� ���ڿ��� �߰��Ѵ�.
        else key = _getche(); // Ȯ�� Ű�� �ΰ��� Ű�� �����Ǳ� ������ �� ��° Ű�� �����Ѵ�.
    }
    // ������ ap_string�� ����Ű�� ��ġ�� �������� �Է��� ���� ���� ��ġ�̱� ������
    // ���� ��ġ�� NULL ���ڸ� �־ ���ڿ��� �ϼ��մϴ�.
    *ap_string = 0;
}

void main()
{
    // �ִ� 31���� ���ڸ� �Է� �޾� ������ �� �ִ�
    char input[32];
    MyGetString(input);  // ���ڿ��� �Է� �޴� �Լ�
    printf("\nInput string : %s\n", input);  // �Էµ� ���ڿ��� ����Ѵ�.
}