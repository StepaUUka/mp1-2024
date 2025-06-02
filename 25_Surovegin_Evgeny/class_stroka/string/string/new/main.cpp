#include<iostream>
#include "String.h"
#include<string>
using namespace std;
int main()
{
	int index, size, pos, n;
	char rep;
	
	//String s("qqq"), s1("12345");
	/*char* massiv;
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
	//cout << s.poisk(index) << endl;
	cout << s[index] << endl;
	cout << "Enter Index for replace" << endl;
	cin >> index;
	cout << "Enter replace" << endl;
	cin >> rep;
	s.replace(index, rep);
	s.print();
	cout << "Enter first Index" << endl;
	cin >> pos;
	cout << "Enter size" << endl;
	cin >> size;
	String s1 = s.substr(pos, size);
	s1.print();

	bool ok = s.palindrom();
	if (ok == true)
	{
		cout << "palindrom" << endl;
	}
	else
	{
		cout << " ne palindrom" << endl;
	}

	cout<<s.alfavit()<<endl;
	String s2("qwert");
	s += s2;
	cout << "s > S2: "  << (s > s2) <<endl;
	cout << "s < S2: " << (s < s2) << endl;
	cout << "s == S2: " << (s == s2) <<endl;
	cout << "s != S2: " << (s != s2) <<endl;
	*/
	String s3;
	String s2("qwert"), s("qqq");
	s3 = s + s2;
	//s3.print(); 
	std::cout << "s3: '" << s3 << "'" << endl;

}