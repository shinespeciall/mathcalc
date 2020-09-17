#include "math_func.h"

void ChordMethod()
{
	double x = 1.5;
	double x_pre = 0.0;
	for (int k = 0; k < 20; k++)
	{
		double delta = x - x_pre;
		printf("k = %d   x = %lf   x_pre = %lf   delta = %lf\n", k, x, x_pre, delta);
		double current_x = x;
		x = x - (x * x * x - x * x - 1) / (x * x * x - x * x - x_pre * x_pre * x_pre + x_pre * x_pre) * (x - x_pre);
		x_pre = current_x;
		//x = (2 - exp(x)) / 10;
	}
	system("pause");
}