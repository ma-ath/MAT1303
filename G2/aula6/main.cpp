#include "glut.h"
#include <cmath>
#include <iostream>
using namespace std;

int xv, yv;

float gamma = 90.0;
float phi = 45.0;
float theta = 135;

void inicia_config()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(gamma, 0, 0, 1);
	glRotatef(phi, 0, 1, 0);
	glRotatef(theta, 0, 0, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -20, 20);  // -20 a 20 para não cortar o Torus
}

void display()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	 glColor3f(1,0,0);
	 glVertex3f(0,0,0);
	 glVertex3f(1,0,0);

	 glColor3f(0,1,0);
	 glVertex3f(0,1,0);
	 glVertex3f(0,0,0);

	 glColor3f(0,0,1);
	 glVertex3f(0,0,1);
	 glVertex3f(0,0,0);
	glEnd();

	glColor3f(1,1,0);
	glutWireTorus(1,1.2,15,15);

	glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y)
{
	if (key == 'a') {
		inicia_config();
		glutPostRedisplay();
	}
}

void botao_mouse(int b,int s,int x,int y)
{
	if (b == GLUT_LEFT_BUTTON)
	{
		if (s == GLUT_DOWN) {
			xv = x;
			yv = y;
		}
		else
			if (s == GLUT_UP)
			    cout << "botao direito solto" << x << ", " << y << endl;
	}
}

void botao_movimento(int x,int y)
{
	theta += (x - xv);
	phi   += (yv - y);
	inicia_config();
	glutPostRedisplay();
	xv = x;
	yv = y;
}

void movimento(int x,int y)
{
	cout << x << " / " << y << endl;
}

void move()
{
	inicia_config();
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400,400);
	glutCreateWindow("ponto");
	inicia_config();
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutMotionFunc(botao_movimento);
	glutPassiveMotionFunc(movimento);
	glutKeyboardFunc(teclado);
	glutIdleFunc(move);
	glutMainLoop();
}
