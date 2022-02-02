// 문법 이해도 1
#include <stdio.h>

void main() {
	// 성적 저장 변수 선언
	int kor = 90, eng = 80, math = 83;
	// 성적 합산
	int sum = kor + eng + math;
	// 실수형식으로 연산하기 위해서 3.0f로 또는 double로 가능
	float avg = sum / 3.0f;

	// 성적 출력
	printf("국어 : %d, 영어 : %d, 수학 : %d,", kor, eng, math);
	// 총점과 평균
	printf(" 총점 : %d, 평균 : %.2f\n", sum, avg);
}