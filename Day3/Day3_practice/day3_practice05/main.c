// 수를 입력받아 정렬하면서 
#include <stdio.h>
// 최대 100개까지 값을 입력 받아 저장한다.
#define MAX_COUNT   100

void DisplayList(int a_data[], int a_count)
{
    int i;
    // 현재 목록에 추가된 값들을 출력한다.
    for (i = 0; i < a_count; i++) printf("%d, ", a_data[i]);
    printf("\n");
}

void InsertData(int a_data[], int a_count, int a_num)
{
    int insert, i;

    // 현재 입력된 값이 이전 입력 받은 값 목록에서 
    // 어떤 위치에 들어가야하는지 찾는다.
    for (insert = 0; insert < a_count; insert++) {
        if (a_num < a_data[insert]) break;
    }

    // insert 위치에 num 값을 입력하기 위해서 insert 뒤에 
    // 있는 값들을 하나씩 뒤로 이동시킨다. 
    for (i = a_count; i > insert; i--) a_data[i] = a_data[i - 1];

    // insert 위치에 num 값을 입력한다.
    a_data[insert] = a_num;
}

int main()
{
    int count = 0, num;
    // 사용자가 입력한 값을 저장할 배열
    int data[MAX_COUNT];

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

            InsertData(data, count, num);
            // 정숫값 목록에 추가된 데이터 갯수를 증가시킨다.
            count++;
            DisplayList(data, count);
        }
    }

    DisplayList(data, count);
    return 0;
}