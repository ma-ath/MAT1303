#include "Funcao.hpp"
#include "glut.h"

void Funcao::grafico(void)
{
	float dx = (_xmax - _xmin) / _pontos;
	float dy = (_ymax - _ymin) / _pontos;
	
	glColor3f(0, 1, 0);

	float x = _xmin;

	for (int i = 0; i < _pontos; i++) {
		float y = _ymin;

		for (int j = 0; j < _pontos; j++) {

			glBegin(GL_LINE_LOOP);
				glVertex3f(x     , y     , f(x     , y     ));
				glVertex3f(x + dx, y     , f(x + dx, y     ));
				glVertex3f(x + dx, y + dy, f(x + dx, y + dy));
				glVertex3f(x     , y + dy, f(x     , y + dy));
			glEnd();

			y += dy;
		}
		x += dx;
	}
}
