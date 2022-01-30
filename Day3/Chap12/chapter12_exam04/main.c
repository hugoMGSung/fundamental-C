/* 배열초기화 문법으로 배열요소 초기화 */
#include <stdio.h>

void main()
{
    short student[20] = { 0, };


    student[1] = 10;
    printf("%d %d\n", student[1], student[2]);
}