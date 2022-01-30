/* typedef 정의한 자료형으로 변수선언 */
#include <stdio.h>

/* US 라는 새로운 자료형 선언 */
typedef unsigned short int US;

void main()
{
    unsigned short int data = 5;
    US temp;  /* unsigned short int temp; 와 동일 */

    temp = data;
    printf("temp = %d\n", temp);
}