#include <stdio.h>

void main()
{
    /* %c와 65가 짝을 이루기 때문에 65에 해당하는 ASCII 코드값
    A 가 출력 됩니다. */
    printf("65의 ASCII 값은 %c 입니다.\n", 65);

    char data = 65;
    /*첫 번째 data는 %c와 짝이 되고 두 번째는 %d와 짝을 이룬다.*/
    printf("%c 의 ASCII 값은 %d 입니다.\n", data, data);
}