#include <iostream>
#include <cmath>
using namespace std;

float x = 2.12;  // se escrever float x = 2.12f está frisando que 2.12 é um float

namespace f1 {
	float f(float x)
	{
		float y = x * x;

		cout << x << endl;

		return y;
	}
}

namespace f2 {
	float f(float x)
	{
		float y = cos(x);

		return y;
	}
}

using namespace f2;

int main(void)
{
	float y = 2;

	cout << x << endl;

	for (int i = 0; i < 4; i++) {
		float x = f(i);
		cout << x << endl;
	}

	cout << x << endl;
}

// se houvesse duas funções f com parâmetros float x e int x:
// se chamar f(2), usa-se a função com parâmetro int x
// se chamar f(2.0), usa-se a função com parâmetro float x
// se fosse float x e double x, basta escrever f(2.0f) para usar a função de parâmetro float x

/*
float f(float& x)
{
	float y = x * x;
	x = 8;
	return y;
}

Nessa função, ao fazer x = 8, está colocando 8 na variável que entrou como parâmetro na chamada de função
*/
