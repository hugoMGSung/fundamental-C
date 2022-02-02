// 문법 이해도2
#include <stdio.h>

void main() {
	// 성적변수
	int kor, eng, math;
	int sum; // 총점
	float avg; // 평균

	printf("성적을 입력하세요.\n");
	printf("국어 : ");
	scanf_s("%d", &kor);
	printf("영어 : ");
	scanf_s("%d", &eng);
	printf("수학 : ");
	scanf_s("%d", &math);

	// 입력 성적 합산
	sum = kor + eng + math;
	// 평균
	avg = sum / 3.0f;

	// 성적 출력
	printf("국어 : %d, 영어 : %d, 수학 : %d,", kor, eng, math);
	// 총점과 평균
	printf(" 총점 : %d, 평균 : %.2f\n", sum, avg);
}