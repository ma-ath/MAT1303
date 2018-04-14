#include "racional.hpp"

int main(void)
{
	racional a(2, 4);
	racional b(1, 3);
	racional c(a);  // ou racional c = a (caso exista o construtor)
	racional f = a.soma(b);

	c.print();
	f.print();
}
