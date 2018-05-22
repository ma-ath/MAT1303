#include "glut.h"
#include "Window.hpp"
#include "Casa.hpp"
#include "Stack.hpp"
#include <iostream>
#include <ctime>

#define PLAYER_ONE 0
#define PLAYER_TWO 1

#define I 0
#define J 1

using namespace std;

int DIMX = 800;  // dimensão x da janela
int DIMY = 800;  // dimensão y da janela

int si, sj;  // índices i e j da matriz de casas que representam os índices da casa selecionada
int mi, mj;  // índices i e j da matriz de casas que representam os índices da casa em que o mouse se encontra
int hi, hj;  // índices i e j da matriz de casas que representam os índices da casa movida com pulo

int cpu[10][2];  // matriz que indica os índices i e j de cada casa verde
int cpuCasa;  // inteiro que indica o índice da última casa modificada da matriz acima

bool selectFlag = false;  // flag: true se alguma casa está selecionada, false caso contrário
bool moveFlag = false;  // flag: true se o mouse está em cima de alguma casa, false caso contrário
bool halmaFlag = false;  // flag: true se o jogador da vez realiza mais de uma jogada, false caso contrário
bool CPUFlag = true;  // flag: true se a CPU do jogador 2 está ativada, false caso contrário
bool turn = PLAYER_ONE;  // booleano que indica de quem é a vez

Window w(-1, 1, -1, 1);  // janela
Casa c[9][9];  // matriz de casas
Stack S;  // pilha para guardar jogadas

// função que retorna true se uma casa é adjacente à casa selecionada, false caso contrário.
bool checkAdjacencia(void)
{
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if ((i == -1) && (j == -1) || ((i == 1) && (j == 1)))
				continue;
			else
				if (mi == si + i && mj == sj + j && c[si + i][sj + j].getColour() == WHITE)
					return true;

	return false;
}

// função que retorna true se é possível executar um pulo na jogada, false caso contrário.
bool checkHalma(void)
{
	if (CPUFlag)  // CPU do jogador 2 não pode realizar pulos
		if (turn == PLAYER_TWO)
			return false;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if ((i == -1) && (j == -1) || ((i == 1) && (j == 1)))
				continue;
			else
				if (mi == si + (2 * i) && mj == sj + (2 * j) && c[si + i][sj + j].getColour() != WHITE)
					return true;

	return false;
}

// função que retorna true se a casa clicada é válida false caso contrário.
// se retornar true, também retorna, como referência, os índices i e j da matriz de casas que representam os índices da casa clicada.
// se retornar false, os valores i e j passados como referência não se alteram.
bool checkCasa(int x, int y, int& ci, int& cj)
{
	float px = x;  // ponto x paramétrico (entre -1 e 1)
	float py = y;  // ponto y paramétrico (entre -1 e 1)
	float l = c[0][0].getl();  // lado do hexágono
	float lcos30 = (l * sqrt(3.0)) / 2;  // metade da largura do hexágono
	float maxy = c[0][0].getcy() + (0.775 * l);  // maior ponto y paramétrico pertencente à casa [0][0]
	float disty = 1.75 * l;  // distância paramétrica do eixo y entre o centro de uma casa e o de outra logo acima ou abaixo
	int faixa = -1;  // faixa horizontal em que a casa se encontra, indo de 0 a 16
	int i, j;  // contadores e índices da matriz de casas

	// adapta pontos x e y para serem paramétricos
	px -= DIMX / 2.0;
	py -= DIMY / 2.0;
	px /= DIMX / 2.0;
	py /= -DIMY / 2.0;

	// seleciona em qual das 17 faixas o mouse foi clicado
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
		return false;
	}

	// anda em todas as casas da faixa clicada
	while (j <= faixa) {
		if ((px >= c[i][j].getcx() - lcos30) && (px <= c[i][j].getcx() + lcos30)) {
			ci = i;
			cj = j;
			return true;
		}

		i--;
		j++;
	}

	return false;
}

// função que retorna true caso já haja um vencedor, false caso contrário
bool checkVencedor(void)
{
	bool check = true;
	static bool msgFlag = false;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - i; j++)
			if (c[i][j].getColour() != RED) {
				check = false;
				break;
			}

	if (check) {
		if (!msgFlag) {
			cout << "Jogador 1 vencedor!" << endl;
			msgFlag = true;
		}
		return true;
	}

	check = true;

	for (int i = 8; i > 4; i--)
		for (int j = 8; j > 12 - i; j--)
			if (c[i][j].getColour() != GREEN) {
				check = false;
				break;
			}

	if (check) {
		if (!msgFlag) {
			cout << "Jogador 2 vencedor!" << endl;
			msgFlag = true;
		}
		return true;
	}
}

// função que seleciona uma casa
void selecionaCasa(int i, int j)
{
	si = i;
	sj = j;
	selectFlag = true;
}

// função que desseleciona uma casa
void desselecionaCasa(void)
{
	selectFlag = false;
	moveFlag = false;
}

// função que ativa o movimento do mouse
void ativaMovimento(int i, int j)
{
	mi = i;
	mj = j;
	moveFlag = true;
}

// função que desativa o movimento do mouse
void desativaMovimento(void)
{
	moveFlag = false;
}

// função que guarda a jogada na pilha
void jogadaPush(void)
{
	Coord co;

	co.si = si;
	co.sj = sj;
	co.mi = mi;
	co.mj = mj;
	co.cpuCasa = cpuCasa;
	co.halmaFlag = halmaFlag;
	co.cor = c[si][sj].getColour();

	S.push(co);
}

// função que retira a jogada da pilha
void jogadaPop(void)
{
	Coord co = S.pop();

	c[co.mi][co.mj].setColour(WHITE);
	c[co.si][co.sj].setColour(co.cor);

	cpuCasa = co.cpuCasa;
	halmaFlag = co.halmaFlag;

	if (!halmaFlag) {
		hi = -1;
		hj = -1;
	} else {
		hi = co.si;
		hj = co.sj;
	}

	if (co.cor == RED) {
		turn = PLAYER_ONE;
	} else {
		turn = PLAYER_TWO;
		cpu[cpuCasa][I] = co.si;
		cpu[cpuCasa][J] = co.sj;
	}
}

// função que faz a jogada
void fazJogada(void)
{
	jogadaPush();
	c[mi][mj].setColour(c[si][sj].getColour());
	c[si][sj].setColour(WHITE);

	if (turn == PLAYER_TWO) {
		cpu[cpuCasa][I] = mi;
		cpu[cpuCasa][J] = mj;
	}

	if (!checkHalma()) {  // se não é mais possível pular casas
		hi = -1;
		hj = -1;
		halmaFlag = false;
		turn = !turn;  // troca a vez do jogador
	} else {
		hi = mi;
		hj = mj;
		halmaFlag = true;
	}
}

// função que desfaz a jogada
void desfazJogada(void)
{
	if (!S.empty()) {
		jogadaPop();
		if (CPUFlag)
			if (turn == PLAYER_TWO)
				jogadaPop();
	}
}

// função que executa a jogada automatizada
void CPUplay(void)
{
	// pega um seed para garantir que o número será aleartório
	srand((unsigned)time(NULL));

	while (turn == PLAYER_TWO) {
		// escolhe uma casa aleatoriamente para andar
		int r = rand() % 10;

		si = cpu[r][I];
		sj = cpu[r][J];

		if (c[si][sj].getColour() != GREEN)
			continue;

		// número que pode ser 0 ou 1 para andar
		int ri = rand() % 2;

		if (si < 8)
			mi = si + ri;

		// número que pode ser 0 ou 1 para andar
		int rj = rand() % 2;

		if (sj < 8)
			mj = sj + rj;

		if (si == mi && sj == mj)
			continue;

		if (c[mi][mj].getColour() != WHITE)
			continue;

		if (checkAdjacencia()) {
			cpuCasa = r;
			fazJogada();
		}
	}

	glutPostRedisplay();
}

// função que prepara o tabuleiro
void preparaTabuleiro(void)
{
	float l = 0.0625;  // lado do hexágono
	float distx = l;  // distância paramétrica do eixo x entre o centro de uma casa e o de outra em qualquer um dos lados
	float disty = 1.75 * l;  // distância paramétrica do eixo y entre o centro de uma casa e o de outra logo acima ou abaixo

	// seta as posições de todas as casas
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			c[i][j].setl(l);
			c[i][j].setcx((j - i) * distx);
			c[i][j].setcy((8 - j - i) * disty);
		}
	}

	int k = 0;

	// seta as cores das casas verdes e guarda seus índices da matriz de casas
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - i; j++) {
			c[i][j].setColour(GREEN);
			cpu[k][I] = i;
			cpu[k][J] = j;
			k++;
		}

	// seta as cores das casas vermelhas
	for (int i = 8; i > 4; i--)
		for (int j = 8; j > 12 - i; j--)
			c[i][j].setColour(RED);
}

// função que desenha o tabuleiro
void desenhaTabuleiro(void)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) 
			c[i][j].draw();

	if (checkVencedor())
		return;

	if (selectFlag)
		c[si][sj].selectDraw();

	if (moveFlag)
		if (!halmaFlag) {
			if (checkAdjacencia() || checkHalma())
				c[mi][mj].selectDraw();
		} else {
			if (checkHalma())
				c[mi][mj].selectDraw();
		}
}

// função que inicia a configuração da escala da janela
void iniciaConfig(float xm, float xM, float ym, float yM)
{
	glLoadIdentity();
	gluOrtho2D(xm, xM, ym, yM);
}

// função display
void display(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	desenhaTabuleiro();
	
	glutSwapBuffers();
}

// função do botão do mouse
void botaoMouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON)
		if (s == GLUT_DOWN) {
			int i, j;
			if (checkCasa(x, y, i, j)) {  // se a casa clicada é válida
				char turnColour;
				if (turn == PLAYER_ONE)
					turnColour = RED;
				else
					turnColour = GREEN;
				char casaColour = c[i][j].getColour();  // pega a cor da casa clicada
				if (casaColour == turnColour) {  // se a casa contém a cor do jogador da vez
					if (!selectFlag) {  // se a casa não está selecionada
						if (!halmaFlag) {  // se não está em condição de halma
							selecionaCasa(i, j);
						} else {
							if (hi == i && hj == j)
								selecionaCasa(i, j);
						}
					} else {
						if (si == i && sj == j)
							desselecionaCasa();
					}
				} else if (casaColour == WHITE) {  // se a casa é branca
					if (selectFlag) {
						if (!halmaFlag) {  // se não está em condição de halma
							if (checkAdjacencia() || checkHalma()) {  // anda a casa
								fazJogada();
								desselecionaCasa();
							}
						} else {  // se está em condição de halma
							if (checkHalma()) {  // anda a casa
								fazJogada();
								desselecionaCasa();
							}
						}
					}
				}
			} else {  // desselecionar casa
				if (selectFlag) {
					desselecionaCasa();
				}
			}
			glutPostRedisplay();
		}

	if (b == GLUT_RIGHT_BUTTON)
		if (s == GLUT_DOWN) {
			if (!selectFlag) {
				desselecionaCasa();
				desfazJogada();
				glutPostRedisplay();
			}
		}

	if (turn == PLAYER_TWO)
		if (CPUFlag)
			CPUplay();
}

// função de movimento do mouse
void movimento(int x, int y)
{
	if (selectFlag) {  // se peça está selecionada
		int i, j;
		if (checkCasa(x, y, i, j)) {
			if (c[i][j].getColour() == WHITE) {
				ativaMovimento(i, j);
			}
		} else {
			if (moveFlag)
				desativaMovimento();
		}
		glutPostRedisplay();
	}
}

// função do teclado
void teclado(unsigned char key, int x, int y)
{
	if (key == ' ')
		if (!selectFlag)
			if (halmaFlag) {
				halmaFlag = false;
				turn = !turn;
			}

	if (key == 'c')
		if (!selectFlag) {
			CPUFlag = !CPUFlag;
			char *m;
			if (CPUFlag)
				m = "CPU do jogador 2 ativada!";
			else
				m = "CPU do jogador 2 desativada!";
			cout << m << endl;
		}

	if (turn == PLAYER_TWO)
		if (CPUFlag)
			CPUplay();
}

// função main
int main(int argc, char **argv)
{
	cout << "Pressione espaco para encerrar sua jogada caso pule casas." << endl;
	cout << "Pressione o botao direito do mouse para voltar uma jogada." << endl;
	cout << "Pressione a letra 'c' para ativar ou desativar a CPU do jogador 2." << endl;
	preparaTabuleiro();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(DIMX, DIMY);
	glutCreateWindow("Stern-Halma");
	iniciaConfig(w.getL(), w.getR(), w.getB(), w.getT());
	glutDisplayFunc(display);
	glutMouseFunc(botaoMouse);
	glutPassiveMotionFunc(movimento);
	glutKeyboardFunc(teclado);
	glutMainLoop();
}
