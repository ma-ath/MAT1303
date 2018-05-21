#include <iostream>
using namespace std;

void maximo_minimo(float *v, int n, float &mx, float &mn)
{
	float maior = v[0];
	float menor = v[0];

	float *w = new float[n];

	for (int i = 0; i < n; i++)
		w[i] = v[i];

	for (int i = 1; i < n; i++) {
		if (w[i] > maior)
			maior = v[i];
		if (w[i] < menor)
			menor = v[i];
	}

	mx = maior;
	mn = menor;

	delete[] w;
}

int main(void)
{
	int n;
	float mx, mn;
	float *u;
	float **A;
	
	cin >> n;
	u = new float[n];
	A = new float *[n];

	for (int i = 0; i < n; i++)
		cin >> u[i];

	for (int i = 0; i < n; i++)
		A[i] = new float [n];

	maximo_minimo(u, 5, mx, mn);

	cout << " max = " << mx << " min = " << mn << endl;

	delete[] u;  // não precisa desalocar aqui porque está no fim da main
}
