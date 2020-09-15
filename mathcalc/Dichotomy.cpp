#include "math_func.h"

void Dichotomy()
{
	double a = 0.0;
	double b = 1.0;
	double x = 0.0;
	double x_pre = 0;
	for (int k = 0; k < 20; k++)
	{
		x = (a + b) / 2;
		double fx = exp(x) + 10 * x - 2;
		double delta = x - x_pre;
		printf("k = %d   a = %lf   b = %lf   x = %lf   fx = %lf   delta = %lf\n", k, a, b, x, fx, delta);
		if (fx <= 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
		x_pre = x;
	}
	system("pause");
}