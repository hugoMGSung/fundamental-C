// 이해도4
#include <stdio.h>
#include <locale.h>

#define MAX_COUNT		30
#define NAME_LENGTH		13

// 학생이름과 성적 입력, 총점과 평균 계산 함수
void inputData(wchar_t name[][NAME_LENGTH], int kor[], int eng[], 
				int math[], int sum[], float avg[], int index) {
	printf("학생 정보를 입력하세요\n");

	printf("%d번째 학생 이름 : ", index + 1);
	// &name[index][0]
	wscanf_s(L"%s", &*name[index], NAME_LENGTH); 
	wprintf(L"%s 국어성적 : ", name[index]);
	scanf_s("%d", &kor[index]);  // 변경표현
	wprintf(L"%s 영어성적 : ", name[index]);
	scanf_s("%d", &eng[index]);
	wprintf(L"%s 수학성적 : ", name[index]);
	scanf_s("%d", &math[index]);

	sum[index] = kor[index] + eng[index] + math[index];
	avg[index] = sum[index] / 3.0f;
}

void showList(wchar_t name[][NAME_LENGTH], int kor[], int eng[],
	int math[], int sum[], float avg[], int count) {
	printf("\n순번	이름	국어	영어	수학	총점	평균\n");
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
		// 선택메뉴 출력
		printf("[ 메뉴 ]\n");
		printf("1. 성적 입력\n");
		printf("2. 목록 보기\n");
		printf("3. 종료\n");
		printf("번호 선택\n");

		scanf_s("%d", &select);
		if (select == 1) {
			if (count < MAX_COUNT) {
				inputData(name, kor, eng, math, sum, avg, count);
				count++;  // 입력받은 학생 수 증가
			}
		}
		else if (select == 2) {
			showList(name, kor, eng, math, sum, avg, count);
		}

		printf("\n");
	}
}