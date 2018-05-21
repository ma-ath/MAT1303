#ifndef WINDOW_H
#define WINDOW_H

class window {
	float L,R,B,T;
    int DIMX,DIMY;
public:
	window(int DX, int DY,float _L = -1,float _R = 1,float _B = -1,float _T = 1)
	{
		L = _L;
		R = _R;
		T = _T;
		B = _B;
        DIMX = DX;
        DIMY = DY;
        
    }
	window(const window& u)
	{
		L = u.L;
		R = u.R;
		T = u.T;
		B = u.B;
        DIMX = u.DIMX;
        DIMY = u.DIMY;
        
    }
	window(void)
	{
        DIMX = 400;
        DIMY = 400;
    }
    float scale (int p, float min, float max, int dim){
        float x = min + p/(float)dim * (max-min);
        
        return x;
    }
    
    void retangulo(int xd, int xm, int yd, int ym);
    void set_window(int xd, int xu, int yu, int yd);
    void set_window(const window& u);
	float getL() { return L; }
	float getR() { return R; }
	float getB() { return B; }
	float getT() { return T; }
};

#endif
