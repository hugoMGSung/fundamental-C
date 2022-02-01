/**/
#include <stdio.h>

void main() {
    printf("%d\n", 14 + 3);
    printf("%d\n", 14 - 3);
    printf("%d\n", 14 * 3);
    printf("%d\n", 14 / 3);
    printf("%d\n", 14 % 3);

    printf("%f\n", 14 / 3.); // 마침표 필요

    // 오버플로
    int a = 0x7fffffff; //0111 1111 1111 1111 1111 1111 1111 1111
    int b = 0x80000000; //1000 0000 0000 0000 0000 0000 0000 0000
    printf("%d, %d\n", a, a + 1);
    printf("%d, %d\n", b, b - 1);
}