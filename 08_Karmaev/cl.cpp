#include <cstdlib>
#include <iostream>
#include "weight.h"


using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	weight t1;
	double z;
	cout << "������� ��� � ��: ";
	cin >> z;

	t1.setW(z);
	t1.printF();
	int type = 0;
	double res;
	while (type != 7) {
		cin >> type;
		switch (type) {
		case 1:
			res = t1.pound();
			cout << "��������� ����������� � ���� = " << res;
			break;
		case 2:
			res = t1.ounce();
			cout << "��������� ����������� � ����� = " << res;
			break;
		case 3:
			res = t1.carat();
			cout << "��������� ����������� � ������ = " << res;
			break;
		case 4:
			res = t1.slug();
			cout << "��������� ����������� � ����� = " << res;
			break;
		case 5:
			cin >> z;
			t1.setW(z);
			break;
		case 6:
			t1.allC();
			break;
		case 7:
			
			break;
		}
	}
	return 1;
}