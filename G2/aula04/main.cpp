#include "glut.h"
#include <cmath>
#include <iostream>
using namespace std;
#include "funcao.h"
#include "window.h"
#include "Stack.h"

Stack S;

int DIMX = 400;
int DIMY = 400;

int mov=0;

int xd, yd, xu, yu, xm, ym;

window w(DIMX, DIMY, -1,1,-1,1);

funcao f(w.getL(),w.getR(),500);
void inicia_config(float xm,float xM,float ym,float yM)
{
	glLoadIdentity();
	gluOrtho2D(xm,xM,ym,yM);
	
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
    if(mov == 1)
        w.retangulo(xd, xm, yd, ym);
    
	glutSwapBuffers();
	cout << i++ << endl;
}

void teclado(unsigned char key, int x, int y)
{
	cout << key << endl;
	if (key == 'a')
		cout << x << " , "  << y << endl;

}

void botao_mouse(int b,int s,int x,int y)
{
    if (b == GLUT_LEFT_BUTTON)
    {
        if (s == GLUT_DOWN){
            xd = x;
            yd = y;
            mov = 1;
        }
        else
        if (s == GLUT_UP)
        {
            xu = x;
            yu = y;
            mov = 0;
			S.push(w);
            w.set_window(xd, xu, yd, yu);
            f.set_dominio(w.getL(),w.getR());
            glutPostRedisplay();
            
        }
    }

	if (b == GLUT_RIGHT_BUTTON)
		if (s == GLUT_DOWN)
			if (!S.empty()) {
				window w1 = S.pop();
				w.set_window(w1.getL(), w1.getR(), w1.getB(), w1.getT());
				f.set_dominio(w1.getL(),w1.getR());
				glutPostRedisplay();
			}
}

void botao_movimento(int x,int y)
{
    xm = x;
    ym = y;
    glutPostRedisplay();
}

void movimento(int x,int y)
{
	cout << x << " / " << y << endl;
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400,400);
	glutCreateWindow("ponto");
	inicia_config(w.getL(),w.getR(),w.getB(),w.getT());
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutMotionFunc(botao_movimento);
	glutPassiveMotionFunc(movimento);
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
