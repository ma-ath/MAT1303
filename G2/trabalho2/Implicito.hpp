#ifndef IMPLICITO_HPP
#define IMPLICITO_HPP

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
		return x * x + y * y + z * z - 1;
	}
	void display_superficie(void);
};

#endif
