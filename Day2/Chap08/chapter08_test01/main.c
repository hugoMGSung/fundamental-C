#include <stdio.h>

void main()
{
	int result = 5;

	switch (result) {
	case 6:
		result = 0;
		break;
	case 5:
		result = 1;
	case 4:
		result = result * 10;
		break;
	}

	printf("result = %d\n", result);
}