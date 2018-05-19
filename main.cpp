#include "glut.h"
#include "Window.hpp"
#include "Casa.hpp"
#include "Stack.hpp"
#include <iostream>

#define PLAYER_ONE 0
#define PLAYER_TWO 1

using namespace std;

int DIMX = 800;
int DIMY = 800;

int si, sj;
int mi, mj;

bool selectFlag = 0;
bool moveFlag = 0;
bool turn = PLAYER_ONE;

Window w(-1, 1, -1, 1);
Casa c[9][9];
Stack S;

bool check_adjacencia(void)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if ((i == -1) && (j == -1) || ((i == 1) && (j == 1)))
				continue;
			else
				if (mi == si + i && mj == sj + j)
					return 1;

	return 0;
}

bool check_halma(void)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if ((i == -1) && (j == -1) || ((i == 1) && (j == 1)))
				continue;
			else
				if (mi == si + (2 * i) && mj == sj + (2 * j) && c[si + i][sj + j].getColour() != WHITE)
					return 1;

	return 0;
}

bool check_casa(int x, int y, int& ii, int &jj)
{
	float px = x;
	float py = y;
	float l = c[0][0].getl();
	float lcos30 = (l * sqrt(3.0)) / 2;
	float maxy = c[0][0].getcy() + (0.775 * l);
	float disty = 1.75 * l;
	int i, j;
	int faixa = -1;
	int casa;

	px -= DIMX / 2.0;
	py -= DIMY / 2.0;
	px /= DIMX / 2.0;
	py /= -DIMY / 2.0;

	for (i = 0; i < 17; i++, maxy -= disty) {
		if ((py <= maxy) && (py >= maxy - disty)) {
			faixa = i;
			break;
		}
	}

	if (faixa >= 0 && faixa < 9) {
		i = faixa;
		j = 0;
	} else if (faixa >= 9 && faixa < 17) {
		i = 8;
		j = faixa - 8;
		faixa = 8;
	} else {
		return 0;
	}

	while (j <= faixa) {
		if ((px >= c[i][j].getcx() - lcos30) && (px <= c[i][j].getcx() + lcos30)) {
			ii = i;
			jj = j;
			return 1;
		}

		i--;
		j++;
	}

	return 0;
}

void selecionarCasa(int i, int j)
{
	si = i;
	sj = j;
	selectFlag = 1;
}

void desselecionarCasa(void)
{
	si = -1;
	sj = -1;
	selectFlag = 0;
	moveFlag = 0;
}

void jogadaPush(void)
{
	Coord co;

	co.si = si;
	co.sj = sj;
	co.mi = mi;
	co.mj = mj;
	co.cor = c[si][sj].getColour();

	S.push(co);
}

void jogadaPop(void)
{
	Coord co = S.pop();

	c[co.mi][co.mj].setColour(WHITE);
	c[co.si][co.sj].setColour(co.cor);

	if (co.cor == RED)
		turn = PLAYER_ONE;
	else
		turn = PLAYER_TWO;
}

void prepara_tabuleiro(void)
{
	float l = 0.0625;
	float distx = l;
	float disty = 1.75 * l;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			c[i][j].setl(l);
			c[i][j].setcx((j - i) * distx);
			c[i][j].setcy((8 - j - i) * disty);
		}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - i; j++)
			c[i][j].setColour(GREEN);

	for (int i = 8; i > 4; i--)
		for (int j = 8; j > 12 - i; j--)
			c[i][j].setColour(RED);
}

void desenha_tabuleiro(void)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) 
			c[i][j].draw();

	if (selectFlag)
		c[si][sj].selectDraw();

	if (moveFlag)
		if (check_adjacencia() || check_halma())
			c[mi][mj].selectDraw();
}

void inicia_config(float xm, float xM, float ym, float yM)
{
	glLoadIdentity();
	gluOrtho2D(xm, xM, ym, yM);
}

void display(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	desenha_tabuleiro();
	
	glutSwapBuffers();
}

void botao_mouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON)
		if (s == GLUT_DOWN) {
			int i, j;
			if (check_casa(x, y, i, j)) {  // se alguma casa foi selecionada
				char turnColour;

				if (turn == PLAYER_ONE)
					turnColour = RED;
				else
					turnColour = GREEN;
				if (c[i][j].getColour() == turnColour) {  // se a casa contém a cor do jogador da vez
					if (si == i && sj == j) {  // desselecionar casa 
						desselecionarCasa();
					} else {  // selecionar casa para andar
						if (!selectFlag) {
							selecionarCasa(i, j);
						}
					}
				} else if (c[i][j].getColour() == WHITE) {  // se a casa é branca
					if (selectFlag) {
						if (check_adjacencia() || check_halma()) {  // anda a casa
							jogadaPush();
							char cor = c[si][sj].getColour();
							c[si][sj].setColour(WHITE);
							c[mi][mj].setColour(cor);
							if (!check_halma())  // se não é mais possível pular casas
								turn = !turn;  // troca a vez do jogador
							desselecionarCasa();
						}
					}
				}
			} else {  // desselecionar casa
				if (selectFlag) {
					desselecionarCasa();
				}
			}
		glutPostRedisplay();
		}
	if (b == GLUT_RIGHT_BUTTON)
		if (s == GLUT_DOWN) {
			if (!selectFlag) {
				desselecionarCasa();
				if (!S.empty()) {
					jogadaPop();
					glutPostRedisplay();
				}
			}
		}
}

void movimento(int x, int y)
{
	if (selectFlag) {  // se peça está selecionada
		int i, j;
		if (check_casa(x, y, i, j)) {
			if (c[i][j].getColour() == WHITE) {
				mi = i;
				mj = j;
				moveFlag = 1;
				glutPostRedisplay();
			}
		} else {
			if (moveFlag)
				moveFlag = 0;
		}
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{
	prepara_tabuleiro();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(DIMX, DIMY);
	glutCreateWindow("Stern-Halma");
	inicia_config(w.getL(), w.getR(), w.getB(), w.getT());
	glutDisplayFunc(display);
	glutMouseFunc(botao_mouse);
	glutPassiveMotionFunc(movimento);
	glutMainLoop();
}
