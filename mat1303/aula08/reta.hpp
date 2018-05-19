#ifndef RETA
#define RETA

class ponto;

class reta {
private:
	float _a, _b;
public:
	reta(float m, float c)
	{
		_a = m;
		_b = c;
	}
	friend float distancia(ponto p, reta r);
};

#endif
