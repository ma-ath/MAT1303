#include "vetor.h"
#include <iostream>
using namespace std;

int main(void)
{
	vetor u(10);

	for (int i = 0; i < 10; i++)
		u.set(i, 2 * i);

	vetor w = u;

	u.soma(w);

	for (int i = 0; i < 10; i++)
		cout << u.get(i) << " , ";

	cout << endl;
}
