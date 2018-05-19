#include "Casa.hpp"
#include "glut.h"
#include <stdlib.h>
#include <iostream>

static void prepara_vertices(float cx, float cy, float l, float x[], float y[])
{
	float lsen30 = l / 2;
	float lcos30 = (l * sqrt(3.0)) / 2;

	x[0] = cx;
	x[1] = cx + lcos30;
	x[2] = cx + lcos30;
	x[3] = cx;
	x[4] = cx + lcos30;
	x[5] = cx;
	x[6] = cx;
	x[7] = cx - lcos30;
	x[8] = cx;
	x[9] = cx;
	x[10] = cx - lcos30;
	x[11] = cx - lcos30;

	y[0] = cy + l;
	y[1] = cy + lsen30;
	y[2] = cy - lsen30;
	y[3] = cy + l;
	y[4] = cy - lsen30;
	y[5] = cy - l;
	y[6] = cy + l;
	y[7] = cy - lsen30;
	y[8] = cy - l;
	y[9] = cy + l;
	y[10] = cy - lsen30;
	y[11] = cy + lsen30;
}

void Casa::draw(void)
{
	float r, g, b;
	float x[12];
	float y[12];

	if (_cor == WHITE) {
		r = 1;
		g = 1;
		b = 1;
	} else if (_cor == RED) {
		r = 1;
		g = 0;
		b = 0;
	} else if (_cor == GREEN) {
		r = 0;
		g = 1;
		b = 0;
	} else {
		std::cout << "Erro na cor da casa" << std::endl;
		exit(0);
	}

	prepara_vertices(_cx, _cy, _l, x, y);

	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 12; i++)
		glVertex2f(x[i], y[i]);

	glEnd();
}

void Casa::selectDraw(void)
{
	float r, g, b;
	float x[12];
	float y[12];

	if (_cor == RED) {
		r = 1;
		g = 0;
		b = 0;
	} else if (_cor == GREEN) {
		r = 0;
		g = 1;
		b = 0;
	} else {
		if (_cor != WHITE) {
			std::cout << "Erro na cor da casa" << std::endl;
			exit(0);
		}
	}

	prepara_vertices(_cx, _cy, _l, x, y);

	glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 12; i++)
		glVertex2f(x[i], y[i]);

	glEnd();

	if (_cor == WHITE)
		return;

	prepara_vertices(_cx, _cy, _l - 0.0125, x, y);

	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < 12; i++)
		glVertex2f(x[i], y[i]);

	glEnd();
}
