// 2진수 문자열을 숫자로 변경
#include <stdio.h>    // printf 함수를 사용하기 위해

int main()
{
    char str[5] = "1011"; // 2진수 형태의 문자열
    int num = 0, i;

    // 2진수 형식의 문자열을 정수로 변경한다.
    for (i = 0; i < sizeof(str)-1; i++) {
        num = (num << 1) + str[i] - '0';
    }

    // 정수로 바뀐 값을 10진수와 16진수 형태로 출력한다.
    printf("Decimal = %d, Hexa = 0x%02X\n", num, num);
    return 0;
}