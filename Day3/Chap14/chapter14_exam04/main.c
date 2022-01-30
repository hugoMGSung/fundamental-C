/* gets 함수로 문자열 입력받기 */
#include <stdio.h>

void main() {
	/*문자열은 마지막에 NULL 문자 0을 포함해야 하므로 최대 9개의 문자까지 저장 가능 */
	char input_string[10];
	gets(input_string); // 문자열 입력받아 input_string에 저장
	printf("input : %s\n", input_string);
}