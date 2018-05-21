#include <stdlib.h>
#include <iostream>
using namespace std;

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
	vetor soma(const vetor& w)
	{
		vetor u(w);

		if (_n != w._n) {
			exit(0);
		} else {
			for (int i = 0; i < _n; i++)
				u._v[i] = _v[i] + w._v[i];
		}
		return u;
	}
	vetor operator+(const vetor& w)
	{
		vetor u(w);

		if (_n != w._n) {
			exit(0);
		} else {
			for (int i = 0; i < _n; i++)
				u._v[i] = _v[i] + w._v[i];
		}
		return u;
	}
	void set(int i, float x)
	{
		if (i < 0 || i >= _n)
			exit(0);
		else
			_v[i] = x;
	}
	void print(void)
	{
		for (int i = 0; i < _n; i++)
			cout << _v[i] << ", ";
	}
	~vetor(void)
	{
		delete[] _v;
	}
	void operator=(const vetor& w)
	{
		delete[] _v;
		_n = w._n;
		_v = new float[_n];

		for (int i = 0; i < _n; i++)
			_v[i] = w._v[i];
	}
	float& operator[](int i)
	{
		if (i < 0 || i >= _n)
			exit(0);
		else
			return _v[i];
	}
	friend vetor soma(vetor x, vetor y)
	{

	}
};
