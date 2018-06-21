
class implicito {
	float xmin,xmax,ymin,ymax,zmin,zmax;
	int pontos;
public:
	implicito(float xm = -1,float xM = 1,
			  float ym = -1,float yM = 1,
			  float zm = -1,float zM = 1,
			  int p = 10)
	{
		xmin = xm;
		xmax = xM;
		ymin = ym;
		ymax = yM;
		zmin = zm;
		zmax = zM;
		pontos = p;
	}
	float f(float x,float y,float z) {
		float w = x*x+y*y+z*z-0.95;
		return w;
	}
	void n(float x,float y,float z,float *r);
	void display_superficie();
	void tetraedro(float *v0,float *v1,float *v2,float *v3);
};
