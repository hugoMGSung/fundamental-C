/* *으로 사각형 만들기 */
#include <stdio.h>

void main() {
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)  // j < 5 --> j < i
		{
			printf("*");
		}
		printf("\n");
	}
}