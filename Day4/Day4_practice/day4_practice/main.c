// ���� ���ص� 1
#include <stdio.h>

void main() {
	// ���� ���� ���� ����
	int kor = 90, eng = 80, math = 83;
	// ���� �ջ�
	int sum = kor + eng + math;
	// �Ǽ��������� �����ϱ� ���ؼ� 3.0f�� �Ǵ� double�� ����
	float avg = sum / 3.0f;

	// ���� ���
	printf("���� : %d, ���� : %d, ���� : %d,", kor, eng, math);
	// ������ ���
	printf(" ���� : %d, ��� : %.2f\n", sum, avg);
}