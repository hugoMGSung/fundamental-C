// ���ص� 5
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

void inputData(SD users[], int index) {
	printf("�л� ������ �Է��ϼ���\n");

	printf("%d��° �л� �̸� : ", index + 1);
	// &*users[index].name --> users[index].name
	wscanf_s(L"%s", &users[index].name[0], NAME_LENGTH);  
	wprintf(L"%s ����� : ", users[index].name);
	scanf_s("%d", &users[index].kor);
	wprintf(L"%s ����� : ", users[index].name);
	scanf_s("%d", &users[index].eng);
	wprintf(L"%s ���м��� : ", users[index].name);
	scanf_s("%d", &users[index].math);

	users[index].sum = users[index].kor + users[index].eng + users[index].math;
	users[index].avg = users[index].sum / 3.0f;
}

void showList(SD users[], int count) {
	printf("\n����	�̸�	����	����	����	����	���\n");
	for (size_t i = 0; i < count; i++)  // MAX_COUNT
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			i + 1, users[i].name, users[i].kor, users[i].eng, 
			users[i].math, users[i].sum, users[i].avg);
	}
}

void main() {
	setlocale(LC_ALL, "ko_KR");

	SD users[MAX_COUNT];
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
				inputData(users, count);
				count++;  // �Է¹��� �л� �� ����
			}
		}
		else if (select == 2) {
			showList(users, count);
		}

		printf("\n");
	}
}