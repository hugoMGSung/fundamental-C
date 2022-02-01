#include <stdio.h>

int global = 0xfe;  // 254

void test_global(void) {
	global++;
}