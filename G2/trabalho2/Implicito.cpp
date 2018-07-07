#include "glut.h"
#include "Implicito.hpp"
#include "polygonise.h"

// função f da curva implícita
static float f(float x, float y, float z)
{
	return x * x + y * y + z * z - 1;
}

// função que calcula a normal de f
static void n(float x, float y, float z, XYZ& r)
{
	r.x = 2 * x;
	r.y = 2 * y;
	r.z = 2 * z;
}

// função que calcula o produto interno de dois vetores
static float calcula_prod_int(XYZ r, XYZ m)
{
	return r.x * m.x + r.y * m.y + r.z * m.z;
}

// função que calcula a interpolação entre dois pontos se o produto do produto interno deles for menor que zero
// retorna 1 se houve a interpolação e 0 caso contrário
static int interp(double isolevel, float *p, TRIANGLE triangle, XYZ& p1, XYZ& p2, int i, int j)
{
	static bool pFlag = false;

	if (p[i] * p[j] < 0) {
		if (!pFlag)
			p1 = VertexInterp(isolevel, triangle.p[i], triangle.p[j], p[i], p[j]);
		else
			p2 = VertexInterp(isolevel, triangle.p[i], triangle.p[j], p[i], p[j]);

		pFlag = !pFlag;

		return 1;
	}

	return 0;
}

// função que desenha, de fato, a figura
static void desenha_facets(int facets, TRIANGLE *triangles)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < facets; i++)
		for (int j = 0; j < 3; j++)
			glVertex3d(triangles[i].p[j].x, triangles[i].p[j].y, triangles[i].p[j].z);

	glEnd();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
}

// função que desenha a silhueta
static void desenha_silhueta(int facets, TRIANGLE *triangles, XYZ m, double isolevel)
{
	float vProdInt[3];  // vetor com o valor do produto interno de cada vértice do triângulo da normal com o modelview

	XYZ r;  // coordenadas do vetor normal
	XYZ p1, p2;  // coordenadas dos pontos por onde passa a reta, descobertos por interpolação

	int contInterp;  // contador de interpolações

	static bool flag = false;

	glLineWidth(8.0f);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);

	for (int i = 0; i < facets; i++) {
		for (int j = 0; j < 3; j++) {
			n(triangles[i].p[j].x, triangles[i].p[j].y, triangles[i].p[j].z, r);  // calcula a normal de um dos vértices de um triângulo
			vProdInt[j] = calcula_prod_int(r, m);  // calcula o produto interno dessa normal com o vetor modelview
		}

		contInterp  = interp(isolevel, vProdInt, triangles[i], p1, p2, 0, 1);
		contInterp += interp(isolevel, vProdInt, triangles[i], p1, p2, 0, 2);
		contInterp += interp(isolevel, vProdInt, triangles[i], p1, p2, 1, 2);

		if (contInterp == 2) {  // se houve 2 interpolações, uma reta corta o triângulo
			glVertex3d(p1.x, p1.y, p1.z);
			glVertex3d(p2.x, p2.y, p2.z);
		}
	}

	glEnd();
	glLineWidth(1.0f);
}

void Implicito::display_superficie(void)
{
	GRIDCELL grid;
	TRIANGLE triangles[16];
	XYZ modelview;  // coordenadas do vetor modelview

	GLfloat model[16];

	float x, y, z;

	float dx = (_xmax - _xmin) / _pontos;
	float dy = (_ymax - _ymin) / _pontos;
	float dz = (_zmax - _zmin) / _pontos;

	int facets;

	glGetFloatv(GL_MODELVIEW_MATRIX, model);

	modelview.x = model[2];
	modelview.y = model[6];
	modelview.z = model[10];

	x = _xmin;
	for (int i = 0; i < _pontos; i++) {
		y = _ymin;

		for (int j = 0; j < _pontos; j++) {
			z = _zmin;

			for (int k = 0; k < _pontos; k++) {
				grid.p[0].x = x;       grid.p[0].y = y;       grid.p[0].z = z;
				grid.p[1].x = x + dx;  grid.p[1].y = y;       grid.p[1].z = z;
				grid.p[2].x = x + dx;  grid.p[2].y = y + dy;  grid.p[2].z = z;
				grid.p[3].x = x;       grid.p[3].y = y + dy;  grid.p[3].z = z;
				grid.p[4].x = x;       grid.p[4].y = y;       grid.p[4].z = z + dz;
				grid.p[5].x = x + dx;  grid.p[5].y = y;       grid.p[5].z = z + dz;
				grid.p[6].x = x + dx;  grid.p[6].y = y + dy;  grid.p[6].z = z + dz;
				grid.p[7].x = x;       grid.p[7].y = y + dy;  grid.p[7].z = z + dz;

				for (int l = 0; l < 8; l++)
					grid.val[l] = f(grid.p[l].x, grid.p[l].y, grid.p[l].z);

				facets = Polygonise(grid, 0, triangles);

				desenha_facets(facets, triangles);
				desenha_silhueta(facets, triangles, modelview, 0);  // desenha a silhueta
				
				z += dz;
			}

			y += dy;
		}

		x += dx;
	}
}
