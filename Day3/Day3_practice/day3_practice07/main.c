// ���� �޸� �Ҵ��Ͽ� ������ �ջ�
#include <stdio.h>    // printf, scanf_s �Լ��� ����ϱ� ����
#include <malloc.h>   // malloc �Լ��� ����ϱ� ����

int main()
{
    int count, i, sum = 0;
    int* p;

    printf("�� ���� ������ �Է��Ͻðڽ��ϱ�? ");
    scanf_s("%d", &count);

    if (count > 0) {
        // �Է� ���� ������ŭ int ũ���� �޸𸮸� �Ҵ��Ѵ�.
        p = malloc(sizeof(int) * count);
        if (p != NULL) {  // ���������� �޸𸮰� �Ҵ�Ǿ��ٸ�!
            // ����ڰ� �Է��� ������ŭ �������� �Է¹޴´�.
            for (i = 0; i < count; i++) {
                printf("%d��° ���� �Է� : ", i + 1);
                scanf_s("%d", &*(p + i)); // p + i�� &*(p+1)�� �ٿ��� ǥ����
            }
            // ����ڰ� �Է��� ���� Ȯ���Ѵ�.
            printf("\n�Էµ� �� Ȯ�� : ");
            for (i = 0; i < count; i++) {
                printf("%d, ", *(p + i));
            }

            printf("\n�Էµ� ���� ��� �ջ��մϴ�.\n");
            for (i = 0; i < count; i++) {
                printf("%d", *(p + i));
                // i��° �Է��� ���� sum ������ �ջ��Ѵ�.
                sum = sum + *(p + i);
                // �߰����� ��� '+' ���ڸ� ����ϴٰ� ���������� '=' ���ڸ� �����
                if (i < count - 1) printf(" + ");
                else printf(" = ");
            }
            // �ջ�� ��� ���� ����Ѵ�.
            printf("%d\n", sum);

            free(p);  // �����Ҵ�� �޸𸮸� �����Ѵ�.
        }
    }
    return 0;
}