#include "math_func.h"

void ChordMethod()
{
	double x = 2;
	double x_pre = 1;
	for (int k = 0; k < 20; k++)
	{
		double delta = x - x_pre;
		printf("k = %d   x = %lf   x_pre = %lf   delta = %lf\n", k, x, x_pre, delta);
		double current_x = x;
		x = x - (x * x * x + 2 * x * x + 10 * x - 20) / (x * x * x + 2 * x * x + 10 * x - x_pre * x_pre * x_pre - 2 * x_pre * x_pre - 10 * x_pre) * (x - x_pre);
		x_pre = current_x;
		//x = (2 - exp(x)) / 10;
	}
	system("pause");
}