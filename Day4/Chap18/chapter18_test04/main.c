/* 연습문제4 */
#include <stdio.h>             // printf 함수, scanf_s 함수를 사용하기 위해!
#include <malloc.h>            // malloc 함수를 사용하기 위해!
#include <memory.h>            // memcpy 함수를 사용하기 위해!

#define MAX_NAME_LENGTH  12    // 최대 12자까지만 입력 받는다.

typedef struct StudentData
{
    char name[MAX_NAME_LENGTH];  // 이름을 저장할 변수
    int kor, eng, math;          // 국어, 영어, 수학 성적을 저장할 변수
    int total;                   // 총점을 저장할 변수
    int ranking;                 // 등수를 저장할 변수
    float average;               // 평균을 저장할 변수

} SD;

typedef struct node
{
    SD data;                     // 학생 정보를 기록할 변수
    struct node* p_next;         // 다음 노드를 가리킬 포인터
} NODE;

void AddNode(NODE** ap_head, NODE** ap_tail, SD* ap_data)
{
    if (NULL != *ap_head) {
        (*ap_tail)->p_next = (NODE*)malloc(sizeof(NODE));  // 새 노드를 할당함!
        *ap_tail = (*ap_tail)->p_next;  // 추가된 노드로 tail 포인터를 옮긴다.
    }
    else {
        *ap_head = (NODE*)malloc(sizeof(NODE)); // 첫 노드를 할당함!
        *ap_tail = *ap_head;  // 첫 노드를 head와 tail 포인터 모두 가리킴
    }
    // 추가된 노드에 학생 정보를 저장한다.
    memcpy(&(*ap_tail)->data, ap_data, sizeof(SD));
    // 추가된 노드의 다음 노드가 없음을 명시한다!
    (*ap_tail)->p_next = NULL;
}

void DeleteAllNode(NODE** ap_head, NODE** ap_tail)
{
    NODE* p = *ap_head, * p_save_next;

    // 시작 노드부터 마지막 노드까지 이동하도록 반복문을 구성함
    while (NULL != p) {
        // 포인터 P가 가리키는 대상이 해제(free)되면 p->p_next로 가리키던
        // 대상을 찾아갈수 없기 때문에 p->p_next를 p_save_next에 저장한다.
        p_save_next = p->p_next;
        // p가 가리키는 노드를 삭제함
        free(p);
        // p가 가리키던 다음 노드의 주소를 p에 대입함
        p = p_save_next;
    }

    // 모든 노드가 삭제되었기 때문에 head와 tail 포인터를 초기화한다.
    *ap_head = *ap_tail = NULL;
}

void UpdateRanking(NODE* ap_head, SD* ap_data)
{
    NODE* p = ap_head;
    // 노드 전체를 이동하면서 등수를 갱신한다.
    while (NULL != p) {
        if (ap_data->total < p->data.total) {
            // 새로 추가될 점수(ap_data)가 현재 노드의 점수(p)보다
            // 작다면 새로 추가될 점수의 등수를 증가시킨다.
            ap_data->ranking++;
        }
        else {
            // 현재 노드의 점수가 새로 추가될 점수보다 작다면 
            // 현재 노드의 등수를 증가시킨다.
            p->data.ranking++;
        }
        // 다음 노드로 이동한다.
        p = p->p_next;
    }
}

void InputData(SD* ap_data, int a_count)
{
    printf("%d 번째 학생 이름 : ", a_count);
    scanf_s("%s", ap_data->name, MAX_NAME_LENGTH);
    printf("국어 점수 : ");
    scanf_s("%d", &ap_data->kor);
    printf("영어 점수 : ");
    scanf_s("%d", &ap_data->eng);
    printf("수학 점수 : ");
    scanf_s("%d", &ap_data->math);

    // 자신의 기본 랭킹은 1등이다.
    ap_data->ranking = 1;
    // 총점을 계산한다.
    ap_data->total = ap_data->kor + ap_data->eng + ap_data->math;
    // 평균을 계산한다.
    ap_data->average = ap_data->total / 3.0f;
}

void DisplayData(NODE* ap_head)
{
    NODE* p = ap_head;

    printf("-----------------------------------------------\n");
    printf(" 이름     국어  영어  수학  총점   평균   등수\n");
    printf("-----------------------------------------------\n");
    // 노드 전체를 이동하면서 등수를 갱신한다.
    while (NULL != p) {
        printf(" %-8s %3d   %3d   %3d   %3d    %3.0f   %2d등\n",
            p->data.name, p->data.kor, p->data.eng, p->data.math,
            p->data.total, p->data.average, p->data.ranking);

        // 다음 노드로 이동한다.
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
        printf("1. 성적 입력\n");
        printf("2. 성적 확인\n");
        printf("3. 종료\n");
        printf("--------------\n");
        printf("선택(1 ~ 3) : ");

        scanf_s("%d", &num);

        printf("\n\n");

        if (num == 3) break;
        else if (num == 1) {
            // 성적을 입력 받는다.
            InputData(&temp, ++count);
            // 각 노드의 등수를 갱신한다.
            UpdateRanking(p_head, &temp);
            // 새로 입력한 성적을 연결 리스트에 추가한다.
            AddNode(&p_head, &p_tail, &temp);
        }
        else if (num == 2) {
            // 각 노드에 저장된 성적 정보를 출력한다.
            DisplayData(p_head);
        }
        printf("\n\n");
    }

    DeleteAllNode(&p_head, &p_tail);
    return 0;
}