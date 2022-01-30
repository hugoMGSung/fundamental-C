/* getchar 함수를 사용, 키보드에 문자 한개 입력 받기 */
#include <stdio.h>

void main()
{
    int input_data;
    /* 표준 입력 함수를 사용하여 문자를 한 개 입력받음 */
    input_data = getchar();
    /* 입력받은 문자를 출력 */
    printf("input : %c\n", input_data);
}