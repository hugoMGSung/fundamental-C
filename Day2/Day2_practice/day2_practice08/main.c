// A~E���� ���̾Ƹ��� ����ϱ�
#include <stdio.h>

void main() {
	int num = 9, length = 9, middle = 5;
	int step = 0;

	for (size_t i = 0; i < num; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if ((j == middle - step) || (j == middle + step)) printf("%c", 'A' + step);
			else printf(".");
		}

		if (i >= num / 2) step--; // 4���� ũ��
		else step++;
		printf("\n");
	}
}