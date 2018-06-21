
class funcao {
	float xmin,xmax,ymin,ymax;
	int pontos;
public:
	funcao() {
		xmin = -1;
		xmax = 1;
		ymin = -1;
		ymax = 1;
		pontos = 10;
	}
	funcao(float xm,float xM,float ym,float yM,int p) {
		xmin   = xm;
		xmax   = xM;
		ymin   = ym;
		ymax   = yM;
		pontos = p;
	}
	float f(float x,float y) {
		return(x*x-y*y);
    }

	void grafico();
};