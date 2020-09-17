#include "math_func.h"

void NewtonMethod()
{
	double x = 0.35;
	double x_pre = 0.0;
	double lambda = 1.0;
	for (int k = 0; k < 20; k++)
	{
		double delta = x - x_pre;
		printf("k = %d   x = %lf   x_pre = %lf   delta = %lf\n", k, x, x_pre, delta);
		x_pre = x;
		x = x - lambda * (x * x * x * x + 1.4 * x * x * x - 0.48 * x * x + 1.408 * x - 0.512) / (4 * x * x * x + 4.2 * x * x + 0.96 * x + 1.408);
		//x = (2 - exp(x)) / 10;
	}
	system("pause");
}

void NewtonMethod_2Elements()
{
	double x = 1.0;
	double x_pre = 0.0;
	double y = 1.0;
	double y_pre = 0.0;
	for (int k = 0; k < 20; k++)
	{
		double delta_x = x - x_pre;
		double delta_y = y - y_pre;
		printf("k = %d   x = %lf   delta_x = %lf   y = %lf   delta_y = %lf\n", k, x, delta_x, y, delta_y);
		x_pre = x;
		y_pre = y;
		x = x - (x * x * x + x * x - x * y * y + 6 * x * y - 5 * x - y * y + 2 * y - 5) / (2 * x * x  + 2 * x * x - 2 * y * y + 6 * y);
		y = y - (x * x * y - 3 * x * x + 2 * x * y - 2 * x - y * y * y + 3 * y * y + 5 * y - 15) / (2 * x * x + 2 * x * x - 2 * y * y + 6 * y);
	}
	system("pause");
}