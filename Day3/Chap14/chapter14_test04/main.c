#include <stdio.h>   // printf와 scanf 함수 사용하기 위해
#include <string.h>  // strcpy 함수를 사용하기 위해

#define MAX_STUDENT_COUNT    3
#define MAX_NAME_LENGTH      10

#define PART_COUNT           4
#define PART_DATA_SIZE       sizeof(int)*PART_COUNT

#define KOR     0  // 국어 성적의 위치
#define ENG     1  // 영어 성적의 위치
#define MATH    2  // 수학 성적의 위치
#define TOTAL   3  // 총점 성적의 위치

void SwapScore(int a_score1[], int a_score2[])
{
    int temp[PART_COUNT];
    // a_score1에 저장된 점수들을 모두 temp로 옮긴다.
    memcpy(temp, a_score1, PART_DATA_SIZE);
    // a_score2에 저장된 점수들을 모두 a_score1로 옮긴다.
    memcpy(a_score1, a_score2, PART_DATA_SIZE);
    // temp에 저장된 점수들을 모두 a_score2로 옮긴다.
    memcpy(a_score2, temp, PART_DATA_SIZE);
}

void InputData(char a_name[][MAX_NAME_LENGTH], int a_score[][PART_COUNT])
{
    int i;
    // 학생별로 성적정보를 student_count 만큼 입력받는다.
    for (i = 0; i < MAX_STUDENT_COUNT; i++) {
        printf("%d 번째 학생 이름 : ", i + 1);
        scanf("%s", a_name + i);// scanf("%s", &a_name[i]); 와 동일한 표현
        // 과목별 성적 입력
        printf("국어 점수 : ");
        scanf("%d", a_score[i] + KOR); // scanf("%d", &a_score[i][KOR]); 와 동일한 표현
        printf("영어 점수 : ");
        scanf("%d", a_score[i] + ENG); // scanf("%d", &a_score[i][ENG]); 와 동일한 표현
        printf("수학 점수 : ");
        scanf("%d", a_score[i] + MATH);// scanf("%d", &a_score[i][MATH]); 와 동일한 표현
        // 입력받은 국어, 영어, 수학, 과학 점수의 총점을 구한다.
        a_score[i][TOTAL] = a_score[i][KOR] + a_score[i][ENG] + a_score[i][MATH];
        // 한줄을 띄운다.
        printf("\n");
    }
}

void DisplayData(char a_name[][MAX_NAME_LENGTH], int a_score[][PART_COUNT])
{
    int i;

    printf("  -----------------------------------------------------------------\n");
    printf("    이름    국어  영어  수학  총점  평균  등수\n");
    printf("  -----------------------------------------------------------------\n");
    for (i = 0; i < MAX_STUDENT_COUNT; i++) {
        // 이름을 출력한다.
        printf("%9s   %3d   %3d   %3d   %3d   %3d %3d등\n",
            a_name[i], a_score[i][KOR], a_score[i][ENG], a_score[i][MATH],
            a_score[i][TOTAL], a_score[i][TOTAL] / MAX_STUDENT_COUNT, i + 1);
    }
}

void main()
{
    char name[MAX_STUDENT_COUNT][MAX_NAME_LENGTH];  // 이름을 저장할 변수
    // 국어, 영어, 수학, 총점을 한번에 저장할 변수
    int score[MAX_STUDENT_COUNT][PART_COUNT];
    // 학생들의 성적을 입력받는다.
    InputData(name, score);
    // 한줄을 띄운다.
    printf("\n");
    // 처리된 성적출력하기
    DisplayData(name, score);
}