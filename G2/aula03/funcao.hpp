#include "glut.h"
#include <cmath>

class Funcao {
private:
	float _xmin, _xmax;
	int _pontos;
public:
	Funcao(void)
	{
		_xmin = -1;
		_xmax = 1;
		_pontos = 500;
	}
	Funcao(float xmin, float xmax, int n)
	{
		_xmin = xmin;
		_xmax = xmax;
		_pontos = n;
	}
	float f(float x)
	{
		return (x * x);
	}
	float getxmin(void)
	{
		return _xmin;
	}
	void grafico(void)
	{
		float x = _xmin;
		float dx = (_xmax - _xmin)/ _pontos;

		glColor3f(1,1,1);
		glBegin(GL_POINTS);

		for(int j =0;j < _pontos;j++) {
			float y = f(x);
			glVertex2f(x,y);
			x += dx;
		}

		glEnd();
	}
	void setDomain(float xmin, float xmax)
	{
		_xmin = xmin;
		_xmax = xmax;
	}
};
