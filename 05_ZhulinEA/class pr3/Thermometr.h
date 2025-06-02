#pragma once
#include <vector>
#include <iostream>

using namespace std; 

class inv {
public:
	int year;
	int month;
	int day;
	int hours;
	double value;
	inv();
	inv(int year, int month, int day, int hours, double value);
	inv(const inv& b);
	bool operator<(const inv& b);
	friend ostream& operator<<(ostream& os, inv& b);
	friend istream& operator>>(istream& is, inv& b);
	bool operator==(const inv& b);
	friend class Thermometr;
}; 


class Thermometr {
private:
	vector <inv> a;
	inv min_date; 
	int kolvo;
public:
	Thermometr();
	Thermometr(const vector <inv>& c);
	void append_inv(inv b);
	void cout_min_date(); 
	void cout_value_in_date(int year, int month, int day, int hours); 
	double average_value_in_day(int year, int month, int day);  
	double average_value_in_month(int year, int month);  
	double average_value(); 
	void average_value_in_month_dn(int year, int month); 
	friend ostream& operator<<(ostream& os, Thermometr& b); 
};