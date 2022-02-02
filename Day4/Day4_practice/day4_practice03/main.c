// ���ص� 3 �迭�� ���
#include <stdio.h>
#include <locale.h>

#define MAX_COUNT		5
#define NAME_LENGTH		13

void main() {
	setlocale(LC_ALL, "ko_KR");
	wchar_t name[MAX_COUNT][NAME_LENGTH];
	int kor[MAX_COUNT], eng[MAX_COUNT], math[MAX_COUNT];
	int sum[MAX_COUNT];
	float avg[MAX_COUNT];

	printf("�л� ������ �Է��ϼ���\n");
	for (size_t i = 0; i < MAX_COUNT; i++)
	{
		printf("%d��° �л� �̸� : ", i + 1);
		wscanf_s(L"%s", name[i], NAME_LENGTH);
		wprintf(L"%s ����� : ", name[i]);
		scanf_s("%d", &kor[i]);  // ����ǥ��
		wprintf(L"%s ����� : ", name[i]);
		scanf_s("%d", &eng[i]);
		wprintf(L"%s ���м��� : ", name[i]);
		scanf_s("%d", &math[i]);
	}

	// �ݺ������� ������ ��� ���
	for (size_t i = 0; i < MAX_COUNT; i++)
	{
		sum[i] = kor[i] + eng[i] + math[i];
		avg[i] = sum[i] / 3.0f;
	}

	printf("\n����	�̸�	����	����	����	����	���\n");
	for (size_t i = 0; i < MAX_COUNT; i++)
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			i + 1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
	}
}
