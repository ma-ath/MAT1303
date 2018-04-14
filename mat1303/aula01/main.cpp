#include <iostream>
using namespace std;  // std determina comandos cout e endl como standard

int main(void)
{
	int a, f;
	
	a = 2;

	if (a > 3) {
		f = 2 + a;
		cout << a << endl;
	} else {
		f = 4;
		a = 3;
	}

	for (int i = 1; i < 5; i++) {
		int v = 8;  // variável i e variável v só existem no for
		cout << v << endl;
	}

	cout << " a = " << a << endl;
	cout << " Mensagem teste " << endl;  // seria a mesma coisa do que com std::cout e std::endl se não houvesse o comando "using namespace std;"
}

// cout = saída de dados
// << = redireciona para
// endl = pula uma linha
