// 동적 메모리 할당하여 정수값 합산
#include <stdio.h>    // printf, scanf_s 함수를 사용하기 위해
#include <malloc.h>   // malloc 함수를 사용하기 위해

int main()
{
    int count, i, sum = 0;
    int* p;

    printf("몇 개의 정수를 입력하시겠습니까? ");
    scanf_s("%d", &count);

    if (count > 0) {
        // 입력 받을 개수만큼 int 크기의 메모리를 할당한다.
        p = malloc(sizeof(int) * count);
        if (p != NULL) {  // 성공적으로 메모리가 할당되었다면!
            // 사용자가 입력한 개수만큼 정숫값을 입력받는다.
            for (i = 0; i < count; i++) {
                printf("%d번째 정수 입력 : ", i + 1);
                scanf_s("%d", &*(p + i)); // p + i는 &*(p+1)를 줄여쓴 표현임
            }
            // 사용자가 입력한 값을 확인한다.
            printf("\n입력된 값 확인 : ");
            for (i = 0; i < count; i++) {
                printf("%d, ", *(p + i));
            }

            printf("\n입력된 값을 모두 합산합니다.\n");
            for (i = 0; i < count; i++) {
                printf("%d", *(p + i));
                // i번째 입력한 값을 sum 변수에 합산한다.
                sum = sum + *(p + i);
                // 중간에는 계속 '+' 문자를 출력하다가 마지막에는 '=' 문자를 출력함
                if (i < count - 1) printf(" + ");
                else printf(" = ");
            }
            // 합산된 결과 값을 출력한다.
            printf("%d\n", sum);

            free(p);  // 동적할당된 메모리를 해제한다.
        }
    }
    return 0;
}