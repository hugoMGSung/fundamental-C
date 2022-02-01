// 피라미드 만들기-1
#include <stdio.h>

void main() {
	int num = 5;

	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 1; j < num-i; j++)
		{
			printf(" ");
		}

		for (size_t j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}