// 이해도 5
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
	printf("학생 정보를 입력하세요\n");

	printf("%d번째 학생 이름 : ", index + 1);
	// &*users[index].name --> users[index].name
	wscanf_s(L"%s", &users[index].name[0], NAME_LENGTH);  
	wprintf(L"%s 국어성적 : ", users[index].name);
	scanf_s("%d", &users[index].kor);
	wprintf(L"%s 영어성적 : ", users[index].name);
	scanf_s("%d", &users[index].eng);
	wprintf(L"%s 수학성적 : ", users[index].name);
	scanf_s("%d", &users[index].math);

	users[index].sum = users[index].kor + users[index].eng + users[index].math;
	users[index].avg = users[index].sum / 3.0f;
}

void showList(SD users[], int count) {
	printf("\n순번	이름	국어	영어	수학	총점	평균\n");
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
		// 선택메뉴 출력
		printf("[ 메뉴 ]\n");
		printf("1. 성적 입력\n");
		printf("2. 목록 보기\n");
		printf("3. 종료\n");
		printf("번호 선택\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (count < MAX_COUNT) {
				inputData(users, count);
				count++;  // 입력받은 학생 수 증가
			}
		}
		else if (select == 2) {
			showList(users, count);
		}

		printf("\n");
	}
}