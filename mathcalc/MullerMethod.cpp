#include "math_func.h"

// the following code modified from https://www.codewithc.com/c-program-for-mullers-method/

#define I 2
float f(float x)
{
	return x*x*x - x*x - 1;
}
void MullerMethod()
{
	int i, k;
	double x[4], li, di, mu, s, l, allerr;
	// Enter the three initial guesses
	x[0] = 0.0; //small
	x[1] = 1.0;
	x[2] = 1.5; //big
	allerr = 0.0000001;
	for (k = 1; k <= 20; k++)
	{
		li = (x[I] - x[I - 1]) / (x[I - 1] - x[I - 2]);
		di = (x[I] - x[I - 2]) / (x[I - 1] - x[I - 2]);
		mu = f(x[I - 2])*li*li - f(x[I - 1])*di*di + f(x[I])*(di + li);
		s = sqrt((mu*mu - 4 * f(x[I])*di*li*(f(x[I - 2])*li - f(x[I - 1])*di + f(x[I]))));
		if (mu < 0)
			l = (2 * f(x[I])*di) / (-mu + s);
		else
			l = (2 * f(x[I])*di) / (-mu - s);
		x[I + 1] = x[I] + l * (x[I] - x[I - 1]);
		printf("k = %d, xk = %lf, xk-1 = %lf, xk-2 = %lf, x = %lf\n", k, x[I - 2], x[I - 1], x[I], x[I + 1]);
		if (fabs(x[I + 1] - x[I]) < allerr)
		{
			system("pause");
			return;
		}
		for (i = I - 2; i < 3; i++)
			x[i] = x[i + 1];
	}
	printf("The required solution does not converge or iterations are insufficient\n");
}