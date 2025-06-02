#include <iostream>
#include "Polynom.h"

using namespace std; 

int main() {
	Polynom a, b, c, c1, c2, c3;
	cin >> a >> b; 
	c1 = 2.5 - a;
	cout << c1;

	c2 = c1 + 2.0; 
	c3 = a - b; 
	c = c1 + c2 + c3;
	cout << c3;
}