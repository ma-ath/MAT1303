#include <iostream>
#include "ponto2d.h"
using namespace std;

int main(void)
{
	ponto2d<int> p(2, 3);
	ponto2d<float> q(3.4, 4.8);

	cout << p.getx() << ',' << q.getx();
}
