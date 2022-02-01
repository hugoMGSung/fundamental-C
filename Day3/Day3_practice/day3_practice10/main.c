// ����
#include <stdio.h>  // printf �Լ��� scnaf_s �Լ��� ����ϱ� ���Ͽ�!

float calc(float a_num1, float a_num2, char a_op_type)
{
    float result;

    switch (a_op_type)
    {
    case '+':  // ���� ������ �Ѵ�.
        result = a_num1 + a_num2;
        break;
    case '-':   // ���� ������ �Ѵ�.
        result = a_num1 - a_num2;
        break;
    case '*':   // ���� ������ �Ѵ�.
        result = a_num1 * a_num2;
        break;
    case '/':   // ������ ������ �Ѵ�.
        if (a_num2 == 0) { // 0���� ������ ���� �����Ѵ�!
            printf("[����] : 0���� ������ �ȵ˴ϴ�!\n");
            return 0;
        }
        result = a_num1 / a_num2;
        break;
    default:
        result = 0;
    }

    return result;
}

void main()
{
    // �����ڸ� ������ ����
    char op_type;
    // �ǿ����� �� ���� ���� ������ ����
    float num1, num2, result;

    printf("������ �Է� : ");
    // �����ڸ� �Է� �޴´�.
    scanf_s("%c", &op_type, 1);
    // �����ڿ� �Բ� �Էµ� ����Ű ����
    rewind(stdin);

    printf("�� ���� ������ �� �Է� : ");
    // �ǿ����ڸ� �� �� �Է� �޴´�.
    scanf_s("%f %f", &num1, &num2);

    result = calc(num1, num2, op_type);
    printf("result : %g\n", result);
}