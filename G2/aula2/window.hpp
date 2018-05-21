#include "glut.h"

class Window {
private:
	float _L, _R, _B, _T;
	int _DIMX, _DIMY;
public:
	Window(int DIMX, int DIMY, float L = -1, float R = 1, float B = -1, float T = 1)
	{
		_DIMX = DIMX;
		_DIMY = DIMY;
		_L = L;
		_R = R;
		_B = B;
		_T = T;
	}
	float getL(void)
	{
		return _L;
	}
	float getR(void)
	{
		return _R;
	}
	float getB(void)
	{
		return _B;
	}
	float getT(void)
	{
		return _T;
	}
	float scale(int p, float min, float max, int dim)
	{
		float x = min + p / (float)dim * (max - min);

		return x;
	}
	void setWindow(float xd, float xu, float yd, float yu)
	{
		float L1, R1, B1, T1;

		L1 = scale(xd, _L, _R, _DIMX-1);
		R1 = scale(xu, _L, _R, _DIMX-1);
		B1 = scale(yu, _T, _B, _DIMY-1);  // 0 a 399 vai para 1 a -1
		T1 = scale(yd, _T, _B, _DIMY-1);  // 0 a 399 vai para 1 a -1

		_L = L1;
		_R = R1;
		_B = B1;
		_T = T1;

		glLoadIdentity();
		gluOrtho2D(_L, _R, _B, _T);
	}
	void retangulo(int xd, int xm, int yd, int ym)
	{
		float r_xm, r_xM, r_ym, r_yM;

		r_xm = scale(xd, _L, _R, _DIMX-1);
		r_xM = scale(xm, _L, _R, _DIMX-1);
		r_ym = scale(yd, _T, _B, _DIMY-1);
		r_yM = scale(ym, _T, _B, _DIMY-1);

		glColor3f(1, 0, 0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(r_xm, r_ym);
			glVertex2f(r_xm, r_yM);
			glVertex2f(r_xM, r_yM);
			glVertex2f(r_xM, r_ym);
		glEnd();
	}
};
