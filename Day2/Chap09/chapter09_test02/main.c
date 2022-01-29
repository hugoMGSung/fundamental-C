#include <stdio.h>

void main() {
	int step = 2, i;

	while (step <= 9) {
		i = 1;
		while (i <= 9) {
			printf("%d * %d = %d\n", step, i, step * i);
			i++;
		}
		step++;
	}
}