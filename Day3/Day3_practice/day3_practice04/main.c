// �������� �Է¹޾� �迭�� ����
#include <stdio.h>
// �ִ� 100������ ���� �Է� �޾� �����Ѵ�.
#define MAX_COUNT   100

int main()
{
    int count = 0, num, i = 0;
    // ����ڰ� �Է��� ���� ������ �迭
    int data[MAX_COUNT];
    // �ִ� 100ȸ���� �Է� �޴´�.
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
            // ������ ��Ͽ� �Էµ� ���� �߰��ϰ� ������ ������ ������Ų��.
            data[count++] = num;
        }
    }

    // ���� ��Ͽ� �߰��� ������ ����Ѵ�.
    while (i < count) printf("%d, ", data[i++]);
    printf("\n");
    return 0;
}