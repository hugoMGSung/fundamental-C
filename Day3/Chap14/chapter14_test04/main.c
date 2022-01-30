#include <stdio.h>   // printf�� scanf �Լ� ����ϱ� ����
#include <string.h>  // strcpy �Լ��� ����ϱ� ����

#define MAX_STUDENT_COUNT    3
#define MAX_NAME_LENGTH      10

#define PART_COUNT           4
#define PART_DATA_SIZE       sizeof(int)*PART_COUNT

#define KOR     0  // ���� ������ ��ġ
#define ENG     1  // ���� ������ ��ġ
#define MATH    2  // ���� ������ ��ġ
#define TOTAL   3  // ���� ������ ��ġ

void SwapScore(int a_score1[], int a_score2[])
{
    int temp[PART_COUNT];
    // a_score1�� ����� �������� ��� temp�� �ű��.
    memcpy(temp, a_score1, PART_DATA_SIZE);
    // a_score2�� ����� �������� ��� a_score1�� �ű��.
    memcpy(a_score1, a_score2, PART_DATA_SIZE);
    // temp�� ����� �������� ��� a_score2�� �ű��.
    memcpy(a_score2, temp, PART_DATA_SIZE);
}

void InputData(char a_name[][MAX_NAME_LENGTH], int a_score[][PART_COUNT])
{
    int i;
    // �л����� ���������� student_count ��ŭ �Է¹޴´�.
    for (i = 0; i < MAX_STUDENT_COUNT; i++) {
        printf("%d ��° �л� �̸� : ", i + 1);
        scanf("%s", a_name + i);// scanf("%s", &a_name[i]); �� ������ ǥ��
        // ���� ���� �Է�
        printf("���� ���� : ");
        scanf("%d", a_score[i] + KOR); // scanf("%d", &a_score[i][KOR]); �� ������ ǥ��
        printf("���� ���� : ");
        scanf("%d", a_score[i] + ENG); // scanf("%d", &a_score[i][ENG]); �� ������ ǥ��
        printf("���� ���� : ");
        scanf("%d", a_score[i] + MATH);// scanf("%d", &a_score[i][MATH]); �� ������ ǥ��
        // �Է¹��� ����, ����, ����, ���� ������ ������ ���Ѵ�.
        a_score[i][TOTAL] = a_score[i][KOR] + a_score[i][ENG] + a_score[i][MATH];
        // ������ ����.
        printf("\n");
    }
}

void DisplayData(char a_name[][MAX_NAME_LENGTH], int a_score[][PART_COUNT])
{
    int i;

    printf("  -----------------------------------------------------------------\n");
    printf("    �̸�    ����  ����  ����  ����  ���  ���\n");
    printf("  -----------------------------------------------------------------\n");
    for (i = 0; i < MAX_STUDENT_COUNT; i++) {
        // �̸��� ����Ѵ�.
        printf("%9s   %3d   %3d   %3d   %3d   %3d %3d��\n",
            a_name[i], a_score[i][KOR], a_score[i][ENG], a_score[i][MATH],
            a_score[i][TOTAL], a_score[i][TOTAL] / MAX_STUDENT_COUNT, i + 1);
    }
}

void main()
{
    char name[MAX_STUDENT_COUNT][MAX_NAME_LENGTH];  // �̸��� ������ ����
    // ����, ����, ����, ������ �ѹ��� ������ ����
    int score[MAX_STUDENT_COUNT][PART_COUNT];
    // �л����� ������ �Է¹޴´�.
    InputData(name, score);
    // ������ ����.
    printf("\n");
    // ó���� ��������ϱ�
    DisplayData(name, score);
}