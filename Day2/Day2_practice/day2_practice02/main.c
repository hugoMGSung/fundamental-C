/* *으로 삼각형 만들기 */
#include <stdio.h>

void main() {
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}