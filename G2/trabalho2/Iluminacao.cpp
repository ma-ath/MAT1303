#include "Iluminacao.hpp"
#include "glut.h"

Iluminacao::Iluminacao()
{
	_mat_especular[0] = 1;
	_mat_especular[1] = 1;
	_mat_especular[2] = 1;
	_mat_especular[3] = 1;
	_mat_back[0] = 1;
	_mat_back[1] = 1;
	_mat_back[2] = 0;
	_mat_back[3] = 1;
	_light_position[0] = 2.0;
	_light_position[1] = 2.0;
	_light_position[2] = 2.0;
	_light_position[3] = 2.0;
	_light_position1[0] = -2.0;
	_light_position1[1] = -2.0;
	_light_position1[2] = -2.0;
	_light_position1[3] = 2.0;
	_light_position2[0] = -2.0;
	_light_position2[1] = 2.0;
	_light_position2[2] = -2.0;
	_light_position2[3] = 2.0;
	_mat_shiness = 50;
}

void Iluminacao::light_on()
{
	glShadeModel(GL_FLAT);
	glMaterialfv(GL_FRONT, GL_SPECULAR, _mat_especular);
	glMaterialf(GL_FRONT, GL_SHININESS, _mat_shiness);
	glLightfv(GL_LIGHT0, GL_POSITION, _light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, _light_position1);
	glLightfv(GL_LIGHT2, GL_POSITION, _light_position2);
	glLightfv(GL_LIGHT0,GL_DIFFUSE, _mat_especular);
	glLightfv(GL_LIGHT1,GL_DIFFUSE, _mat_especular);
	glLightfv(GL_LIGHT2,GL_DIFFUSE, _mat_especular);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
    glMaterialfv(GL_BACK, GL_DIFFUSE, _mat_back);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, _mat_back);
}

void Iluminacao::light_off()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
}
