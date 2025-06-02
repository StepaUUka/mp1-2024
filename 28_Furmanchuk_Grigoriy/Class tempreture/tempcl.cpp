#include "tempcl.h"
#include "timeg.h"
#include <iostream>
#include "limits.h"
using namespace std;

//year;
//int month;
//int day;
//int time;
bool date::operator==(date& dd) {
	if (month == dd.month && day == dd.day)
		return true;
	return false;
}

///
bool date::equelto(date& dd) const{
	if (month == dd.month && day == dd.day && time == dd.time)
		return true;
	return false;
}



void temp::setdate(int m, int d, int t) {
	date dd(m, d, t);
	int f = 0;
	if (arr.size() == 0) {
		arr.push_back(dd);
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].equelto(dd)) {
			f = 1;
			break;
		}
	}
	if (f != 1 && arr[arr.size()-1].gett() != 10*19)
		arr.push_back(dd);
}

void temp::setmul(int n) {
	while (n > 0) {
		int m, d, t;
		cin >> m >> d >> t;
		date dd(m, d, t);
		int f = 0;
		if (arr.size() == 0) {
			arr.push_back(dd);
			return;
		}
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i].equelto(dd)) {
				f = 1;
				break;
			}
		}
		if (f != 1 && arr[arr.size() - 1].gett() != 10 * 19) {
			arr.push_back(dd);
			cin >> arr[arr.size()-1].gett();
		}
		else
			cout << "Observation on " << year << "." << m << "." << t << " already taken";
		n--;
	}
}

void temp::settmp(double t) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].gett() == 10*19) {
			arr[i] = t;
			return;
		}
	}
}

int temp::avrmonth(int n) {
	int res = 0, k = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].getmonth() == n) {
			res += arr[i].gett();
			k++;
		}
	}
	res = res / k;
	return res;
}


const double& temp::operator()(int m, int d, int t) const{
	date dd(m, d, t);
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].equelto(dd)) {
			return arr[i].gett();
		}
	}
}
double& temp::operator()(int m, int d, int t) {
	date dd(m, d, t);
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].equelto(dd)) {
			return arr[i].gett();
		}
	}
}





ostream& operator<<(ostream& out, temp& tmp) {
	for (int i = 0; i < tmp.arr.size(); i++) {
		out << tmp.year << "." << tmp.arr[i] << "\n";
	}
	return out;
}


void main(){
	temp ex(2025);
	ex.setdate(10, 8, 18);
	ex.settmp(15);

	ex.setdate(10, 10, 18);
	ex.settmp(19);


	cout << ex << "\n";
	/*cout << ex(10, 8, 18) << "\n";
	ex(10, 8, 18) = 9;
	cout << ex;*/

	//ex.setmul(2);
	// 
	//cout << ex;

	cout << ex.avrmonth(10);
}