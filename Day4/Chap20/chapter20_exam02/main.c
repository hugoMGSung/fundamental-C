/* 콜백함수 */
#include <stdio.h>

// PrintValue 함수는 라이브러리에서 제공됨!
void PrintValue(int a_value, void (*ap_modify)(int*));

// ModifyValue 함수는 라이브러리 사용자가 필요에 의해서 만들었음!
void ModifyValue(int* ap_value)
{
    // ap_value 포인터가 가리키는 대상이 음수이면 양수로 변경한다.
    if (*ap_value < 0) *ap_value = *ap_value * (-1);
}

int main()
{
    int value = -5;

    PrintValue(value, NULL);   // -5라고 출력됨!
    // PrintValue 함수에서 함수 포인터에 의해 ModifyValue 함수가 호출되어
    // -5값이 5가로 변경됩니다. 그래서 5라고 출력됨!
    PrintValue(value, ModifyValue);
    return 0;
}