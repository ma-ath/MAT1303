class Funcao
{
private:
	float _xmin, _xmax, _ymin, _ymax;
	int _pontos;
public:
	Funcao(void)
	{
		_xmin   = -1;
		_xmax   = 1;
		_ymin   = -1;
		_ymax   = 1;
		_pontos = 10;
	}
	Funcao(float xm, float xM, float ym, float yM, int p)
	{
		_xmin   = xm;
		_xmax   = xM;
		_ymin   = ym;
		_ymax   = yM;
		_pontos = p;
	}
	float f(float x, float y) { return (x * x - y * y); }
	void grafico(void);
};
