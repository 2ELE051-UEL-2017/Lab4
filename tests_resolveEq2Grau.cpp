#include "CppUTest/TestHarness.h"

extern "C" {
	int resolveEq2Grau(double a, double b, double c, double* x1, double* x2);
}

TEST_GROUP(resolveEq2Grau)
{
};

TEST(resolveEq2Grau, a0b0c0)
{
	LONGS_EQUAL(-1, resolveEq2Grau(0.0, 0.0, 0.0, NULL, NULL));
}

TEST(resolveEq2Grau, a0b0c1)
{
	LONGS_EQUAL(-1, resolveEq2Grau(0.0, 0.0, 1.0, NULL, NULL));
}

TEST(resolveEq2Grau, a0b1c1)
{
	LONGS_EQUAL(-1, resolveEq2Grau(0.0, 1.0, 1.0, NULL, NULL));
}

TEST(resolveEq2Grau, a1b4c5)
{
	LONGS_EQUAL(0, resolveEq2Grau(1.0, 4.0, 5.0, NULL, NULL));
}

TEST(resolveEq2Grau, a1b0c0ApenasRetorno)
{
	double x1, x2;

	LONGS_EQUAL(1, resolveEq2Grau(1.0, 0.0, 0.0, &x1, &x2));
}

TEST(resolveEq2Grau, a1b1c0ApenasRetorno)
{
	double x1, x2;

	LONGS_EQUAL(2, resolveEq2Grau(1.0, 1.0, 0.0, &x1, &x2));
}

TEST(resolveEq2Grau, a1b0c0)
{
	double x1, x2;

	LONGS_EQUAL(1, resolveEq2Grau(1.0, 0.0, 0.0, &x1, &x2));

	DOUBLES_EQUAL(0.0, x1, 1e-10);
}

TEST(resolveEq2Grau, a1b1c0)
{
	double x1, x2;

	LONGS_EQUAL(2, resolveEq2Grau(1.0, 1.0, 0.0, &x1, &x2));

	DOUBLES_EQUAL(-1.0, x1, 1e-10);
	DOUBLES_EQUAL(0.0, x2, 1e-10);
}

TEST(resolveEq2Grau, a1b0cm1)
{
	double x1, x2;

	LONGS_EQUAL(2, resolveEq2Grau(1.0, 0.0, -1.0, &x1, &x2));

	DOUBLES_EQUAL(-1.0, x1, 1e-10);
	DOUBLES_EQUAL(1.0, x2, 1e-10);
}

TEST(resolveEq2Grau, a1bm5c6)
{
	double x1, x2;

	LONGS_EQUAL(2, resolveEq2Grau(1.0, -5.0, 6.0, &x1, &x2));

	DOUBLES_EQUAL(2.0, x1, 1e-10);
	DOUBLES_EQUAL(3.0, x2, 1e-10);
}
