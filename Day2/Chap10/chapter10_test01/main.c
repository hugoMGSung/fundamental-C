/* ��������1, 2 */
#include <stdio.h>

unsigned char ResetBit(unsigned char dest_data, unsigned char bit_num);

void main() {
	unsigned char data = 5;

	if (data & 0x01) printf("�� ���� Ȧ���Դϴ�.\n");
	else printf("�� ���� ¦���Դϴ�.\n");

	printf("3����Ʈ 0��ȯ, 0xFF -> %X\n", ResetBit(0xFF, 3));
}

unsigned char ResetBit(unsigned char dest_data, unsigned char bit_num) {
	dest_data = dest_data & (0x01 << bit_num);
	return dest_data;
}