#include "vetor.hpp"

int main(void)
{
	vetor x(10);

	for (int i = 0; i < 10; i++)
		x.set(i, i + 2);

	vetor y(x);

	vetor w = x + y;

	vetor q(30);

	q = x + y;

	q.print();
	w.print();
}
