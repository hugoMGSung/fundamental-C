// 정수값을 입력받아 배열에 대입
#include <stdio.h>
// 최대 100개까지 값을 입력 받아 저장한다.
#define MAX_COUNT   100

int main()
{
    int count = 0, num, i = 0;
    // 사용자가 입력한 값을 저장할 배열
    int data[MAX_COUNT];
    // 최대 100회까지 입력 받는다.
    while (count < MAX_COUNT) {
        // 입력 문구를 출력한다.
        printf("Input Data (Exit -> 9999) : ");
        // 사용자에게 정숫값을 입력 받는다.
        if (scanf_s("%d", &num) == 0) {
            // 사용자가 정숫값이 아닌 다른 형태의 값을 입력한 경우!
            printf("Invalid Number!! Try again!!\n");
            // 표준 입력 버퍼를 되감아서 초기화 효과를 준다!
            rewind(stdin);
        }
        else {
            if (num == 9999) break;  //  9999를 입력하면 종료한다.
            // 정숫값 목록에 입력된 값을 추가하고 데이터 갯수를 증가시킨다.
            data[count++] = num;
        }
    }

    // 현재 목록에 추가된 값들을 출력한다.
    while (i < count) printf("%d, ", data[i++]);
    printf("\n");
    return 0;
}