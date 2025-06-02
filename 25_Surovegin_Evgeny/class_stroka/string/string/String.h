#pragma once
class String
{
private:
	char* Massiv;
	int Razmer;
public:
	String(const char* data);
	String();
	~String();

	int size() const;
	String& operator=(const String& s);
	String& operator=(const char* s);
	void print();
	void poisk(int index);
	void replace(int index, char rep);
	void substr(int pos, int size);
	bool palindrom();
	void alfavit();
};

