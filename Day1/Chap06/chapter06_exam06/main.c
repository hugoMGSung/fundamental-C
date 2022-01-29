#include <stdio.h>

void main()
{
    int data = 7;
    /* 자릿수 확인을 위해 [ ] 문자를 사용함 */
    printf("[%d] [%5d] \n", data, data);
    /* 자릿수 확인을 위해 [ ] 문자를 사용함 */
    printf("[%5d] [%05d] [%-5d]\n", data, data, data);

    double data1 = 3.141592;
    /* 자릿수 확인을 위해 [ ] 문자를 사용함 */
    printf("[%f] [%.4f] [%8.4f] [%-8.4f]\n", data1, data1, data1, data1);
}