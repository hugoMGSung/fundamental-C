// 이해도 8 연결리스트
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#define MAX_COUNT		30
#define NAME_LENGTH		33

typedef struct Student {
	size_t num;		// 학번
	wchar_t* p_name;	// 이름 포인터로 변경
	int kor, eng, math;
	int sum;
	float avg;

	// 다음 학생 정보가 저장된 메모리 포인터
	struct Student* p_next;
} SD;

void inputData(SD* ap_user) {
	wchar_t temp[NAME_LENGTH];
	printf("학생 정보를 입력하세요\n");

	printf("학번 : ");
	scanf_s("%d", &ap_user->num);

	// 이름을 임시메모리에 
	printf("학생 이름 : ");
	wscanf_s(L"%s", temp, NAME_LENGTH);
	// 입력받은 이름의 길이
	int len = wcslen(temp) + 2;
	// 이름 길이만큼 힙에 메모리할당
	ap_user->p_name = (wchar_t*)malloc(len);
	// 할당된 메모리에 문자열 복사
	//memcpy(ap_user->p_name, temp, len);
	wcscpy_s(ap_user->p_name, len + 1, temp);

	wprintf(L"%s 국어성적 : ", ap_user->p_name);
	scanf_s("%d", &ap_user->kor);
	wprintf(L"%s 영어성적 : ", ap_user->p_name);
	scanf_s("%d", &ap_user->eng);
	wprintf(L"%s 수학성적 : ", ap_user->p_name);
	scanf_s("%d", &ap_user->math);

	ap_user->sum = ap_user->kor + ap_user->eng + ap_user->math;
	ap_user->avg = ap_user->sum / 3.0f;
}

void showList(SD* ap_user) {
	printf("\n학번	이름	국어	영어	수학	총점	평균\n");
	while (NULL != ap_user)  // MAX_COUNT
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			ap_user->num, ap_user->p_name, ap_user->kor, ap_user->eng,
			ap_user->math, ap_user->sum, ap_user->avg);

		ap_user = ap_user->p_next;
	}
}

// 학생 이름을 저장하기 위해 할당 메모리를 모두 해제
void deleteData(SD* ap_user) {
	// 학생정보가 저장된 마지막 위치의 다음위치에 대한 주소 
	SD* p_delete;
	// 학생정보가 저장된 주소에서 학생 이름에 해당하는 메모리를 해제
	while (NULL != ap_user) {
		p_delete = ap_user;
		ap_user = ap_user->p_next;
		//free(p_delete->p_name); // 메모리 해제
		free(p_delete);
	}
}

void main() {
	setlocale(LC_ALL, "ko_KR");

	SD *p_head = NULL, *p_tail = NULL;
	int select = 0, count = 0;

	while (select != 3) {
		// 선택메뉴 출력
		printf("[ 메뉴 lnk ]\n");
		printf("1. 학생 추가\n");
		printf("2. 목록 보기\n");
		printf("3. 종료\n");
		printf("번호 선택\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (NULL != p_head) { // 첫 학생이 아닌 경우
				p_tail->p_next = (SD*)malloc(sizeof(SD)); // 학생 주소 하나 할당
				p_tail = p_tail->p_next;
			}
			else { // 처음이면
				p_head = (SD*)malloc(sizeof(SD));
				p_tail = p_head;
			}
			// p_tail이 마지막 위치를 가리키면 더이상 뒤에 정보가 없음을 설정
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