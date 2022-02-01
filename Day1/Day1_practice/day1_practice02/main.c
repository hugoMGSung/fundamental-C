/* 정수형식 예제 */
#include <stdio.h>

void main() {
	char a = 'a';
	printf("%d\n", sizeof(a));
	printf("%d %d\n", sizeof('a'), sizeof(100)); // !! 'a'만 출력해볼 것

	printf("char:%d\n", sizeof(char));
	printf("short:%d\n", sizeof(short));
	printf("int:%d\n", sizeof(int));
	printf("long:%d\n", sizeof(long));
	printf("long long:%d\n", sizeof(long long));

	// 명시적 출력
	char c1 = 0x80, c2 = 0x7F;
	printf("char:%d, %d ~ %d\n", sizeof(char), c1, c2);
	short s1 = 0x8000, s2 = 0x7fff;
	printf("short:%d, %d ~ %d\n", sizeof(short), s1, s2);
	int i1 = 0x80000000, i2 = 0x7fffffff;
	printf("int:%d, %d ~ %d\n", sizeof(int), i1, i2);
	long l1 = 0x80000000, l2 = 0x7fffffff;
	printf("long:%d, %ld ~ %ld\n", sizeof(long), l1, l2);
	long long ll1 = 0x8000000000000000, ll2 = 0x7FFFFFFFFFFFFFFF;
	printf("long long:%d, %lld ~ %lld\n", sizeof(long long), ll1, ll2);

	// unsigned
	unsigned short us1 = 0x0000, us2 = 0xffff;
	printf("unsigned short:%d, %u ~ %u\n", sizeof(unsigned short), us1, us2);
	unsigned int ui1 = 0x00000000, ui2 = 0xffffffff;
	printf("unsigned int:%d, %u ~ %u\n", sizeof(unsigned int), ui1, ui2);
	unsigned long ul1 = 0x00000000, ul2 = 0xffffffff;
	printf("unsigned long:%d, %lu ~ %lu\n", sizeof(unsigned long), ul1, ul2);
	unsigned long long ull1 = 0x0000000000000000, ull2 = 0xFFFFFFFFFFFFFFFF;
	printf("unsigned long long:%d, %llu ~ %llu\n", sizeof(unsigned long long), ull1, ull2);
}