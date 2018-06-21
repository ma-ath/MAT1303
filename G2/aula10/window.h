class window {
	float L,R,B,T;
public:
	window(float _L = -1,float _R = 1,float _B = -1,float _T = 1)
	{
		L = _L;
		R = _R;
		T = _T;
		B = _B;
	}

	float getL() { return L; }
	float getR() { return R; }
	float getB() { return B; }
	float getT() { return T; }
};