//
#include <stdio.h>  // printf 함수를 사용하기 위해
#include <conio.h>  // getche 함수를 사용하기 위해

void main()
{
    // 최대 31개의 문자를 입력 받아 저장할 수 있다
    char input[32];
    int i = 0, key = 0;

    // 사용자에게 키를 입력 받고 Enter 키면 작업을 종료한다.
    while ((key = getche()) != '\r') {
        if (key != 0 && key != 0x00E0) input[i++] = key; // 확장 키가 아닌 경우에만 해당 키를 문자열에 추가한다.
        else key = getche(); // 확장 키는 두개의 키로 구성되기 때문에 두 번째 키를 제거한다.
    }
    // i가 가리키는 위치가 마지막에 입력한 문자 다음 위치이기 때문에
    // input[i]에 NULL 문자를 넣어서 문자열을 완성합니다.
    input[i] = 0;
    printf("\nInput string : %s\n", input);  // 입력된 문자열을 출력한다.
}