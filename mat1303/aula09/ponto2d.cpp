#include "ponto2d.hpp"

template <class A> A ponto2d<A>::getx(void)
{
	return _v[0];
}

template <class A> ponto2d<A>::soma(ponto2d a)
{
	ponto2d x(0, 0);

	x._v[0] = _v[0] + a._v[0];
	x._v[1] = _v[1] + a._v[1];

	return x;
}
