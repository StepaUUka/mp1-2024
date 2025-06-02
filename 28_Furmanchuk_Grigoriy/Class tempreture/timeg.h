#pragma once
#include "limits.h"
#include <iostream>

using namespace std;

class date {
private:
	int month;
	int day;
	int time;
	double t;
public:
	const int getmonth() { return month; }
	const double& gett() const { return t; }///////
	double& gett() { return t;}
	date(int m, int d, int t_) {month = m; day = d; time = t_; t = 10*19; }
	bool operator==(date& dd);
	bool equelto(date& dd) const;
	friend ostream& operator<<(ostream& on, date& dd) {
			on << dd.month << "." << dd.day << " " << dd.time << ":00" << " " << dd.t << " deg C";
			return on;
	}
	date operator=(double tp) {
		t = tp;
		return *this;
	}
};

