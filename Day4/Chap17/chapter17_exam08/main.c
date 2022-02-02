// 명령행 인자
#include <stdio.h>
#include <string.h>

void main(int argc, char** argv) {
	int i = 0, j = 0, len = 0;

	printf("Number of arguments(argc) = %d\n", argc);

	for (i = 0; i < argc; i++)
	{
		len = strlen(*(argv + i)); // argv[i]
		printf("argv[%d]=%s Length = %d\n", i, *(argv + i), len);

	}
}