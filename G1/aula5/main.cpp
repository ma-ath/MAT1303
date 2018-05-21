#include <iostream>
#include "circulo.hpp"
using namespace std;

int main(void)
{
	circulo a;  // ou circulo a();
	circulo b(2, 1.3, 3.4);
	float area = a.area();
	float raio = a.raio();

	cout << area << endl;
	cout << raio << endl;

	area = b.area();
	raio = b.raio();

	cout << area << endl;
	cout << raio << endl;
}
