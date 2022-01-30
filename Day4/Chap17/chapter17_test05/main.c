/* ��������5 */
#include <stdio.h>
#include <malloc.h>

// ���ÿ� ���� ���� �ϳ� �߰��� �� ����ϴ� �Լ�
// a_num : �߰��� ���� ��, ap_stack : ���� �޸� ������ ���� �ּ�
// ap_data_count : ���ÿ� ����� ������ ������ ����� �޸��� �ּ�
// a_stack_size : ������ ũ�Ⱑ ����� ����
void Push(short a_num, short* ap_stack,
    unsigned short* ap_data_count, unsigned short a_stack_size)
{
    // ���ÿ� �� ������ �ִ� ��쿡�� �Է��� �޴´�.
    if (*ap_data_count < a_stack_size) {
        *(ap_stack + *ap_data_count) = a_num;  // ���ÿ� ���ο� ���� �����Ѵ�.
        (*ap_data_count)++;  // ����� ������ ������Ų��.  
    }
    else printf("Stack�� �������� ���� �� �̻� ���� �� �����ϴ�\n");
}

// ���ÿ��� �������� �Էµ� ���� ���� �ϳ� �������� �Լ�
// ap_num : ���ÿ��� ������ �������� ����� �ּ�
// ap_stack : ���� �޸� ������ ���� �ּ�
// ap_data_count : ���ÿ� ����� ������ ������ ����� �޸��� �ּ�
// a_stack_size : ������ ũ�Ⱑ ����� ����
// ���ÿ��� ���� ���� ���������� �������� 1�� ��ȯ�ϰ� �����ϸ� 0�� ��ȯ�Ѵ�.
short Pop(short* ap_num, short* ap_stack,
    unsigned short* ap_data_count, unsigned short a_stack_size)
{
    if (*ap_data_count == 0) {  // ���ÿ� ����� ���� ���� ���
        printf("Stack�� ����� ���� �����ϴ�.\n");
        return 0;
    }

    (*ap_data_count)--;  // ���ÿ� ����� ������ ������ ����
    // �������� ����Ǿ� �ִ� �������� ������
    *ap_num = *(ap_stack + *ap_data_count);
    return 1;
}

// ���ÿ� �ִ� ������ ����ϴ� �Լ�
// ap_stack : ���� �޸� ������ ���� �ּ�
// a_data_count : ���� ���ÿ� ����� ������ ����
void ShowStack(short* ap_stack, unsigned short a_data_count)
{
    int i;

    if (a_data_count == 0) printf("Stack�� ����� ���� �����ϴ�.\n");
    else {
        printf("Stack�� ����� �� ���\n");
        for (i = 0; i < a_data_count; i++) {
            printf("[%03d] : %d\n", i + 1, ap_stack[i]);
        }
        printf("�� %d���� ���� ���� �Ǿ� �ֽ��ϴ�.\n", a_data_count);
    }
}

void main(void)
{
    // ���ÿ� ����� �������� ������ ������ ũ�⸦ ������ ����
    unsigned short count = 0, stack_size = 0;
    // �޴� �׸��� �����Ҷ� ����� ������ ���� �Է¹��� �� ����� ����
    short select_index = 0, temp = 0;
    short* p_stack;     // �������� ����� �޸� ������ ����ų ������

    printf("Stack�� ũ�⸦ �Է��ϼ��� : ");
    scanf_s("%hu", &stack_size);
    p_stack = (short*)malloc(sizeof(short) * stack_size);

    while (select_index != 9) {
        // ����ڿ��� ������ �� �ִ� ����� �����ش�.
        printf("\n\n1. Stack�� �� �ֱ�\n");
        printf("2. Stack���� �� ������\n");
        printf("3. Stack�� ����� �� Ȯ��\n");
        printf("9. ���α׷� ����\n\n");
        printf("���� : ");
        scanf_s("%hd", &select_index); // ����ڰ� ������ �޴����� ��´�.

        switch (select_index) {
        case 1: // ����ڰ� �Է��� ���� ���ÿ� �����Ѵ�.
            printf("������ ���� �Է��ϼ��� : ");
            scanf_s("%hd", &temp);
            Push(temp, p_stack, &count, stack_size);
            break;
        case 2: // ���ÿ� ����� �������� �����´�.
            if (Pop(&temp, p_stack, &count, stack_size)) {
                printf("������ �� -> %d", temp);
            }
            break;
        case 3: // ���ÿ� ����� ������ �����ش�.
            ShowStack(p_stack, count);
            break;
        }
    }

    free(p_stack);
}