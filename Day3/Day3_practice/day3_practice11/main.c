// 입력한 문자열 뒤집어서 출력
#include <stdio.h>           // printf 함수, scanf_s 함수를 사용하기 위해!
#define MAX_LENGTH     64    // 최대 64자까지만 입력 받는다.

// a_str 저장된 문자열을 뒤집어 출력한다.
void PrintResersedString(char a_str[])
{
    int i, len = 0;
    // a_str에 저장된 문자열을 뒤집어서 저장할 배열을 선언한다.
    char resersed_str[MAX_LENGTH];

    // 사용자가 입력한 str 배열에 입력된 문자열의 길이를 구한다.
    while (a_str[len] != 0) len++;

    // a_str에 저장된 문자를 resersed_str의 뒤에서부터 대입하여 뒤집는다.
    for (i = 0; i < len; i++) {
        resersed_str[len - i - 1] = a_str[i];
    }
    // resersed_str 문자열의 끝에 NULL 문자를 추가한다.
    resersed_str[i] = 0;
    // 뒤집은 문자열을 출력한다.
    printf("%s\n", resersed_str);
}

void main()
{
    char str[MAX_LENGTH];

    printf("Input String : ");
    // scanf 함수를 사용하려면 scanf("%[^\n]s", str); 라고 적으면 됩니다.
    // %s라고만 적으면 공백을 구분자로 봐서 입력을 공백까지만 받기 때문에 
    // 아래와 같이 '형식 지정자'를 사용해야지 공백도 포함해서 입력 받습니다.
    scanf_s("%[^\n]s", str, MAX_LENGTH - 1);

    printf("-> ");
    // str 변수에 저장된 문자열을 뒤집어 출력한다.
    PrintResersedString(str);
}