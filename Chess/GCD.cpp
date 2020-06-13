#include "GCD.h"

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (b)
	{
		a %= b;
		Swap(a, b);
	}
	return a;
}