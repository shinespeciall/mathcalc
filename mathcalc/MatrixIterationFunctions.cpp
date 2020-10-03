#include "math_func.h"

using namespace Eigen;

void JacobiIteration()
{
	Matrix3f A, D, DI, L, U, I, BJ;
	Vector3f b, fJ, xk;
	A << 5.0, 2.0, 1.0,
		-1.0, 4.0, 2.0,
		2.0, -3.0, 10.0;
	b << -12.0, 20.0, 3.0;
	I = D = DI = L = U = I = BJ = Matrix3f::Zero();
	I(0, 0) = I(1, 1) = I(2, 2) = 1.0;
	D(0, 0) = A(0, 0); D(1, 1) = A(1, 1); D(2, 2) = A(2, 2);
	DI(0, 0) = 1.0 / A(0, 0); DI(1, 1) = 1.0 / A(1, 1); DI(2, 2) = 1.0 / A(2, 2);
	L(1, 0) = -A(1, 0); L(2, 0) = -A(2, 0); L(2, 1) = -A(2, 1);
	U(0, 1) = -A(0, 1); U(0, 2) = -A(0, 2); U(1, 2) = -A(1, 2);
	BJ = I - DI * A;
	fJ = DI * b;
	std::cout << "BJ:" << std::endl << std::fixed << BJ << std::endl << std::endl;
	std::cout << "fJ:" << std::endl << std::fixed << fJ << std::endl;

	xk << 0.0, 0.0, 0.0;
	for (int i = 0; i < 20; ++i)
	{
		xk = BJ * xk + fJ;
		std::cout << "xk:" << std::endl << std::fixed << xk << std::endl;
	}
}

void GSIteration()
{
	Matrix3f A, D, L, DmL, U, I, BGS;
	Vector3f b, fGS, xk;
	A << -1.0, 4.0, 2.0,
		5.0, 2.0, 1.0,
		2.0, -3.0, 10.0;
	b << 20.0, -12.0, 3.0;
	I = D = L = DmL = U = I = BGS = Matrix3f::Zero();
	I(0, 0) = I(1, 1) = I(2, 2) = 1.0;
	D(0, 0) = A(0, 0); D(1, 1) = A(1, 1); D(2, 2) = A(2, 2);
	L(1, 0) = -A(1, 0); L(2, 0) = -A(2, 0); L(2, 1) = -A(2, 1);
	U(0, 1) = -A(0, 1); U(0, 2) = -A(0, 2); U(1, 2) = -A(1, 2);
	DmL = D - L;
	BGS = DmL.inverse() * U;
	fGS = DmL.inverse() * b;
	std::cout << "BBG:" << std::endl << std::fixed << BGS << std::endl << std::endl;
	std::cout << "fGS:" << std::endl << std::fixed << fGS << std::endl;

	xk << 0.0, 0.0, 0.0;
	for (int i = 0; i < 10; ++i)
	{
		xk = BGS * xk + fGS;
		std::cout << "xk:" << std::endl << std::fixed << xk << std::endl;
	}
}