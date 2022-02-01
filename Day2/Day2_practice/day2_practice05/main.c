// 역피라미드 만들기-2
#include <stdio.h>

void main() {
	int num = 5;

	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 1; j < i+1; j++)
		{
			printf(" ");
		}

		for (size_t j = 2*num-1; j > 2*i; j--)
		{
			printf("*");
		}

		printf("\n");
	}
}