/* ������� (8����, 10����, 16����) */
#include <stdio.h>

void main() {
	// �⺻���
	printf("%d\n", 010);	// 8���� 
	printf("%d\n", 10);		// 10����
	printf("%d\n", 0x10);	// 16����

	// 8���� ���
	printf("%#o\n", 010);	// 8����
	printf("%#o\n", 10);	// 10����
	printf("%#o\n", 0x10);	// 16����

	// 16���� ���
	printf("%#x\n", 010);	// 
	printf("%#x\n", 10);	// 
	printf("%#x\n", 0x10);	// 

	// 16���� 0x12345678 -> 0001 0010 0011 0100 0101 0110 0111 1000
	printf("%d\n", 0x12345678);
	unsigned int num = 305419896;
	printf("%#x\n", num);

	for (int i = 31; i >= 0; --i)
	{
		int result = num >> i & 1;
		printf("%d", result);
		if (i % 4 == 0) printf(" ");
	}
	printf("\n");
}