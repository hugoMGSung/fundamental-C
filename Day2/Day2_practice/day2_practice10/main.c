#include <stdio.h>

void test_global(void);   // �ٸ� �ҽ��� �Լ� ȣ���� ���ؼ��� �Լ� ���� �ʿ�

extern int global;		// global ������ �ִٶ�� ���

void main() {
	test_global();
	printf("global = %d\n", global);
}