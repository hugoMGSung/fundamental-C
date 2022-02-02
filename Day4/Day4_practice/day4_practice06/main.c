// ���ص� 6
// ������ ���� ��� 
#include <stdio.h>
#include <locale.h>

#define MAX_COUNT		30
#define NAME_LENGTH		13

typedef struct Student {
	wchar_t name[NAME_LENGTH];
	int kor, eng, math;
	int sum;
	float avg;
} SD;

void inputData(SD* ap_user, int index) {
	printf("�л� ������ �Է��ϼ���\n");

	printf("%d��° �л� �̸� : ", index + 1);
	// &*users[index].name --> users[index].name
	wscanf_s(L"%s", &*ap_user->name, NAME_LENGTH);
	wprintf(L"%s ����� : ", ap_user->name);
	scanf_s("%d", &ap_user->kor);
	wprintf(L"%s ����� : ", ap_user->name);
	scanf_s("%d", &ap_user->eng);
	wprintf(L"%s ���м��� : ", ap_user->name);
	scanf_s("%d", &ap_user->math);

	ap_user->sum = ap_user->kor + ap_user->eng + ap_user->math;
	ap_user->avg = ap_user->sum / 3.0f;
}

void showList(SD* ap_user, int count) {
	printf("\n����	�̸�	����	����	����	����	���\n");
	for (size_t i = 0; i < count; i++)  // MAX_COUNT
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			i + 1, ap_user->name, ap_user->kor, ap_user->eng,
			ap_user->math, ap_user->sum, ap_user->avg);

		ap_user++;
	}
}

void main() {
	setlocale(LC_ALL, "ko_KR");

	SD users[MAX_COUNT];
	int select = 0, count = 0;

	while (select != 3) {
		// ���ø޴� ���
		printf("[ �޴�* ]\n");
		printf("1. ���� �Է�\n");
		printf("2. ��� ����\n");
		printf("3. ����\n");
		printf("��ȣ ����\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (count < MAX_COUNT) {
				inputData(users + count, count);
				count++;  // �Է¹��� �л� �� ����
			}
		}
		else if (select == 2) {
			showList(users, count);
		}

		printf("\n");
	}
}