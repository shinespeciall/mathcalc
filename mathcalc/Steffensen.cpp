#include "math_func.h"

void steffensen()
{
	double x_tier = 0.0;
	double x_ave = 0.0;
	double x = 0.5;
	for (int k = 0; k < 20; k++)
	{
		printf("k = %d   x_tier = %lf   x_ave = %lf   x = %lf\n", k, x_tier, x_ave, x);
		x_tier = sqrt(sin(x));
		x_ave = sqrt(sin(x_tier));
		x = x_tier - ((x_ave - x_tier) * (x_ave - x_tier) / (x_ave - 2 * x_tier + x));
	}
	system("pause");
}