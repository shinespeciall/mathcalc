#include "math_func.h"

void NewtonMethod()
{
	double x = 0;
	double x_pre = 0.0;
	double lambda = 1.0;
	for (int k = 0; k < 20; k++)
	{
		double delta = x - x_pre;
		printf("k = %d   x = %lf   x_pre = %lf   delta = %lf\n", k, x, x_pre, delta);
		x_pre = x;
		//x = x - lambda * (x * x * x - 3 * x - 1) / (3 * x * x - 3);
		x = (2 - exp(x)) / 10;
	}
	system("pause");
}