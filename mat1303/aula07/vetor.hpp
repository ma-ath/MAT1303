#include <stdlib.h>

#ifndef VETOR
#define VETOR

class vetor {
private:
	int _n;
	float *_v;
public:
	vetor(int dim)
	{
		_n = dim;
		_v = new float[_n];
	}
	vetor(const vetor& w)
	{
		_n = w._n;
		_v = new float[_n];

		for (int i = 0; i < _n; i++)
			_v[i] = w._v[i];
	}
	~vetor(void)  // destrutor
	{
		delete[] _v;
	}
	float get(int i)
	{
		if (i >= 0 && i < _n)
			return _v[i];
		exit(0);
	}
	void set(int i, float x)
	{
		if (i >= 0 && i < _n)
			_v[i] = x;
	}
	void soma(const vetor& u)
	{
		if (u._n != _n)
			return;
		for (int i = 0; i < _n; i++)
			_v[i] += u._v[i];
	}
};

#endif
