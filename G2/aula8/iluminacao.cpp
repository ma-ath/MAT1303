
#include "iluminacao.h" 
#include <GLUT/glut.h>

iluminacao::iluminacao()
{
	mat_especular[0] = 1;
	mat_especular[1] = 1;
	mat_especular[2] = 1;
	mat_especular[3] = 1;
	mat_back[0] = 1;
	mat_back[1] = 1;
	mat_back[2] = 0;
	mat_back[3] = 1;
	light_position[0] = 2.0;
	light_position[1] = 2.0;
	light_position[2] = 2.0;
	light_position[3] = 2.0;
	light_position1[0] = -2.0;
	light_position1[1] = -2.0;
	light_position1[2] = -2.0;
	light_position1[3] = 2.0;
	light_position2[0] = -2.0;
	light_position2[1] = 2.0;
	light_position2[2] = -2.0;
	light_position2[3] = 2.0;
	mat_shiness = 50;
}

void iluminacao::light_on()
{
	glShadeModel(GL_FLAT);
//	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_especular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shiness);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT0,GL_DIFFUSE, mat_especular);
	glLightfv(GL_LIGHT1,GL_DIFFUSE, mat_especular);
	glLightfv(GL_LIGHT2,GL_DIFFUSE, mat_especular);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
    glMaterialfv(GL_BACK, GL_DIFFUSE, mat_back);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_back);
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	//glEnable(GL_NORMALIZE);
}

void iluminacao::light_off()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
}

/*
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);  // até GL_LIGHT7
float pos0[] = {1, 2, 3, 1};  // x, y, z, w
float dif0[] = {1, 0, 0, 1};  // cor da luz (vermelha)
float spec0[] = {1, 1, 1, 1};
float amb0[] = {1, 0, 0, 1};  // r, g, b, 1
glLightfv(GL_LIGHT0, GL_POSITION, pos0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, dif0);
glLightfv(GL_LIGHT0, GL_SPECULAR, spec0);
glLightfv(GL_LIGHT0, GL_AMBIENT, amb0);
*/
