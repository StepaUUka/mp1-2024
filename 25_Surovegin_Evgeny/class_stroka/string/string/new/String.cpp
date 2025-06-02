#include "String.h"
#include <cstring>
#include<iostream>
#include<cmath>
using namespace std;

String::String(const char* data)
{
	Razmer = strlen(data);
	Massiv = new char [Razmer];
	for (int i = 0; i < Razmer; i++)
	{
		Massiv[i] = data[i];
	}
}
String::String()
{
	Razmer = 0;
	Massiv = nullptr;
}
String::String(const String& s)
{
	Massiv = new char[s.Razmer];
	Razmer = s.Razmer;
	for (int i = 0; i < s.Razmer; i++)
	{
		Massiv[i] = s.Massiv[i];
	}
}
String::~String()
{
	if (Massiv != nullptr)
	{
		delete [] Massiv;
	}
}

String& String::operator=(const String& s)
{
	if (Massiv != nullptr)
	{
		delete[] Massiv;
	}
	Massiv = new char[s.Razmer];
	Razmer = s.Razmer;
	for (int i = 0; i < s.Razmer; i++)
	{
		Massiv[i] = s.Massiv[i];
	}
	return *this;
}
void String::print() const
{
	for (int i = 0; i < Razmer; i++)
	{
		cout << Massiv[i];
	}
	cout << endl;
}
int  String::size() const// не подразумевает изменения внутри класса
{
	return Razmer;
}
String& String::operator=(const char* s)
{
	if (Massiv != nullptr)
	{
		delete[] Massiv;
	}
	Razmer = strlen(s);
	Massiv = new char[Razmer];
	for (int i = 0; i < Razmer; i++)
	{
		Massiv[i] = s[i];
	}
	return *this;
}
/*char String::poisk(int index) const
{
	if (index < 0 || index > Razmer - 1)
	{
		return 0;
	}
	return Massiv[index];
}
*/
char String::operator[](int index) const
{
	if (index < 0 || index > Razmer - 1)
	{
		return 0;
	}
	return Massiv[index];
}
void String::replace(int index, char rep)
{
	if (index < 0 || index > Razmer - 1)
	{
		cout << "Mistake Index" << endl;
	}
	Massiv[index] = rep;
}
String String::substr(int pos, int size) const
{
	String res;

	if (pos < 0 || pos > Razmer - 1)
	{
		cout << "Mistake Pos" << endl;
		return res;
	}
	if(pos + size > Razmer )
	{
		cout << "Mistake size" << endl;
		return res;
	}

	res.Massiv = new char[size];
	for (int i = pos; i < pos+size; i++)
	{
		res.Massiv[i-pos] = Massiv[i];
	}
	res.Razmer = size;
	return res;
}
bool String::palindrom() const
{
	if (Razmer % 2 == 0)
	{
		for (int i = 0; i < Razmer / 2; i++)
		{
			if (Massiv[i] != Massiv[Razmer - 1 - i])
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < floor(Razmer / 2); i++)
		{
			if (Massiv[i] != Massiv[Razmer - 1 - i])
			{
				return false;
			}
		}
	}

	return true;
}
int String::alfavit() const
{	
	int k = 0;
	int ok = 0;
	int m = 0;
	char* tmp;
	tmp = new char[Razmer];
	for (int i = 0; i < Razmer; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Massiv[i] != tmp[j])
			{
				ok++;
			}
		}
		if (ok == m)
		{
			tmp[m] = Massiv[i];
			k++;
			m++;
		}
		ok = 0;
	}
	return k;
}
void String::operator+=(const String& s)
{
	char* tmp = Massiv;
	Massiv = new char[Razmer + s.Razmer];
	for (int i = 0; i < Razmer; i++)
	{
		Massiv[i] = tmp[i];
	}
	for (int i = Razmer; i < Razmer + s.Razmer; i++)
	{
		Massiv[i] = s.Massiv[i - Razmer];
	}
	Razmer = Razmer + s.Razmer;
	delete[] tmp;
}
bool String::operator>(const String& s)
{
	if (Razmer > s.Razmer)
	{
		return true;
	}
	if (Razmer == s.Razmer)
	{
		for (int i = 0; i < Razmer; i++)
		{
			if (Massiv[i] > s.Massiv[i])
			{
				return true;
			}
		}
	}
	return false;
}
bool String::operator<(const String& s)
{
	if (Razmer < s.Razmer)
	{
		return true;
	}
	if (Razmer == s.Razmer)
	{
		for (int i = 0; i < Razmer; i++)
		{
			if (Massiv[i] < s.Massiv[i])
			{
				return true;
			}
		}
	}
	return false;
}
bool String::operator==(const String& s)
{
	if (Razmer == s.Razmer)
	{
		for (int i = 0; i < Razmer; i++)
		{
			if (Massiv[i] != s.Massiv[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool String::operator!=(const String& s)
{
	if (Razmer == s.Razmer)
	{
		for (int i = 0; i < Razmer; i++)
		{
			if (Massiv[i] != s.Massiv[i])
			{
				return true;
			}
		}
		return true;
	}
	return true;
}
String String::operator+(const String& s)
{
	String res;
	res.Massiv = new char[Razmer + s.Razmer];
	for (int i = 0; i < Razmer; i++)
	{
		res.Massiv[i] = Massiv[i];
	}
	for (int i = Razmer; i < Razmer + s.Razmer; i++)
	{
		res.Massiv[i] = s.Massiv[i - Razmer];
	}
	res.Razmer = Razmer + s.Razmer;
	return res;
}
/*std::ostream& operator<<(std::ostream& os, const String& s)
{
	for(int i = 0;i<s.Razmer;i++)
}
*/

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.Razmer; i++)
	{
		os << s.Massiv[i];
	}
	return os;
}
