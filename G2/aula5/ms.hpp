class ms {
	float xmin, xmax, ymin, ymax;
	int n;
	ms() { n = 0; }
	ms(float xm, float xM, float ym, float yM)
	{
		xmin = xm;
		xmax = xM;
		ymin = ym;
		ymax = yM;
	}
	float f(float x, float y)
	{
		return (x * x + y * y - 1);
	}
	void visualiza()
	{
		float x = xmin;
		float y;

		float dx = (xmax - xmin) / n;
		float dy = (ymax - ymin) / n;

		for (int i = 0; i < n; i++) {
			y = ymin;
			for (int j = 0; j < n; j++) {
				curva(x, y, dx, dy);
			}
			x += dx;
		}
	}
	void curva(float x, float y, float dx, float dy)
	{
		int ind, r1, r2;
		float z[4];

		z[0] = f(x, y);
		z[1] = f(x + dx, y);
		z[2] = f(x + dx, y + dy);
		z[3] = f(x, y + dy);

		ind  = (z[0] < 0) ? 1 : 0;
		ind += (z[1] < 0) ? 2 : 0;
		ind += (z[2] < 0) ? 4 : 0;
		ind += (z[3] < 0) ? 8 : 0;

		r1 = 0;
		r2 = 0;

		switch (ind) {
			case 1:
				r1 = 0;
				r2 = 3;
				break;
			case 2:
				r1 = 0;
				r2 = 1;
				break;
			case 4:
				r1 = 1;
				r2 = 2;
				break;
			case 8:
				r1 = 1;
				r2 = 3;
				break;
			case 3:
				r1 = 1;
				r2 = 3;
				break;
			case 6:
				r1 = 0;
				r2 = 2;
				break;
			case 9:
				r1 = 0;
				r2 = 2;
				break;
			case 12:
				r1 = 1;
				r2 = 3;
				break;
			case 7:
				r1 = 2;
				r2 = 3;
				break;
			case 14:
				r1 = 0;
				r2 = 3;
				break;
			case 13:
				r1 = 0;
				r2 = 1;
				break;
			case 11:
				r1 = 1;
				r2 = 2;
				break;
			case 5:
				break;
			case 10:
				break;
		}

		if ((ind > 0) && (ind < 15)) {
			float xc[4], yc[4];
			xc[0] = x;	xc[1] = x + dx;	xc[2] = x + dx;	xc[3] = x;
			yc[0] = y;	yc[1] = y;	yc[2] = y + dy;	yc[3] = y + dy;
		}
	}
};
