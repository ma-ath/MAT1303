#ifndef WINDOW_H
#define WINDOW_H

class Window
{
private:
	float _L, _R, _B, _T;
public:
	Window(float L = -1, float R = 1, float B = -1, float T = 1)
	{
		_L = L;
		_R = R;
		_B = B;
		_T = T;
	}
	float getL(void) { return _L; }
	float getR(void) { return _R; }
	float getB(void) { return _B; }
	float getT(void) { return _T; }
};

#endif
