/* 정수를 오름차순으로 정렬 */
#include <stdio.h>

void main() {
	int data[7] = { 6, 3, 9, 7, 2, 4, 1 };
	int i, j, temp = 0;

	// 정렬전 현재상태 출력
	printf("Before : ");
	for (i = 0; i < 7; i++) printf("%d, ", data[i]);

	// 버블정렬 사용 data 배열 오름차순 정렬
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6 - i; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	printf("\n");

	// 정렬후 출력
	printf("After  : ");
	for (i = 0; i < 7; i++) printf("%d, ", data[i]);

	printf("\n");
}