#include "racional.hpp"
#include <iostream>
using namespace std;

racional::racional(const racional& r)  // const para nao ter chance de mudar nenhum valor de r
{
	_p = r._p;
	_q = r._q;
}

void racional::simplifica(void)
{
	int r;
	int p = _p;
	int q = _q;

	do {
		r = p % q;
		p = q;
		q = r;
	} while (r != 0);

	_p = _p / p;
	_q = _q / p;
}

racional racional::soma(const racional& x)
{
	racional y;

	y._p = _p * x._q + _q * x._p;
	y._q = _q * x._q;
	y.simplifica();

	return y;
}

void racional::print(void)
{
	if ((_q == 1) || (_q == -1))
		cout << _p * _q << endl;
	else
		cout << _p << '/' << _q << endl;

}
