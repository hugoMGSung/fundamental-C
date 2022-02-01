// 포인터로 글자 입력하기
#include <stdio.h>
#include <conio.h>

void MyGetString(char* ap_string)
{
    int key = 0;

    // 사용자에게 키를 입력 받고 Enter 키면 작업을 종료한다.
    while ((key = _getche()) != '\r') {
        if (key != 0 && key != 0x00E0) *ap_string++ = key; // 확장 키가 아닌 경우에만 해당 키를 문자열에 추가한다.
        else key = _getche(); // 확장 키는 두개의 키로 구성되기 때문에 두 번째 키를 제거한다.
    }
    // 포인터 ap_string가 가리키는 위치가 마지막에 입력한 문자 다음 위치이기 때문에
    // 현재 위치에 NULL 문자를 넣어서 문자열을 완성합니다.
    *ap_string = 0;
}

void main()
{
    // 최대 31개의 문자를 입력 받아 저장할 수 있다
    char input[32];
    MyGetString(input);  // 문자열을 입력 받는 함수
    printf("\nInput string : %s\n", input);  // 입력된 문자열을 출력한다.
}