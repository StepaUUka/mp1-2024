#include<iostream>
#include "String.h"
#include<string>
using namespace std;
int main()
{
	int index, size, pos, n;
	char rep;
	//String s("qqq"), s1("12345");
	char* massiv;
	cout << "Enter dlinu" << endl;
	cin >> n;
	massiv = new char[n+1];
	while (n < 0)
	{
		cin >> n;

	}
	for (int i = 0; i < n; i++)
	{
		cin >> massiv[i];
	}
	massiv[n] = '\0';
	String s(massiv);
	delete[] massiv;

	s.print();
	//s = "1QQQQ";
	s.print();
//	s = s1;
//	s.print();
	cout << "Enter Index poisk" << endl;
	cin >> index;
	s.poisk(index);
	cout << "Enter Index for replace" << endl;
	cin >> index;
	cout << "Enter replace" << endl;
	cin >> rep;
	s.replace(index, rep);
	cout << "Enter first Index" << endl;
	cin >> pos;
	cout << "Enter size" << endl;
	cin >> size;
	s.substr(pos, size);

	bool ok = s.palindrom();
	if (ok == true)
	{
		cout << "palindrom" << endl;
	}
	else
	{
		cout << " ne palindrom" << endl;
	}

	s.alfavit();
}