#pragma once
#include <cstdlib>
#include <iostream>


using namespace std;

class weight {
private:
	double kg;
public:
	void setW(double k) { kg = abs(k); }
	double getW() { return kg; }
	void printF() {
		cout << "1).pound - ����\n2).ounce - �����\n3).carat - ������\n4).slug - �����\n5)������ ��� ������\n6).allC - ��� �����\n7)�����\n";
	}
	double pound() { return (kg / 16.38); }
	double ounce() { return (kg / 0.0311035); }
	double carat() { return (kg / 0.0002); }
	double slug() { return (kg / 14.5939); }
	void allC() {
		cout << kg / 16.38 << "\n" << kg / 0.0311035 << "\n" << kg / 0.0002 << "\n" << kg / 14.5939 << "\n";
	}

};
