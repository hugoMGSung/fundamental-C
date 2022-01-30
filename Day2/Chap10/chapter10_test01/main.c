/* 연습문제1, 2 */
#include <stdio.h>

unsigned char ResetBit(unsigned char dest_data, unsigned char bit_num);

void main() {
	unsigned char data = 5;

	if (data & 0x01) printf("이 값은 홀수입니다.\n");
	else printf("이 값은 짝수입니다.\n");

	printf("3번비트 0변환, 0xFF -> %X\n", ResetBit(0xFF, 3));
}

unsigned char ResetBit(unsigned char dest_data, unsigned char bit_num) {
	dest_data = dest_data & (0x01 << bit_num);
	return dest_data;
}