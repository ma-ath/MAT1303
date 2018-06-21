#include <GLUT/glut.h>
#include "funcao.h"
#include "iluminacao.h"
#include "superficie.h"
#include <cmath>
#include <iostream>
using namespace std;

funcao f;
iluminacao I;
superficie s(0,6.3,-0.4,0.4,30);

int xv;
int yv;

float t = 0;
float t1 = 0;

float theta = 135;
float phi   = 45.0;
float gama = 90.0;
float dt = 0.0001;
float scale = 1.0;


void inicia_config()
{
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(scale,scale,scale);
	glRotatef(gama,0,0,1);
	glRotatef(phi  ,0,1,0);
	glRotatef(theta,0,0,1);
//	float x = cos(t1);
//	float y = sin(t1);
//	gluLookAt(x,y,1-t1,0,0,0,0,0,1);
//    t1 += dt;
//	if (fabs(t1) > 20)
//		dt = -dt;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1,1,-1,1,-20,20);
//	gluPerspective(45, 1.333, 0.1, 100);
}

void display()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/*	glBegin(GL_LINES);
	 glColor3f(1,0,0);
	 glVertex3f( 0,0,0);
	 glVertex3f( 1,0,0);

	 glColor3f(0,1,0);
	 glVertex3f(0,1,0);
	 glVertex3f(0,0,0); 
	 
	 glColor3f(0,0,1);
	 glVertex3f(0,0,1);
	 glVertex3f(0,0,0);
	glEnd();
*/
	I.light_on();
	glColor3f(1,1,0);
	s.display_sup();
	I.light_off();
	glutSwapBuffers();
}
void move()
{
	inicia_config();
    glutPostRedisplay();
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

void botao_mouse(int b,int s,int x,int y)
{
	if (b == GLUT_RIGHT_BUTTON)
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

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutCreateWindow("ponto");
	inicia_config();
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutMotionFunc(botao_movimento);
	glutPassiveMotionFunc(movimento);
	glutKeyboardFunc(teclado);
	//glutIdleFunc(move);
	glutMainLoop();
}
