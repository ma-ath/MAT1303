#include "glut.h"
#include "Iluminacao.hpp"
#include "Implicito.hpp"
#include "polygonise.h"
#include <iostream>
using namespace std;

Iluminacao I;
Implicito q(-1.4, 1.4, -1.4, 1.4, -1.4, 1.4, 20);

int xv;
int yv;

float theta = 135;
float phi   = 45.0;
float gamma = 90.0;
float scale = 1.0;

void inicia_config(void)
{
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glScalef(scale, scale, scale);

	glRotatef(gamma, 0, 0, 1);
	glRotatef(phi  , 0, 1, 0);
	glRotatef(theta, 0, 0, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.4, 1.4, -1.4, 1.4, -20, 20);
}

void display(void)
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	I.light_on();
	q.display_superficie();
	I.light_off();

	glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y)
{
	cout << key << endl;
	if (key == 'a') {
		inicia_config();
		glutPostRedisplay();
	}
	if (key == 's') {
		scale -= 0.2;
		inicia_config();
		glutPostRedisplay();
	}
	if (key == 'S') {
		scale += 0.2;
		inicia_config();
		glutPostRedisplay();
	}
}

void botao_mouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON) {
		if (s == GLUT_DOWN) {
			xv = x;
			yv = y;
		}
	}
}

void botao_movimento(int x, int y)
{
	theta += (x - xv);
	phi   += (yv - y);

	inicia_config();
	glutPostRedisplay();

	xv = x;
	yv = y;
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutCreateWindow("Polygonise");
	inicia_config();
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutMotionFunc(botao_movimento);
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
