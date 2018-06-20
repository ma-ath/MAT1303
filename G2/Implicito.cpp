#include "glut.h"
#include "Implicito.hpp"
#include "polygonise.h"

void Implicito::display_superficie()
{
	float dx = (_xmax - _xmin) / _pontos;
	float dy = (_ymax - _ymin) / _pontos;
	float dz = (_zmax - _zmin) / _pontos;

	float x = _xmin;
	float y,z;

	float v[8][3];
	for(int i=0;i < _pontos; i++ ) {
		y = _ymin;
		for(int j=0;j < _pontos; j++ ) {
			z = _zmin;
			for(int k = 0; k < _pontos; k++) {
				v[0][0] = x;    v[1][0] = x+dx;    v[2][0] = x;      v[3][0] = x+dx;
				v[0][1] = y;    v[1][1] = y;       v[2][1] = y+dy;   v[3][1] = y+dy;
				v[0][2] = z;    v[1][2] = z;       v[2][2] = z;      v[3][2] = z;

				v[4][0] = x;    v[5][0] = x+dx;    v[6][0] = x;      v[7][0] = x+dx;
				v[4][1] = y;    v[5][1] = y;       v[6][1] = y+dy;   v[7][1] = y+dy;
				v[4][2] = z+dz; v[5][2] = z+dz;    v[6][2] = z+dz;   v[7][2] = z+dz;

				tetraedro(v[0], v[2], v[3], v[7]);
				tetraedro(v[0], v[2], v[6], v[7]);
				tetraedro(v[0], v[1], v[3], v[7]);
				tetraedro(v[0], v[1], v[5], v[7]);
				tetraedro(v[0], v[4], v[5], v[7]);
				tetraedro(v[0], v[4], v[6], v[7]);
				z += dz;
			}
			y += dy;
		}
		x += dx;
	}
}

void Implicito::tetraedro(float *v0,float *v1, float *v2,float *v3)
{
	float w0 = f(v0[0],v0[1],v0[2]);
	float w1 = f(v1[0],v1[1],v1[2]);
	float w2 = f(v2[0],v2[1],v2[2]);
	float w3 = f(v3[0],v3[1],v3[2]);

	float p[4][3];
	int n = 0;
	float t;

	if (w0 * w1 < 0)
	{
		t = -w0/(w1-w0);
		for(int i =0;i<3 ;i++)
			p[n][i] = v0[i] + t * (v1[i] - v0[i]);
		n++;
	}
	
	if (w1 * w3 < 0)
	{
		t = -w1/(w3-w1);
		for(int i =0;i<3 ;i++)
			p[n][i] = v1[i] + t * (v3[i] - v1[i]);
		n++;
	}
	if (w0 * w3 < 0)
	{
		t = -w0/(w3-w0);
		for(int i =0;i<3 ;i++)
			p[n][i] = v0[i] + t * (v3[i] - v0[i]);
		n++;
	}
	if (w2 * w3 < 0)
	{
		t = -w2/(w3-w2);
		for(int i =0;i<3 ;i++)
			p[n][i] = v2[i] + t * (v3[i] - v2[i]);
		n++;
	}
	if (w0 * w2 < 0)
	{
		t = -w0/(w2-w0);
		for(int i =0;i<3 ;i++)
			p[n][i] = v0[i] + t * (v2[i] - v0[i]);
		n++;
	}
	if (w1 * w2 < 0)
	{
		t = -w1/(w2-w1);
		for(int i =0;i<3 ;i++)
			p[n][i] = v1[i] + t * (v2[i] - v1[i]);
		n++;
	}
	if (n == 3) {
  	    glColor3f(1,0,0);
		glBegin(GL_TRIANGLES);
	}
	else {
		glColor3f(1,0,0);
		glBegin(GL_QUADS);
	}
//	glBegin(GL_LINE_LOOP);
	float r[3];
	if (n < 5) {
	for(int i = 0;i<n;i++) {
		(*this).n(p[i][0],p[i][1],p[i][2],r);
		glNormal3f(r[0],r[1],r[2]);
		glVertex3f(p[i][0],p[i][1],p[i][2]);
	}
	}
	glEnd();

	
}

void Implicito::n(float x,float y,float z,float *r)
{
	  r[0] = 2*x;
	  r[1] = 2*y;
	  r[2] = 2*z;
	//  cout << r[0] << "  " << r[1] << "  " << r[2] << endl;
	//  float norma = sqrt(r[0] * r[0] + r[1] * r[1] + r[2]*r[2]);
		
	//  r[0] /= norma;		
	//  r[1] /= norma;
	//  r[2] /= norma;
}

void Implicito::display_superficiep()
{
	GRIDCELL grid;
	TRIANGLE triangles[1024];

	grid.p[0].x = _xmin;
	grid.p[1].x = _xmax;
	grid.p[2].x = _xmax;
	grid.p[3].x = _xmin;
	grid.p[4].x = _xmin;
	grid.p[5].x = _xmax;
	grid.p[6].x = _xmax;
	grid.p[7].x = _xmin;

	grid.p[0].y = _ymin;
	grid.p[1].y = _ymin;
	grid.p[2].y = _ymax;
	grid.p[3].y = _ymax;
	grid.p[4].y = _ymin;
	grid.p[5].y = _ymin;
	grid.p[6].y = _ymax;
	grid.p[7].y = _ymax;

	grid.p[0].z = _zmin;
	grid.p[1].z = _zmin;
	grid.p[2].z = _zmin;
	grid.p[3].z = _zmin;
	grid.p[4].z = _zmax;
	grid.p[5].z = _zmax;
	grid.p[6].z = _zmax;
	grid.p[7].z = _zmax;

	Polygonise(grid, 0.000001, triangles);
}
