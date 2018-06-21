#include "funcao.h"
#include <GLUT/glut.h>

void funcao::grafico()
{
	float dx = (xmax - xmin) / pontos;
	float dy = (ymax - ymin) / pontos;
	glColor3f(1,0,0);
	float x = xmin;
	for(int i=0;i<pontos;i++) {
		float y = ymin;
	    for(int j=0;j<pontos;j++) {
			glBegin(GL_QUADS);
				glVertex3f(x   ,y   ,f(x   ,y   ));
				glVertex3f(x+dx,y   ,f(x+dx,y   ));
				glVertex3f(x+dx,y+dy,f(x+dx,y+dy));
				glVertex3f(x   ,y+dy,f(x   ,y+dy));
			glEnd();
			y += dy;
	    }
		x += dx;
	}
}
