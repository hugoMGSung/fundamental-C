// 계산기
#include <stdio.h>  // printf 함수와 scnaf_s 함수를 사용하기 위하여!

float calc(float a_num1, float a_num2, char a_op_type)
{
    float result;

    switch (a_op_type)
    {
    case '+':  // 덧셈 연산을 한다.
        result = a_num1 + a_num2;
        break;
    case '-':   // 뺄셈 연산을 한다.
        result = a_num1 - a_num2;
        break;
    case '*':   // 곱셈 연산을 한다.
        result = a_num1 * a_num2;
        break;
    case '/':   // 나눗셈 연산을 한다.
        if (a_num2 == 0) { // 0으로 나누는 것을 방지한다!
            printf("[오류] : 0으로 나누면 안됩니다!\n");
            return 0;
        }
        result = a_num1 / a_num2;
        break;
    default:
        result = 0;
    }

    return result;
}

void main()
{
    // 연산자를 저장할 변수
    char op_type;
    // 피연산자 두 개의 값을 저장할 변수
    float num1, num2, result;

    printf("연산자 입력 : ");
    // 연산자를 입력 받는다.
    scanf_s("%c", &op_type, 1);
    // 연산자와 함께 입력된 엔터키 제거
    rewind(stdin);

    printf("두 개의 연산할 값 입력 : ");
    // 피연산자를 두 개 입력 받는다.
    scanf_s("%f %f", &num1, &num2);

    result = calc(num1, num2, op_type);
    printf("result : %g\n", result);
}