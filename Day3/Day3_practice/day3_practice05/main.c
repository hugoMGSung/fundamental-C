// ���� �Է¹޾� �����ϸ鼭 
#include <stdio.h>
// �ִ� 100������ ���� �Է� �޾� �����Ѵ�.
#define MAX_COUNT   100

void DisplayList(int a_data[], int a_count)
{
    int i;
    // ���� ��Ͽ� �߰��� ������ ����Ѵ�.
    for (i = 0; i < a_count; i++) printf("%d, ", a_data[i]);
    printf("\n");
}

void InsertData(int a_data[], int a_count, int a_num)
{
    int insert, i;

    // ���� �Էµ� ���� ���� �Է� ���� �� ��Ͽ��� 
    // � ��ġ�� �����ϴ��� ã�´�.
    for (insert = 0; insert < a_count; insert++) {
        if (a_num < a_data[insert]) break;
    }

    // insert ��ġ�� num ���� �Է��ϱ� ���ؼ� insert �ڿ� 
    // �ִ� ������ �ϳ��� �ڷ� �̵���Ų��. 
    for (i = a_count; i > insert; i--) a_data[i] = a_data[i - 1];

    // insert ��ġ�� num ���� �Է��Ѵ�.
    a_data[insert] = a_num;
}

int main()
{
    int count = 0, num;
    // ����ڰ� �Է��� ���� ������ �迭
    int data[MAX_COUNT];

    while (count < MAX_COUNT) {
        // �Է� ������ ����Ѵ�.
        printf("Input Data (Exit -> 9999) : ");
        // ����ڿ��� �������� �Է� �޴´�.
        if (scanf_s("%d", &num) == 0) {
            // ����ڰ� �������� �ƴ� �ٸ� ������ ���� �Է��� ���!
            printf("Invalid Number!! Try again!!\n");
            // ǥ�� �Է� ���۸� �ǰ��Ƽ� �ʱ�ȭ ȿ���� �ش�!
            rewind(stdin);
        }
        else {
            if (num == 9999) break;  //  9999�� �Է��ϸ� �����Ѵ�.

            InsertData(data, count, num);
            // ������ ��Ͽ� �߰��� ������ ������ ������Ų��.
            count++;
            DisplayList(data, count);
        }
    }

    DisplayList(data, count);
    return 0;
}