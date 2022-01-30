/* gets 함수로 문자열을 입력받을 때 입력취소까지 처리 */
#include <stdio.h>

void main()
{
    char input_string[10];
    /*반환값이 NULL이 아니라 문자열을 입력 받아서 input_string에 저장함*/
    if (NULL != gets(input_string)) {
        printf("input -> %s\n", input_string);
    }
    else {
        printf("input -> Canceled\n");
    }
}