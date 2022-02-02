/* 2차원 포인터 사용, 일반변수 값 대입 */
#include <stdio.h>

void main()
{
    short data = 3;
    short* p = &data; // data변수의 주소를 1차원 포인터 p에 저장
    short** pp = &p;    // 1차원 포인터p 주소를 2차원 포인터 pp에 저장

    printf("[Before  ] data : %d\n", data);
    *p = 4;
    printf("[Use *p  ] data : %d\n", data);
    **pp = 108;
    printf("[Use **pp] data : %d\n", data);

}