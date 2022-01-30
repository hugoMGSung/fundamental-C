/* 2차원배열, ... */
#include <stdio.h>

void main() {
	char data[3][5];
	char(*p)[5];
	p = data;

	(*p)[1] = 3;
	printf("(*p)[1] = %d\n", (*p)[1]);
	(*(p + 1))[2] = 4;
	printf("(*(p + 1))[2] = %d\n", (*(p + 1))[2]);
	(*(p + 2))[4] = 5;
	printf("(*(p + 2))[4] = %d\n", (*(p + 2))[4]);

	printf("Total array size -> %d\n", sizeof(data));
	printf("2nd array size -> %d\n", sizeof(data[0]));

	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		for (int j = 0; j < sizeof(data[0]); j++)
		{
			printf("%d, ", data[i][j]);
		}
		printf("\n");
	}
}