template <class A> class ponto2d {
private:
	A _v[2];
public:
	ponto2d(A x, A y)
	{
		_v[0] = x;
		_v[1] = y;
	}
	A getx(void);
	ponto2d soma(ponto2d a);
};
