/* for반복문 사용, 구구단2단 출력하기 */
#include <stdio.h>

void main()
{
    int i;
    /* i 변수가 1 ~ 9까지 1씩 증가하면서 총 9번 반복합니다 */
    for (i = 1; i <= 9; i++) {
        /* 2 * i = 2*i 형식으로 출력합니다 */
        printf("2 * %d = %d\n", i, 2 * i);
    }
}