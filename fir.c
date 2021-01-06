#include "fir.h"

void fir(int input, int *output, int taps[NUM_TAPS]) {

	static int delay_line[NUM_TAPS] = {};
	int result = 0;

Shift_Accum_Loop:
	for (int i = NUM_TAPS - 1; i >= 0; i--) {
//#pragma HLS pipeline II=1
		if (i == 0) {
			result += input * taps[0];
			delay_line[0] = input;
		} else {
			delay_line[i] = delay_line[i - 1];
			result += delay_line[i] * taps[i];
		}
	}
	*output = result;
}
