
#include "window.h"
#include "glut.h"

void window::set_window(int xd, int xu, int yd, int yu) {
	float L1, R1, B1, T1; 

	L1 = scale(xd, L, R, DIMX-1);
	R1 = scale(xu, L, R, DIMX-1);

	B1 = scale(yu, T, B, DIMY-1);
	T1 = scale(yd, T, B, DIMY-1);

	L=L1;
	R=R1;
	B=B1;
	T=T1;

	glLoadIdentity();
	gluOrtho2D(L,R,B,T);

}

void window::set_window(const window& u)
{
	L = u.L;
	R = u.R;
	T = u.T;
	B = u.B;
    DIMX = u.DIMX;
    DIMY = u.DIMY;

	glLoadIdentity();
	gluOrtho2D(L,R,B,T);
}

void window::retangulo(int xd, int xm, int yd, int ym){
	float rx1, rx2, ry1, ry2;

		rx1 = scale (xd, L, R, DIMX-1);
		rx2 = scale (xm, L, R, DIMX-1);
		ry1 = scale (yd, T, B, DIMY-1);
		ry2 = scale (ym, T, B, DIMY-1);

		glColor3f(1,0,0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(rx1, ry1);
			glVertex2f(rx1, ry2);
			glVertex2f(rx2, ry2);
			glVertex2f(rx2, ry1);
		glEnd();
}
