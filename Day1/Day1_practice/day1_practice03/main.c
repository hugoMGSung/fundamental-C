/* 실수 형식 표현
 * %f, %g, %e 
 */
#include <stdio.h>

void main() {
	printf("sizeof(float):%d bytes, sizeof(double):%d bytes\n", sizeof(float), sizeof(double));
	printf("sizeof(0.1f):%d bytes, sizeof(0.1):%d bytes\n", sizeof(0.1f), sizeof(0.1));

	// 실수 출력
	printf("%.2f\n", 12.3456);	// 12.35
	printf("%e\n", 12.3456);	// 1.234560e+01
	printf("%g\n", 12.3456);	//1213456
	printf("%g\n", 0.000000123456);		//1.23456e-07

	// 실수계산 오차
    float f = 0.0f;
    f += 0.1f;
    printf("%.20f\n", f);
    f += 0.1f;
    printf("%.20f\n", f);
    f += 0.1f;
    printf("%.20f\n", f);

    double df = 0.0;
    df += 0.1;
    printf("%.20f\n", df);
    df += 0.1;
    printf("%.20f\n", df);
    df += 0.1;
    printf("%.20f\n", df);
}