#include <stdio.h>

void main() {
	char a = 0x12, b = 0x34;
	short c = 0x5678;

	int t;

	char* p = (char*)&t;
	*(p + 3) = a;
	*(p + 2) = b;

	short* p2 = (short*)&t;
	*(p2) = c;
	printf("%X\n", t);
}