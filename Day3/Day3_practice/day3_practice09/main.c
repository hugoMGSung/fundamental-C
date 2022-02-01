// 2번째
#include <stdio.h> // printf, gets_s 함수를 사용하기 위해
#define MAX_BIT_COUNT    33

int main()
{
    char str[MAX_BIT_COUNT]; // 2진수 형태의 문자열을 저장할 변수
    char* p = str;           // str 배열의 시작주소를 포인터 p에 저장
    int num = 0, i;

    printf("Input Bit : ");
    gets_s(str, MAX_BIT_COUNT);  // 문자열을 입력 받는다!

    // 2진수 형식의 문자열을 정수로 변경한다.
    for (i = 0; *p; i++) {
        num = (num << 1) + *p - '0';
        p++;  // 다음 문자로 이동한다.
    }

    // 정수로 바뀐 값을 10진수와 16진수 형태로 출력한다.
    printf("Decimal = %d, Hexa = 0x%X\n", num, num);
    return 0;
}