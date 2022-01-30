/* 다른 변수의 주소를 사용, 포인터로 값 대입 */
#include <stdio.h>

void main()
{
    short birthday;
    short* ptr;
    ptr = &birthday;   /* birthday 변수의 주소를 ptr 변수에 대입 */
    *ptr = 0x0412;     /* birthday = 0x0412; 와 같은 결과 */

    printf("birthday = %d (0x%04X)\n", birthday, birthday);
}