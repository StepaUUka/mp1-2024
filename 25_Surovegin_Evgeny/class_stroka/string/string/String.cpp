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
void String::print()
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
void String::poisk(int index)
{
	if (index < 0 || index > Razmer - 1)
	{
		cout << "Mistake Index" << endl;
	}
	else
	{
		cout << Massiv[index]<<endl;

	}
}
void String::replace(int index, char rep)
{
	if (index < 0 || index > Razmer - 1)
	{
		cout << "Mistake Index" << endl;
	}
	else
	{
		Massiv[index] = rep;
		print();
	}
}
void String::substr(int pos, int size)
{
	if (pos < 0 || pos > Razmer - 1)
	{
		cout << "Mistake Pos" << endl;
		return;
	}
	if(pos + size > Razmer )
	{
		cout << "Mistake size" << endl;
		return;
	}

	char* sub = new char[size+1];
	for (int i = pos; i < pos+size; i++)
	{
		sub[i-pos] = Massiv[i];
	}
	sub[size] = '\0';
	String res(sub);
	res.print();
	delete[] sub;
}
bool String::palindrom()
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
void String::alfavit()
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
	cout << k;
}
