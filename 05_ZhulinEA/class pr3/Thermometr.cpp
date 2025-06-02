#include <iostream>
#include "Thermometr.h" 
#include <vector>
#include <cmath> 

using namespace std; 

inv::inv() : year(0), month(0), day(0), hours(0), value(-100) {} 


inv::inv(int y, int m, int d, int h, double v) {
	year = y;
	month = m; 
	day = d; 
	hours = h;
	value = v; 
}
inv::inv(const inv& b) {
	year = b.year; 
	month = b.month; 
	day = b.day; 
	hours = b.hours; 
	value = b.value; 
}


bool inv::operator<(const inv& b) {
	if (year < b.year) {
		return true;
	}
	else if (year > b.year) {
		return false; 
	}
	else {
		if (month < b.month) {
			return true; 
		}
		else if (month > b.month) {
			return false; 
		}
		else {
			if (day < b.day) {
				return true; 
			}
			else if (day > b.day) {
				return false;
			}
			else {
				if (hours < b.hours) {
					return true; 
				}
				else {
					return false; 
				}
			}
		}
	}
}
bool inv::operator==(const inv& b) {
	if (year == b.year) {
		return true;
	}
	else {
		if (month == b.month) {
			return true;
		}
		else {
			if (day == b.day) {
				return true;
			}
			else {
				if (hours == b.hours) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}


istream& operator>>(istream& is, inv& b) {
	cout << "Cin Year: "; 
	is >> b.year; 
	cout << "Cin Month: "; 
	is >> b.month; 
	cout << "Cin Day: ";
	is >> b.day; 
	cout << "Cin Hours: ";
	is >> b.hours; 
	cout << "Cin Value: ";
	is >> b.value;
	return is; 
}

ostream& operator<<(ostream& os, inv& b) {
	os << "Year: " << b.year << " Month: " << b.month << " Day: " << b.day << " Hours: " << b.hours << " Value: " << b.value;
	return os; 
}







Thermometr::Thermometr(): a() {}; 

Thermometr::Thermometr(const vector <inv>& c) {
	for (int i = 0; i < c.size(); i++) {
		a.push_back(c[i]);
	}
};

void Thermometr::append_inv(inv b) {
	a.push_back(b);
	kolvo++;
	if (b < a[kolvo - 1] or b == a[kolvo - 1]) {
		min_date = b;
	}
};
void Thermometr::cout_min_date() {
	cout << min_date; 
}
void Thermometr::cout_value_in_date(int year, int month, int day, int hours) {
	for (int i = 0; i < kolvo; i++) {
		if (a[i].year == year and a[i].month == month and a[i].day == day and a[i].hours == hours) {
			cout << "Value: " << a[i].value; 
		}
		else {
			cout << "This date isn't in Thermometr!!!"; 
		}
	}
};

double Thermometr::average_value_in_day(int year, int month, int day) {
	double res = 0;
	int k = 0; 
	for (int i = 0; i < kolvo; i++) {
		if (a[i].year == year and a[i].month == month and a[i].day == day){ 
			k++; 
			res += a[i].value; 
		}
	}
	return (res / k); 
}; 

double Thermometr::average_value() {
	double res = 0;
	if (kolvo == 0) {
		return 0; 
	}
	for (int i = 0; i < kolvo; i++) {
		res += a[i].value; 
	}
	return res / kolvo; 
}

double Thermometr::average_value_in_month(int year, int month) {
	double res = 0;
	int k = 0;
	for (int i = 0; i < kolvo; i++) {
		if (a[i].year == year and a[i].month == month) {
			k++; 
			res += a[i].value; 
		}
	}
	return res / k; 
}

void Thermometr::average_value_in_month_dn(int year, int month) {
	double resd = 0;
	double resn = 0; 
	int kd = 0;
	int kn = 0; 
	for (int i = 0; i < kolvo; i++) {
		if (a[i].year == year and a[i].month == month and (a[i].hours > 5 and a[i].hours < 21)) {
			resd += a[i].value; 
			kd++; 
		}	
		else if (a[i].year == year and a[i].month == month and (a[i].hours >= 21 or a[i].hours <= 5)) {
			resn += a[i].value; 
			kn++; 
		}
	}
	cout << "average in night: " << resd / kd; 
	cout << "average in day: " << resn / kn; 
}