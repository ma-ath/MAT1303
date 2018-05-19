#include "reta.hpp"

#ifndef PONTO
#define PONTO

class reta;

class ponto {
private:
	float _x, _y;
public:
	ponto(float x, float y)
	{
		_x = x;
		_y = y;
	}
	friend float distancia(ponto p, reta r);
};

#endif
