/* Metodo da Bolha (ordenação de um vetor) */

#include <iostream>
using namespace std;

void ordena(float *v, int n)
{
	char flag = 1;

	while (flag) {
		flag = 0;

		for (int i = 0; i < (n - 1); i++) {
			if (v[i] > v[i + 1]) {
				float swap = v[i];
				v[i] = v[i + 1];
				v[i + 1] = swap;
				flag = 1;
			}
		}
	}
}

int main(void)
{
	float x[10];
	const int n = 10;

	/* Entrada de Dados */
	cout << "Entre com os numeros para ordenacao" << endl;
	for (int i = 0; i < n; i ++) {
		cout << endl << " numero [" << i << "] = ";
		cin >> x[i];
	}

	/* Ordena a sequencia de numeros */
	ordena(x, n);

	/* Imprime a sequencia de numeros ordenada */
	cout << endl << " Sequencia ordenada : " << endl;
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
}
