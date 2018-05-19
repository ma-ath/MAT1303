#include "glut.h"
#include <iostream>
#include <cmath>
using namespace std;

void display(void)
{
	static int i = 0;

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);  // define cor dos pontos ou retas (no caso, vermelho)
//	glBegin(GL_POINTS);  // define que vai gerar pontos
//	 glVertex2f(0.5, 0.5);  // define pontos (no caso, somente um)
	glBegin(GL_LINES);  // define que vai gerar retas
//	 glVertex2f(0.5, 0.5);  // ponto inicial da primeira reta
//	 glVertex2f(-1, -0.4);  // ponto final da primeira reta

//	 glColor3f(0, 1, 0);  // muda cor da próxima reta (no caso, para verde)
//	 glVertex2f(0.2, -0.9);  // ponto inicial da segunda reta
//	 glVertex2f(-0.4, 0.5);  // ponto final da segunda reta
	 glVertex2f(-1, 0);  // ponto inicial da primeira reta
	 glVertex2f(1, 0);  // ponto final da primeira reta

	 glColor3f(0, 1, 0);  // muda cor da próxima reta (no caso, para verde)
	 glVertex2f(0, 1);  // ponto inicial da segunda reta
	 glVertex2f(0, -1);  // ponto final da segunda reta
	glEnd();

	float x = -1;
	float dx = (1 - (-1)) / 200.0;

//	glColor3f(1, 1, 1);
//	glBegin(GL_LINE_STRIP);  // pega o penúltimo ponto feito e liga ao último 

	for (int j = 0; j < 200; j++) {
//		float y = x * x;
		float y = sin(x * 3);

		glColor3f(1, 1, 1);
		glBegin(GL_POINTS);
		
		glVertex2f(x, y);
		glEnd();

		x += dx;
	}
//	glEnd();

//	glFlush();
	glutSwapBuffers();
	cout << i++ << endl;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutCreateWindow("ponto");
//	gluOrtho2D(-2, 2, -2, 2);  // mudança de escala (left, right, bottom, top)
	gluOrtho2D(-1, 1, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
}
