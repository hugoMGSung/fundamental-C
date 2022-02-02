// 이해도 3 배열을 사용
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

	printf("학생 정보를 입력하세요\n");
	for (size_t i = 0; i < MAX_COUNT; i++)
	{
		printf("%d번째 학생 이름 : ", i + 1);
		wscanf_s(L"%s", name[i], NAME_LENGTH);
		wprintf(L"%s 국어성적 : ", name[i]);
		scanf_s("%d", &kor[i]);  // 변경표현
		wprintf(L"%s 영어성적 : ", name[i]);
		scanf_s("%d", &eng[i]);
		wprintf(L"%s 수학성적 : ", name[i]);
		scanf_s("%d", &math[i]);
	}

	// 반복문으로 총점과 평균 계산
	for (size_t i = 0; i < MAX_COUNT; i++)
	{
		sum[i] = kor[i] + eng[i] + math[i];
		avg[i] = sum[i] / 3.0f;
	}

	printf("\n순번	이름	국어	영어	수학	총점	평균\n");
	for (size_t i = 0; i < MAX_COUNT; i++)
	{
		wprintf(L"%3d\t%s\t%d\t%d\t%d\t%d\t%f\n",
			i + 1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
	}
}
