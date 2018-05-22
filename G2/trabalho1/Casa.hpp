#ifndef CASA_H
#define CASA_H

#define WHITE 0
#define RED 1
#define GREEN 2

class Casa
{
private:
	float _cx;  // centro x da casa, paramétrico
	float _cy;  // centro y da casa, paramétrico
	float _l;  // lado do hexágono, paramétrico
	char _cor;  // cor da casa
public:
	Casa(void) { _l = 0; _cor = WHITE; }
	float getcx(void) { return _cx; }
	float getcy(void) { return _cy; }
	float getl(void) { return _l; }
	float getColour(void) { return _cor; }
	void setcx(float cx) { _cx = cx; }
	void setcy(float cy) { _cy = cy; }
	void setl(float l) { _l = l; }
	void setColour(char cor) { _cor = cor; }
	void draw(void);
	void selectDraw(void);
};

#endif
