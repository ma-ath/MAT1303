#include "glut.h"
#include <cmath>
#include <iostream>
#include "funcao.hpp"
#include "window.hpp"
using namespace std;

Window w(-1, 1, -1, 1);

Funcao f(w.getL(), w.getR(), 500);

void inicia_config(float xm, float xM, float ym, float yM)
{
	glLoadIdentity();
	gluOrtho2D(xm, xM, ym, yM);
}

void display()
{
	static int i = 0;
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1,0,0);
	glBegin(GL_LINES);
	 glVertex2f(-1,0);
	 glVertex2f( 1,0);

	 glColor3f(0,1,0);
	 glVertex2f(0,1);
	 glVertex2f(0,-1);
	glEnd();

	f.grafico();

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
	if (b == GLUT_RIGHT_BUTTON)
		if (s == GLUT_DOWN)
			cout << "botao direito pressionado " << x << ',' << y << endl;
		else if (s == GLUT_UP)
			cout << "botao direito solto " << x << ',' << y << endl;
}

void botao_movimento(int x, int y)
{
	cout << x << ':' << y << endl;
}

void movimento(int x, int y)
{
	cout << x << '/' << y << endl;
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400,400);
	glutCreateWindow("ponto");
	inicia_config(w.getL(), w.getR(), w.getB(), w.getT());
	inicia_config(w.getL(), w.getR(), w.getB(), w.getT());
//	gluOrtho2D(xmin, xmax, ymin, ymax);
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutMotionFunc(botao_movimento);
//	glutPassiveMotionFunc(movimento);
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
