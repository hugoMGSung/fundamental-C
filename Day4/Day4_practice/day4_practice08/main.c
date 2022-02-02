// ���ص� 8 ���Ḯ��Ʈ
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#define MAX_COUNT		30
#define NAME_LENGTH		33

typedef struct Student {
	size_t num;		// �й�
	wchar_t* p_name;	// �̸� �����ͷ� ����
	int kor, eng, math;
	int sum;
	float avg;

	// ���� �л� ������ ����� �޸� ������
	struct Student* p_next;
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

void showList(SD* ap_user) {
	printf("\n�й�	�̸�	����	����	����	����	���\n");
	while (NULL != ap_user)  // MAX_COUNT
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			ap_user->num, ap_user->p_name, ap_user->kor, ap_user->eng,
			ap_user->math, ap_user->sum, ap_user->avg);

		ap_user = ap_user->p_next;
	}
}

// �л� �̸��� �����ϱ� ���� �Ҵ� �޸𸮸� ��� ����
void deleteData(SD* ap_user) {
	// �л������� ����� ������ ��ġ�� ������ġ�� ���� �ּ� 
	SD* p_delete;
	// �л������� ����� �ּҿ��� �л� �̸��� �ش��ϴ� �޸𸮸� ����
	while (NULL != ap_user) {
		p_delete = ap_user;
		ap_user = ap_user->p_next;
		//free(p_delete->p_name); // �޸� ����
		free(p_delete);
	}
}

void main() {
	setlocale(LC_ALL, "ko_KR");

	SD *p_head = NULL, *p_tail = NULL;
	int select = 0, count = 0;

	while (select != 3) {
		// ���ø޴� ���
		printf("[ �޴� lnk ]\n");
		printf("1. �л� �߰�\n");
		printf("2. ��� ����\n");
		printf("3. ����\n");
		printf("��ȣ ����\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (NULL != p_head) { // ù �л��� �ƴ� ���
				p_tail->p_next = (SD*)malloc(sizeof(SD)); // �л� �ּ� �ϳ� �Ҵ�
				p_tail = p_tail->p_next;
			}
			else { // ó���̸�
				p_head = (SD*)malloc(sizeof(SD));
				p_tail = p_head;
			}
			// p_tail�� ������ ��ġ�� ����Ű�� ���̻� �ڿ� ������ ������ ����
			p_tail->p_next = NULL;

			inputData(p_tail);
			count++;
		}
		else if (select == 2) {
			showList(p_head);
		}

		printf("\n");
	}

	deleteData(p_head);
}