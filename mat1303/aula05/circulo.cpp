#include "circulo.hpp"

circulo::circulo(void)
{
	_raio = 1;
	_centrox = 0;
	_centroy = 0;
}

double circulo::area(void)
{
	return (3.14 * _raio * _raio);
}

circulo::circulo(double r, double cx, double cy)
{
	_raio = r;
	_centrox = cx;
	_centroy = cy;
}
