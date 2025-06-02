#pragma once
#include <ostream>
class String
{
private:
	char* Massiv;
	int Razmer;
public:
	String(const char* data);
	String(const String& s);
	String();
	virtual ~String();

	int size() const;
	String& operator=(const String& s);
	String& operator=(const char* s);
	char operator[](int index) const;
	void print() const;
	//char poisk(int index) const;
	void replace(int index, char rep);
	String substr(int pos, int size) const;
	bool palindrom() const;
	int alfavit() const;
	void operator+=(const String&s);
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	String operator+(const String& s);
	friend std::ostream& operator<<(std::ostream& os, const String& s);
};

