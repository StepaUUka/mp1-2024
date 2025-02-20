#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "weighter.h"


using namespace std;



//1.5 ��������� �����




void start_menu() {
	cout << "1. ���������� � ������������ �����\n";
	cout << "2. ���������� � ������������ �����\n";
	cout << "3. ���������� � �������� ������\n";
}

void end_menu() {
	cout << "1. ��������� ����������� � ������ ������� ���������.\n";
	cout << "2. �������� �����.\n";
	cout << "3. ��������� ������ ���������.\n";
}


int main() 
{
	int status = 0, c = 0;
	double we = 0.0;
	setlocale(LC_ALL, "Russian");

	Weighter weightmain;

	while (c <= 10) {
		if (status == 0) {
			cout << "������� ����������� ��� � �����������: ";
			cin >> weightmain.weight;
			if (weightmain.weight > 0.0) {
				cout << "\n�������! �������������� �����: " << weightmain.weight << " ��\n\n";
				status = 1;
			}
			else {
				while (weightmain.weight <= 0.0) {
					cout << "�������� ������������ �����! ����������, ��������� ����!";
					cin >> weightmain.weight;
				}
			}

		}

		if (status == 1) {
			start_menu();
			cout << "\n\n�������� ����������� � ��������� ������� �����: \n";
			cin >> c;

			switch (c) {
			case 1: {
				weightmain.pound();
				status = 2;
				break;
			}

			case 2: {
				weightmain.ounce();
				status = 2;
				break;
			}

			case 3: {
				weightmain.drachma();
				status = 2;
				break;
			}
			}
		}

		if (status == 2) {
			cout << "\n\n����������� ���������! �������� ���������� ��������: \n\n";
			end_menu();
			cin >> c;

			switch (c) {
			case 1: {
				status = 1;
				break;
			}
			case 2: {
				status = 0;
				break;
			}
			case 3: {
				cout << "Thanks for using! GD!\n";
				c = 11;
				break;
			}
			}
		}
	}


	return 0;
}