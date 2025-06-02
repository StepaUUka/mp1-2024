#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>


using namespace std;

class Monitoring {
private:
	int day;
	int month;
	int year;
	int hour;
	double temperature;
public:
	Monitoring() : day(1), month(1), year(2025), hour(0), temperature(0.0) {}

	Monitoring(int day, int month, int year, int hour, double temperature) : day(day), month(month), year(year), hour(hour), temperature(temperature) {}

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	int getHour() const { return hour; }
	double getTemperature() const { return temperature; }
	int setDay(int d) { day = d; }
	int setMonth(int m) { month = m; }
	int setYear(int y) { year = y; }
	int setHour(int h) { hour = h; }
	double setTemperature(double t) { temperature = t; }

	void printMon() const {
		cout << "Дата: " << day << "." << month << "." << year << "  " << hour << ":00  " << temperature << " C" << endl;
	}

};

class Thermometr {
private:
	vector <Monitoring> monitor = { {1,1,2025,0,-15.2} };
	int size = 1;

public:
	void setBaseDateTime(int day, int month, int year, int hour, double t) {
		Monitoring a(day, month, year, hour, t);
		monitor[0] = (a);
	}

	void const getBaseDateTime() const {
		monitor[0].printMon();
	}

	void newMonit(int day, int month, int year, int hour, double temperature) {
		Monitoring skib(day, month, year, hour, temperature);
		/*int flag = 1, c = 0, temp = 0;
		while (flag != 0) {
			if (monitor[c].getYear() < skib.getYear()) {
				while (monitor[c].getYear() < skib.getYear()) {
					c++;
				}
				if (monitor[c].getMonth() < skib.getMonth()) {
					while (monitor[c].getMonth() < skib.getMonth()) {
						c++;
					}
					if (monitor[c].getDay() < skib.getDay()) {
						while (monitor[c].getDay() < skib.getDay()) {
							c++;
						}
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c, skib);
								break;
							}
						}
					}
					if (monitor[c].getDay() > skib.getDay()) {
						monitor.insert(monitor.begin() + c - 1, skib);
						break;
					}
					if (monitor[c].getDay() == skib.getDay()) {
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c, skib);
								break;
							}
						}
						if (monitor[c].getHour() > skib.getHour()) {
							monitor.insert(monitor.begin() + c - 1, skib);
							break;
						}
						if (monitor[c].getHour() == skib.getHour()) {
							cout << "ощибка ничего не палучилась";
						}
					}
				}
				if (monitor[c].getMonth() > skib.getMonth()) {
					monitor.insert(monitor.begin() + c - 1, skib);
					break;
				}
				if (monitor[c].getMonth() == skib.getMonth()) {
					if (monitor[c].getDay() < skib.getDay()) {
						while (monitor[c].getDay() < skib.getDay()) {
							c++;
						}
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c, skib);
								flag = 0;
								break;
							}
						}
					}
					if (monitor[c].getDay() > skib.getDay()) {
						monitor.insert(monitor.begin() + c - 1, skib);

						break;
					}
					if (monitor[c].getDay() == skib.getDay()) {
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c - 1, skib);
								flag = 0;
								break;
							}
						}
					}

				}

			}
			if (monitor[c].getYear() > skib.getYear()) {
				monitor.insert(monitor.begin() + c - 1, skib);
				break;
			}
			if (monitor[c].getYear() == skib.getYear()) {
				if (monitor[c].getMonth() < skib.getMonth()) {
					while (monitor[c].getMonth() < skib.getMonth()) {
						c++;
					}
					if (monitor[c].getDay() < skib.getDay()) {
						while (monitor[c].getDay() < skib.getDay()) {
							c++;
						}
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c, skib);
								break;
							}
						}
					}
					if (monitor[c].getDay() > skib.getDay()) {
						monitor.insert(monitor.begin() + c - 1, skib);
						break;
					}
					if (monitor[c].getDay() == skib.getDay()) {
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c, skib);
								break;
							}
						}
						if (monitor[c].getHour() > skib.getHour()) {
							monitor.insert(monitor.begin() + c - 1, skib);
							break;
						}
						if (monitor[c].getHour() == skib.getHour()) {
							cout << "ощибка ничего не палучилась";
						}
					}
				}
				if (monitor[c].getMonth() > skib.getMonth()) {
					monitor.insert(monitor.begin() + c - 1, skib);
					break;
				}
				if (monitor[c].getMonth() == skib.getMonth()) {
					if (monitor[c].getDay() < skib.getDay()) {
						while (monitor[c].getDay() < skib.getDay()) {
							c++;
						}
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c, skib);
								flag = 0;
								break;
							}
						}
					}
					if (monitor[c].getDay() > skib.getDay()) {
						monitor.insert(monitor.begin() + c - 1, skib);

						break;
					}
					if (monitor[c].getDay() == skib.getDay()) {
						if (monitor[c].getHour() < skib.getHour()) {
							while (monitor[c].getHour() < skib.getHour()) {
								c++;
							}
							if (monitor[c].getHour() > skib.getHour()) {
								monitor.insert(monitor.begin() + c - 1, skib);
								flag = 0;
								break;
							}
						}
					}

				}
			}
		}*/
		monitor.push_back(skib);
	}

	void getTemper(int d, int m, int y, int h)const {
		int k = 0;
		for (int i = 0; i < monitor.size(); i++) {
			if (d == monitor[i].getDay() && m == monitor[i].getMonth() && y == monitor[i].getYear() && h == monitor[i].getHour()) {
				cout << "Температура -   " << monitor[i].getTemperature() << " C" << endl;
				k = 1;
			}
		}
		if (k != 1) {
			cout << "Такого замера не было (((";
		}
	}

	void addMonitoringSeries(int d, int m, int y, int k) {
		int* t;
		t = new int[k];
		for (int i = 0; i < k; i++) {
			t[i] = -1;
		}
		int c = 0;
		while (k != 0) {
			int h;

			cout << "Введите время" << endl;
			cin >> h;
			while (h < 0 || h > 24) {

				cout << "Ошибка введите заново" << endl;
				cin >> h;

			}
			for (int i = 0; i < k; i++) {
				if (t[i] == h) {
					cout << "Ошибка введите заново" << endl;
					cin >> h;

					i = 0;
				}
			}
			t[c] = h;
			double temper;
			cout << "Введите температуру ";
			cin >> temper;
			newMonit(d, m, y, h, temper);
			k--;

		}
	}

	void findAvgTempForDay(int d, int m, int y) {
		int counter = 0;
		double c_temp = 0.0;
		for (int i = 0; i < monitor.size(); i++) {
			if (monitor[i].getDay() == d && monitor[i].getMonth() == m && monitor[i].getYear() == y) {
				c_temp += monitor[i].getTemperature();
				counter += 1;
			}
		}
		cout << "Средняя температура за " << d << "." << m << "." << y << "  " << (c_temp / counter);
	}

	void findAvgTempForMonth(int m, int y) {
		int counter = 0;
		double c_temp = 0.0;
		for (int i = 0; i < monitor.size(); i++) {
			if (monitor[i].getMonth() == m && monitor[i].getYear() == y) {
				c_temp += monitor[i].getTemperature();
				counter += 1;
			}
		}
		cout << "Средняя температура за месяц = " << (c_temp / counter);
	}

	void findAvgTempForYear(int m, int y) {
		int counter = 0;
		double c_temp = 0.0;
		for (int i = 0; i < monitor.size(); i++) {
			if (monitor[i].getYear() == y) {
				c_temp += monitor[i].getTemperature();
				counter += 1;
			}
		}
		cout << "Средняя температура за год = " << (c_temp / counter);
	}

	void avgdaytempformonth(int m, int y) {
		int counter = 0;
		double c_temp = 0.0;
		for (int i = 0; i < monitor.size(); i++) {
			if (monitor[i].getYear() == y && monitor[i].getMonth() == m && (12 <= monitor[i].getHour() <= 18)) {
				c_temp += monitor[i].getTemperature();
				counter += 1;
			}
		}
		cout << "Средняя дневная температура за месяц = " << (c_temp / counter);
	}

	void avgnighttempformonth(int m, int y) {
		int counter = 0;
		double c_temp = 0.0;
		for (int i = 0; i < monitor.size(); i++) {
			if (monitor[i].getYear() == y && monitor[i].getMonth() == m && ((22 <= monitor[i].getHour() <= 23)) || ((0 <= monitor[i].getHour() <= 5))) {
				c_temp += monitor[i].getTemperature();
				counter += 1;
			}
		}
		cout << "Средняя ночная температура за месяц = " << (c_temp / counter);
	}

};