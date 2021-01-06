#include "stdio.h"
#include "fir.h"

const int SIZE = 256;

int main(int argc, char *argv[])
{
	int taps[] = {1, 2, 0, -3, 0, 4, -5, 0, 1, -2, 0, -3, 0, 4, -5, 0};
	int out = 0;
	for (int i = 0; i < SIZE; i++) {
		fir(i, &out, taps);
	}
	printf("===============================\n");
	printf("result = %d\n", out);
	if (out == -483) {
		printf("Test passed!\n");
		printf("===============================\n");
		return 0;
	} else {
		printf("Test failed!\n");
		printf("===============================\n");
		return 1;
	}
}
