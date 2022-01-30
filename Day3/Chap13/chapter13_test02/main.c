#include <stdio.h>

void main() {
	int data = 0x12345678;

	short* p = (short*)&data;
	*p = 0x0412;

	printf("data = %X\n", data);
}