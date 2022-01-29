#include <stdio.h>

void main()
{
	int data = 5, result = 0;

	result = data % 2;
	printf("result = %d\n", result);

	result = data < 5;
	printf("result = %d\n", result);

	result = data < 4 + 3;
	printf("result = %d\n", result);

	result = data++ + 2;
	printf("result = %d, data = %d\n", result, data);

	result = 0; data = 5;
	result = data == 5;
	printf("result = %d, data = %d\n", result, data);

	result = 0; data = 5;
	result = data != 5 && (data = 0);
	printf("result = %d, data = %d\n", result, data);

	result = 0; data = 5;
	result = --result && (data = 0);
	printf("result = %d, data = %d\n", result, data);

	result = 0; data = 5;
	result = result-- && (data = 0);
	printf("result = %d, data = %d\n", result, data);

	result = 0; data = 5;
	result = result-- && (data = 0);
	printf("result = %d, data = %d\n", result, data);
}