class Implicito
{
private:
	float _xmin, _xmax, _ymin, _ymax, _zmin, _zmax;
	int _pontos;
public:
	Implicito(float xmin = -1,float xmax = 1,
			  float ymin = -1,float ymax = 1,
			  float zmin = -1,float zmax = 1,
			  int p = 10)
	{
		_xmin = xmin;
		_xmax = xmax;
		_ymin = ymin;
		_ymax = ymax;
		_zmin = zmin;
		_zmax = zmax;
		_pontos = p;
	}
	float f(float x, float y, float z)
	{
		float w = x*x + y*y + z*z - 1;
		return w;
	}
	void n(float x, float y, float z, float *r);
	void display_superficie(void);
	void tetraedro(float *v0, float *v1, float *v2, float *v3);
	void display_superficiep(void);
};
