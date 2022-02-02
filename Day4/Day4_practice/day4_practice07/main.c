// ���ص� 7
// �̸��� �ִ���� ���� �� ���� ���� �޸� ����
// malloc

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#define MAX_COUNT		30
#define NAME_LENGTH		33

typedef struct Student {
	size_t num;		// �й�
	wchar_t *p_name;	// �̸� �����ͷ� ����
	int kor, eng, math;
	int sum;
	float avg;
} SD;

void inputData(SD* ap_user) {
	wchar_t temp[NAME_LENGTH];
	printf("�л� ������ �Է��ϼ���\n");

	printf("�й� : ");
	scanf_s("%d", &ap_user->num);

	// �̸��� �ӽø޸𸮿� 
	printf("�л� �̸� : ");
	wscanf_s(L"%s", temp, NAME_LENGTH);
	// �Է¹��� �̸��� ����
	int len = wcslen(temp) + 2; 
	// �̸� ���̸�ŭ ���� �޸��Ҵ�
	ap_user->p_name = (wchar_t*)malloc(len);
	// �Ҵ�� �޸𸮿� ���ڿ� ����
	//memcpy(ap_user->p_name, temp, len);
	wcscpy_s(ap_user->p_name, len + 1, temp);

	wprintf(L"%s ����� : ", ap_user->p_name);
	scanf_s("%d", &ap_user->kor);
	wprintf(L"%s ����� : ", ap_user->p_name);
	scanf_s("%d", &ap_user->eng);
	wprintf(L"%s ���м��� : ", ap_user->p_name);
	scanf_s("%d", &ap_user->math);

	ap_user->sum = ap_user->kor + ap_user->eng + ap_user->math;
	ap_user->avg = ap_user->sum / 3.0f;
}

void showList(SD* ap_user, int count) {
	printf("\n�й�	�̸�	����	����	����	����	���\n");
	for (size_t i = 0; i < count; i++)  // MAX_COUNT
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			ap_user->num, ap_user->p_name, ap_user->kor, ap_user->eng,
			ap_user->math, ap_user->sum, ap_user->avg);

		ap_user++;
	}
}

// �л� �̸��� �����ϱ� ���� �Ҵ� �޸𸮸� ��� ����
void deleteData(SD* ap_user, int count) {
	// �л������� ����� ������ ��ġ�� ������ġ�� ���� �ּ� 
	SD* p_end_user = ap_user + count;
	// �л������� ����� �ּҿ��� �л� �̸��� �ش��ϴ� �޸𸮸� ����
	while (ap_user < p_end_user) {
		//free(ap_user->p_name); // �޸� ����
		ap_user++; // �л����� �̵�
	}
}

void main() {
	setlocale(LC_ALL, "ko_KR");

	SD users[MAX_COUNT];
	int select = 0, count = 0;

	while (select != 3) {
		// ���ø޴� ���
		printf("[ �޴�** ]\n");
		printf("1. �л� �߰�\n");
		printf("2. ��� ����\n");
		printf("3. ����\n");
		printf("��ȣ ����\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (count < MAX_COUNT) {
				inputData(users + count);
				count++;  // �Է¹��� �л� �� ����
			}
		}
		else if (select == 2) {
			showList(users, count);
		}

		printf("\n");
	}
	
	deleteData(users, count);
}