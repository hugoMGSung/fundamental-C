/* ������ ��ġ�� �޸� �ּ� ��� */
#include <stdio.h>

void main() {
	short birthday;
	short* ptr;     // short *ptr; -->
	ptr = &birthday;   // birthday ������ �ּҸ� ptr������ ����

	// %p ������ �޸� �ּҸ� 16���� �������� ���
	printf("birthday ������ �ּҴ� &%p  �Դϴ�.\n", ptr);
}