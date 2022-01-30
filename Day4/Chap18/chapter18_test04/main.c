/* ��������4 */
#include <stdio.h>             // printf �Լ�, scanf_s �Լ��� ����ϱ� ����!
#include <malloc.h>            // malloc �Լ��� ����ϱ� ����!
#include <memory.h>            // memcpy �Լ��� ����ϱ� ����!

#define MAX_NAME_LENGTH  12    // �ִ� 12�ڱ����� �Է� �޴´�.

typedef struct StudentData
{
    char name[MAX_NAME_LENGTH];  // �̸��� ������ ����
    int kor, eng, math;          // ����, ����, ���� ������ ������ ����
    int total;                   // ������ ������ ����
    int ranking;                 // ����� ������ ����
    float average;               // ����� ������ ����

} SD;

typedef struct node
{
    SD data;                     // �л� ������ ����� ����
    struct node* p_next;         // ���� ��带 ����ų ������
} NODE;

void AddNode(NODE** ap_head, NODE** ap_tail, SD* ap_data)
{
    if (NULL != *ap_head) {
        (*ap_tail)->p_next = (NODE*)malloc(sizeof(NODE));  // �� ��带 �Ҵ���!
        *ap_tail = (*ap_tail)->p_next;  // �߰��� ���� tail �����͸� �ű��.
    }
    else {
        *ap_head = (NODE*)malloc(sizeof(NODE)); // ù ��带 �Ҵ���!
        *ap_tail = *ap_head;  // ù ��带 head�� tail ������ ��� ����Ŵ
    }
    // �߰��� ��忡 �л� ������ �����Ѵ�.
    memcpy(&(*ap_tail)->data, ap_data, sizeof(SD));
    // �߰��� ����� ���� ��尡 ������ ����Ѵ�!
    (*ap_tail)->p_next = NULL;
}

void DeleteAllNode(NODE** ap_head, NODE** ap_tail)
{
    NODE* p = *ap_head, * p_save_next;

    // ���� ������ ������ ������ �̵��ϵ��� �ݺ����� ������
    while (NULL != p) {
        // ������ P�� ����Ű�� ����� ����(free)�Ǹ� p->p_next�� ����Ű��
        // ����� ã�ư��� ���� ������ p->p_next�� p_save_next�� �����Ѵ�.
        p_save_next = p->p_next;
        // p�� ����Ű�� ��带 ������
        free(p);
        // p�� ����Ű�� ���� ����� �ּҸ� p�� ������
        p = p_save_next;
    }

    // ��� ��尡 �����Ǿ��� ������ head�� tail �����͸� �ʱ�ȭ�Ѵ�.
    *ap_head = *ap_tail = NULL;
}

void UpdateRanking(NODE* ap_head, SD* ap_data)
{
    NODE* p = ap_head;
    // ��� ��ü�� �̵��ϸ鼭 ����� �����Ѵ�.
    while (NULL != p) {
        if (ap_data->total < p->data.total) {
            // ���� �߰��� ����(ap_data)�� ���� ����� ����(p)����
            // �۴ٸ� ���� �߰��� ������ ����� ������Ų��.
            ap_data->ranking++;
        }
        else {
            // ���� ����� ������ ���� �߰��� �������� �۴ٸ� 
            // ���� ����� ����� ������Ų��.
            p->data.ranking++;
        }
        // ���� ���� �̵��Ѵ�.
        p = p->p_next;
    }
}

void InputData(SD* ap_data, int a_count)
{
    printf("%d ��° �л� �̸� : ", a_count);
    scanf_s("%s", ap_data->name, MAX_NAME_LENGTH);
    printf("���� ���� : ");
    scanf_s("%d", &ap_data->kor);
    printf("���� ���� : ");
    scanf_s("%d", &ap_data->eng);
    printf("���� ���� : ");
    scanf_s("%d", &ap_data->math);

    // �ڽ��� �⺻ ��ŷ�� 1���̴�.
    ap_data->ranking = 1;
    // ������ ����Ѵ�.
    ap_data->total = ap_data->kor + ap_data->eng + ap_data->math;
    // ����� ����Ѵ�.
    ap_data->average = ap_data->total / 3.0f;
}

void DisplayData(NODE* ap_head)
{
    NODE* p = ap_head;

    printf("-----------------------------------------------\n");
    printf(" �̸�     ����  ����  ����  ����   ���   ���\n");
    printf("-----------------------------------------------\n");
    // ��� ��ü�� �̵��ϸ鼭 ����� �����Ѵ�.
    while (NULL != p) {
        printf(" %-8s %3d   %3d   %3d   %3d    %3.0f   %2d��\n",
            p->data.name, p->data.kor, p->data.eng, p->data.math,
            p->data.total, p->data.average, p->data.ranking);

        // ���� ���� �̵��Ѵ�.
        p = p->p_next;
    }
}

int main()
{
    NODE* p_head = NULL, * p_tail = NULL;
    SD temp;
    int num, count = 0;

    while (1) {
        printf("[ Menu ]\n");
        printf("1. ���� �Է�\n");
        printf("2. ���� Ȯ��\n");
        printf("3. ����\n");
        printf("--------------\n");
        printf("����(1 ~ 3) : ");

        scanf_s("%d", &num);

        printf("\n\n");

        if (num == 3) break;
        else if (num == 1) {
            // ������ �Է� �޴´�.
            InputData(&temp, ++count);
            // �� ����� ����� �����Ѵ�.
            UpdateRanking(p_head, &temp);
            // ���� �Է��� ������ ���� ����Ʈ�� �߰��Ѵ�.
            AddNode(&p_head, &p_tail, &temp);
        }
        else if (num == 2) {
            // �� ��忡 ����� ���� ������ ����Ѵ�.
            DisplayData(p_head);
        }
        printf("\n\n");
    }

    DeleteAllNode(&p_head, &p_tail);
    return 0;
}