/* 연습문제06 */
// char data[a][b][c];  a -> 2,  b -> 3,  c -> 4

#define LIMIT_A     2
#define LIMIT_B     3
#define LIMIT_C     4

#include <stdio.h>
#include <malloc.h>   // malloc, free 사용!

void main()
{
    int a, b, c;
    char*** p;

    // *(p+0)와 *(p+1)에 해당하는 메모리 생성
    p = (char***)malloc(sizeof(char**) * LIMIT_A);

    // *((*p+0)+0)에서 *(*(p+1)+2)까지에 해당하는 메모리 생성
    for (a = 0; a < LIMIT_A; a++) {
        *(p + a) = (char**)malloc(sizeof(char*) * LIMIT_B);
        // *(*((*p+0)+0)+0)에서 *(*(*(p+1)+2)+3)까지에 해당하는 메모리 생성
        for (b = 0; b < LIMIT_B; b++) {
            *(*(p + a) + b) = (char*)malloc(sizeof(char) * LIMIT_C);
        }
    }

    // 제대로 생성되었는지 체크하는 코드
    for (a = 0; a < LIMIT_A; a++) {
        for (b = 0; b < LIMIT_B; b++) {
            for (c = 0; c < LIMIT_C; c++) {
                // 각 메모리가 할당된 순서로 0, 1, 2, 3... 값을 대입한다.
                // a는 1 증가할 때마다 b, c 반복문에 의해서 LIMIT_B * LIMIT_C씩
                // 값이 증가하고 b는 1증가할때마다 LIMIT_C씩 값이 증가하기 때문에 
                // 대입되는 값은 (a * LIMIT_B * LIMIT_C) + (b * LIMIT_C) + c와 
                // 같이 구성하면 됩니다.
                *(*(*(p + a) + b) + c) =
                    a * LIMIT_B * LIMIT_C + b * LIMIT_C + c;
            }
        }
    }

    // 대입한 코드가 정상적으로 출력되는지 확인한다.
    for (a = 0; a < LIMIT_A; a++) {
        printf("*(p+%d)에 해당하는 메모리 주소 = %p\n", a, p + a);
        printf("========================================\n");
        for (b = 0; b < LIMIT_B; b++) {
            printf("*(*(p+%d)+%d)에 해당하는 메모리 주소 = %p\n",
                a, b, *(p + a) + b);
            printf("------------------------------------------------\n");
            for (c = 0; c < LIMIT_C; c++) {
                printf("*(*(*(p+%d)+%d)+%d)의 주소(%p)와 저장된 값(%d)\n",
                    a, b, c, *(*(p + a) + b) + c, *(*(*(p + a) + b) + c));
            }
            printf("\n");
        }
        printf("\n");
    }

    for (a = 0; a < LIMIT_A; a++) {
        for (b = 0; b < LIMIT_B; b++) {
            // *(*((*p+0)+0)+0)에서 *(*(*(p+1)+2)+3)까지에 해당하는 메모리 해제
            free(*(*(p + a) + b));
        }
        // *((*p+0)+0)에서 *(*(p+1)+2)까지에 해당하는 메모리 해제
        free(*(p + a));
    }
    // *(p+0)와 *(p+1)에 해당하는 메모리 해제
    free(p);
}