#include "glut.h"
#include <iostream>
#include "funcao.hpp"
#include "window.hpp"
using namespace std;

int DIMX = 400;
int DIMY = 400;

int xd, yd, xu, yu, xm, ym;

bool mov = 0;

Window w(DIMX, DIMY, -1, 1, -1, 1);

Funcao f(w.getL(), w.getR(), 500);

void inicia_config(float xm, float xM, float ym, float yM)
{
	glLoadIdentity();
	gluOrtho2D(xm, xM, ym, yM);
}

void display(void)
{
	static int i = 0;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	 glVertex2f(-1, 0);
	 glVertex2f( 1, 0);

	 glColor3f(0, 1, 0);
	 glVertex2f(0, 1);
	 glVertex2f(0, -1);
	glEnd();

	f.grafico();

	if (mov == 1)
		w.retangulo(xd, xm, yd, ym);

	glutSwapBuffers();
	cout << i++ << endl;
}

void teclado(unsigned char key, int x, int y)
{
	cout << key << endl;

	if (key == 'a')
		cout << x << ',' << y << endl;
}

void botao_mouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON)
		if (s == GLUT_DOWN) {
			xd = x;
			yd = y;
			mov = 1;
		} else if (s == GLUT_UP) {
			xu = x;
			yu = y;
			mov = 0;

			w.setWindow(xd, xu, yd, yu);
			f.setDomain(w.getL(), w.getR());
			glutPostRedisplay();  // dá display de novo logo após a interrupção do mouse
			// display() faz imediatamente após a chamada, glutPostRedisplay() faz ao fim da interrupção ou da função
		}
}

void botao_movimento(int x, int y)
{
	xm = x;
	ym = y;
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(DIMX, DIMY);
	glutCreateWindow("ponto");
	inicia_config(w.getL(), w.getR(), w.getB(), w.getT());
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutMotionFunc(botao_movimento);
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
