#include <cmath>
#include <GLUT/glut.h>

class superficie {
	float umin,umax,vmin,vmax;
	int pontos;
public:
	superficie() {
		umin = -1;
		umax = 1;
		vmin = -1;
		vmax = 1;
		pontos = 10;
	}
	superficie(float um,float uM,float vm,float vM,int p) {
		umin   = um;
		umax   = uM;
		vmin   = vm;
		vmax   = vM;
		pontos = p;
	}
	void s(float u,float v,float *r) {
		r[0] = cos(u) + v * cos(u/2)* cos(u);  
		r[1] = sin(u) + v * cos(u/2)* sin(u); 
		r[2] = v * sin(u/2);
    }
	
	void n(float u,float v,float *r) {
		float v1[3],v2[3];
		float p0[3],p1[3],p2[3];

		float du = (umax-umin)/pontos;
		float dv = (vmax-vmin)/pontos;

		s(u   ,v,p0);
		s(u+du,v,p1);
		s(u,v+dv,p2);

		for(int i=0;i<3;i++) {
			v1[i] = p1[i] - p0[i];
			v2[i] = p2[i] - p0[i];
		}
		r[0] =  v1[1] * v2[2] - v1[2] * v2[1];
		r[1] = -v1[0] * v2[2] + v1[2] * v2[0];
		r[2] =  v1[0] * v2[1] - v1[1] * v2[0];

		float norma = sqrt(r[0] * r[0] + r[1] * r[1] + r[2]*r[2]);
		r[0] /= norma;
		r[1] /= norma;
		r[2] /= norma;
    }

	void display_sup() {
		float du = (umax - umin) / pontos;
		float dv = (vmax - vmin) / pontos;
		float r[3];
		glColor3f(1,0,0);
		float u = umin;
		for(int i=0;i<pontos;i++) {
			float v = vmin;
			for(int j=0;j<pontos;j++) {
				glBegin(GL_QUADS);
					n(u,v,r);
					glNormal3fv(r);
					s(u,v,r);
					glVertex3fv(r); 

					n(u+du,v,r);
					glNormal3fv(r);
					s(u+du,v,r);
					glVertex3f(r[0], r[1], r[2]); 
					
					n(u+du,v+dv,r);
					glNormal3fv(r);
					s(u+du,v+dv,r);
					glVertex3f(r[0], r[1], r[2]); 
					
					n(u,v+dv,r);
					glNormal3fv(r);
					s(u,v+dv,r);
					glVertex3f(r[0], r[1], r[2]); 
				glEnd();
				v += dv;
			}
			u += du;
		}
	}
};
