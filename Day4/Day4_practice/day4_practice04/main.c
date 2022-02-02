// ���ص�4
#include <stdio.h>
#include <locale.h>

#define MAX_COUNT		30
#define NAME_LENGTH		13

// �л��̸��� ���� �Է�, ������ ��� ��� �Լ�
void inputData(wchar_t name[][NAME_LENGTH], int kor[], int eng[], 
				int math[], int sum[], float avg[], int index) {
	printf("�л� ������ �Է��ϼ���\n");

	printf("%d��° �л� �̸� : ", index + 1);
	// &name[index][0]
	wscanf_s(L"%s", &*name[index], NAME_LENGTH); 
	wprintf(L"%s ����� : ", name[index]);
	scanf_s("%d", &kor[index]);  // ����ǥ��
	wprintf(L"%s ����� : ", name[index]);
	scanf_s("%d", &eng[index]);
	wprintf(L"%s ���м��� : ", name[index]);
	scanf_s("%d", &math[index]);

	sum[index] = kor[index] + eng[index] + math[index];
	avg[index] = sum[index] / 3.0f;
}

void showList(wchar_t name[][NAME_LENGTH], int kor[], int eng[],
	int math[], int sum[], float avg[], int count) {
	printf("\n����	�̸�	����	����	����	����	���\n");
	for (size_t i = 0; i < count; i++)
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			i + 1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
	}
}

void main() {
	setlocale(LC_ALL, "ko_KR");

	wchar_t name[MAX_COUNT][NAME_LENGTH];
	int kor[MAX_COUNT], eng[MAX_COUNT], math[MAX_COUNT];
	int sum[MAX_COUNT];
	float avg[MAX_COUNT];
	int select = 0, count = 0;

	while (select != 3) {
		// ���ø޴� ���
		printf("[ �޴� ]\n");
		printf("1. ���� �Է�\n");
		printf("2. ��� ����\n");
		printf("3. ����\n");
		printf("��ȣ ����\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (count < MAX_COUNT) {
				inputData(name, kor, eng, math, sum, avg, count);
				count++;  // �Է¹��� �л� �� ����
			}
		}
		else if (select == 2) {
			showList(name, kor, eng, math, sum, avg, count);
		}

		printf("\n");
	}
}