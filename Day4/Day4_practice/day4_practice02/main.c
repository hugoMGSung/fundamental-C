// ���� ���ص�2
#include <stdio.h>

void main() {
	// ��������
	int kor, eng, math;
	int sum; // ����
	float avg; // ���

	printf("������ �Է��ϼ���.\n");
	printf("���� : ");
	scanf_s("%d", &kor);
	printf("���� : ");
	scanf_s("%d", &eng);
	printf("���� : ");
	scanf_s("%d", &math);

	// �Է� ���� �ջ�
	sum = kor + eng + math;
	// ���
	avg = sum / 3.0f;

	// ���� ���
	printf("���� : %d, ���� : %d, ���� : %d,", kor, eng, math);
	// ������ ���
	printf(" ���� : %d, ��� : %.2f\n", sum, avg);
}