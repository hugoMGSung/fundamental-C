/* ��������06 */
// char data[a][b][c];  a -> 2,  b -> 3,  c -> 4

#define LIMIT_A     2
#define LIMIT_B     3
#define LIMIT_C     4

#include <stdio.h>
#include <malloc.h>   // malloc, free ���!

void main()
{
    int a, b, c;
    char*** p;

    // *(p+0)�� *(p+1)�� �ش��ϴ� �޸� ����
    p = (char***)malloc(sizeof(char**) * LIMIT_A);

    // *((*p+0)+0)���� *(*(p+1)+2)������ �ش��ϴ� �޸� ����
    for (a = 0; a < LIMIT_A; a++) {
        *(p + a) = (char**)malloc(sizeof(char*) * LIMIT_B);
        // *(*((*p+0)+0)+0)���� *(*(*(p+1)+2)+3)������ �ش��ϴ� �޸� ����
        for (b = 0; b < LIMIT_B; b++) {
            *(*(p + a) + b) = (char*)malloc(sizeof(char) * LIMIT_C);
        }
    }

    // ����� �����Ǿ����� üũ�ϴ� �ڵ�
    for (a = 0; a < LIMIT_A; a++) {
        for (b = 0; b < LIMIT_B; b++) {
            for (c = 0; c < LIMIT_C; c++) {
                // �� �޸𸮰� �Ҵ�� ������ 0, 1, 2, 3... ���� �����Ѵ�.
                // a�� 1 ������ ������ b, c �ݺ����� ���ؼ� LIMIT_B * LIMIT_C��
                // ���� �����ϰ� b�� 1�����Ҷ����� LIMIT_C�� ���� �����ϱ� ������ 
                // ���ԵǴ� ���� (a * LIMIT_B * LIMIT_C) + (b * LIMIT_C) + c�� 
                // ���� �����ϸ� �˴ϴ�.
                *(*(*(p + a) + b) + c) =
                    a * LIMIT_B * LIMIT_C + b * LIMIT_C + c;
            }
        }
    }

    // ������ �ڵ尡 ���������� ��µǴ��� Ȯ���Ѵ�.
    for (a = 0; a < LIMIT_A; a++) {
        printf("*(p+%d)�� �ش��ϴ� �޸� �ּ� = %p\n", a, p + a);
        printf("========================================\n");
        for (b = 0; b < LIMIT_B; b++) {
            printf("*(*(p+%d)+%d)�� �ش��ϴ� �޸� �ּ� = %p\n",
                a, b, *(p + a) + b);
            printf("------------------------------------------------\n");
            for (c = 0; c < LIMIT_C; c++) {
                printf("*(*(*(p+%d)+%d)+%d)�� �ּ�(%p)�� ����� ��(%d)\n",
                    a, b, c, *(*(p + a) + b) + c, *(*(*(p + a) + b) + c));
            }
            printf("\n");
        }
        printf("\n");
    }

    for (a = 0; a < LIMIT_A; a++) {
        for (b = 0; b < LIMIT_B; b++) {
            // *(*((*p+0)+0)+0)���� *(*(*(p+1)+2)+3)������ �ش��ϴ� �޸� ����
            free(*(*(p + a) + b));
        }
        // *((*p+0)+0)���� *(*(p+1)+2)������ �ش��ϴ� �޸� ����
        free(*(p + a));
    }
    // *(p+0)�� *(p+1)�� �ش��ϴ� �޸� ����
    free(p);
}