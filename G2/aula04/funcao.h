#include "glut.h"
#include <cmath>

class funcao {
	float xmin,xmax;
	int   pontos;
public:
	funcao(void) {
		xmin =    -1;
		xmax =     1;
		pontos = 500;
	}
	funcao(float xm,float xM, int n) {
		xmin = xm;
		xmax = xM;
		pontos = n;
	}
	float f(float x) {
		return(x*x*cos(x));
	}
    void set_dominio(float min, float max){
        xmin = min;
        xmax = max;
    }
	void grafico()
	{
		float x = xmin;
	    float dx = (xmax - xmin)/pontos;
	    glColor3f(1,1,1);
		glBegin(GL_POINTS);
		for(int j = 0;j < pontos;j++) {
		   float y = f(x);
		   glVertex2f(x,y);
		   x += dx;
		}
		glEnd();
	}
};
