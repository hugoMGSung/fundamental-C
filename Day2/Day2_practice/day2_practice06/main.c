// 다이아몬드 만들기
#include <stdio.h>

void main() {
	int num = 5;

	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 1; j < num - i; j++)
		{
			printf(" ");
		}

		for (size_t j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (size_t i = 1; i < num; i++) // i의 초기값 0에서 1
	{
		for (size_t j = 1; j < i + 1; j++)
		{
			printf(" ");
		}

		for (size_t j = 2 * num - 1; j > 2 * i; j--)
		{
			printf("*");
		}

		printf("\n");
	}
}