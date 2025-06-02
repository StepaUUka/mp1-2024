#pragma once
#include "timeg.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class temp {
private:
	int year;
	vector<date>arr;
public:
	temp(int y) {
		year = y;
	}
	void setdate(int m, int d, int t);
	void settmp(double t);
	void setmul(int n);
	int avrmonth(int n);
	const double& operator()(int m, int d, int t) const;
	double& operator()(int m, int d, int t);
	friend ostream& operator<<(ostream& out, temp& tmp);
};
