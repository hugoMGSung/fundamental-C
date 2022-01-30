/* 연습문제5 */
#include <stdio.h>
#include <malloc.h>

// 스택에 정수 값을 하나 추가할 때 사용하는 함수
// a_num : 추가할 정수 값, ap_stack : 스택 메모리 영역의 시작 주소
// ap_data_count : 스택에 저장된 데이터 개수가 저장된 메모리의 주소
// a_stack_size : 스택의 크기가 저장된 변수
void Push(short a_num, short* ap_stack,
    unsigned short* ap_data_count, unsigned short a_stack_size)
{
    // 스택에 빈 공간이 있는 경우에만 입력을 받는다.
    if (*ap_data_count < a_stack_size) {
        *(ap_stack + *ap_data_count) = a_num;  // 스택에 새로운 값을 저장한다.
        (*ap_data_count)++;  // 저장된 갯수를 증가시킨다.  
    }
    else printf("Stack이 가득차서 값을 더 이상 넣을 수 없습니다\n");
}

// 스택에서 마지막에 입력된 정수 값을 하나 가져오는 함수
// ap_num : 스택에서 가져온 정수값이 저장될 주소
// ap_stack : 스택 메모리 영역의 시작 주소
// ap_data_count : 스택에 저장된 데이터 개수가 저장된 메모리의 주소
// a_stack_size : 스택의 크기가 저장된 변수
// 스택에서 정수 값을 성공적으로 가져오면 1을 반환하고 실패하면 0을 반환한다.
short Pop(short* ap_num, short* ap_stack,
    unsigned short* ap_data_count, unsigned short a_stack_size)
{
    if (*ap_data_count == 0) {  // 스택에 저장된 값이 없는 경우
        printf("Stack에 저장된 값이 없습니다.\n");
        return 0;
    }

    (*ap_data_count)--;  // 스택에 저장된 정수의 갯수를 줄임
    // 마지막에 저장되어 있던 정수값을 저장함
    *ap_num = *(ap_stack + *ap_data_count);
    return 1;
}

// 스택에 있는 값들을 출력하는 함수
// ap_stack : 스택 메모리 영역의 시작 주소
// a_data_count : 현재 스택에 저장된 데이터 개수
void ShowStack(short* ap_stack, unsigned short a_data_count)
{
    int i;

    if (a_data_count == 0) printf("Stack에 저장된 값이 없습니다.\n");
    else {
        printf("Stack에 저장된 값 목록\n");
        for (i = 0; i < a_data_count; i++) {
            printf("[%03d] : %d\n", i + 1, ap_stack[i]);
        }
        printf("총 %d개의 값이 저장 되어 있습니다.\n", a_data_count);
    }
}

void main(void)
{
    // 스택에 저장된 데이터의 개수와 스택의 크기를 저장할 변수
    unsigned short count = 0, stack_size = 0;
    // 메뉴 항목을 선택할때 사용할 변수와 값을 입력받을 때 사용할 변수
    short select_index = 0, temp = 0;
    short* p_stack;     // 스택으로 사용할 메모리 공간을 가리킬 포인터

    printf("Stack의 크기를 입력하세요 : ");
    scanf_s("%hu", &stack_size);
    p_stack = (short*)malloc(sizeof(short) * stack_size);

    while (select_index != 9) {
        // 사용자에게 선택할 수 있는 기능을 보여준다.
        printf("\n\n1. Stack에 값 넣기\n");
        printf("2. Stack에서 값 꺼내기\n");
        printf("3. Stack에 저장된 값 확인\n");
        printf("9. 프로그램 종료\n\n");
        printf("선택 : ");
        scanf_s("%hd", &select_index); // 사용자가 선택한 메뉴값을 얻는다.

        switch (select_index) {
        case 1: // 사용자가 입력한 값을 스택에 저장한다.
            printf("저장할 값을 입력하세요 : ");
            scanf_s("%hd", &temp);
            Push(temp, p_stack, &count, stack_size);
            break;
        case 2: // 스택에 저장된 정수값을 가져온다.
            if (Pop(&temp, p_stack, &count, stack_size)) {
                printf("가져온 값 -> %d", temp);
            }
            break;
        case 3: // 스택에 저장된 값들을 보여준다.
            ShowStack(p_stack, count);
            break;
        }
    }

    free(p_stack);
}