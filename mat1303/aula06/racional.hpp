class racional {
private:
	int _p, _q;
	void simplifica(void);
public:
	racional(int p = 0, int q = 1)
	{
		_p = p;
		_q = q;
		simplifica();
	}
	racional(const racional& r);
	int get_p(void) { return _p; }
	int get_q(void) { return _q; }
	racional soma(const racional& x);
	void print(void);
};
