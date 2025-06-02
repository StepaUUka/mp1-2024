#include <cstdlib>
#include <iostream>
#include <cstring>



using namespace std;

class Polinom {
private:
	int degree;
	double* coeff;
public:
	Polinom(int s) {
		if (s > 100 || s < 0) {
			throw invalid_argument("Неподходящая степень");
		}
		coeff = new double[s + 1];
		for (int i = 0; i < s + 1; i++) {
			coeff[i] = 0.0;
		}
		degree = s + 1;

	}
	Polinom(const Polinom& p1) {
		degree = p1.degree;
		coeff = new double[degree];
		memcpy(coeff, p1.coeff, sizeof(double) * degree);
	}
	

	void setCoefficients() {
		for (int i = 0; i < degree; i++) {
			cin >> coeff[i];
		}
	}
	void printDegree() {
		cout << degree-1;
	}
	int getD() {
		return degree;
	}
	void checkCoef(int s) {
		cout << coeff[s];
	}
	double inPoint(double k) {
		double result=0;
		for (int i = 0; i < degree; i++) {
			result += coeff[i] * pow(k, i);
		}
		return result;
	}
	Polinom proizv() const {
		Polinom p2(degree - 2);
		for (int i = 1; i < degree; i++) {
			p2.coeff[i - 1] = coeff[i] * i;
		}
		return p2;
	}
	Polinom operator*(const Polinom& p2) const {
		int resDegree = degree + p2.degree - 2;
		Polinom res(resDegree);
		for (int i = 0; i < degree; i++) {
			for (int j = 0; j < p2.degree; j++) {
				res.coeff[i + j] += coeff[i] * p2.coeff[j];
			}
		}
		return res;
	}
	friend ostream& operator<<(ostream& os, const Polinom& p) {
		for (int i = p.degree - 1; i >= 0; i--) {
			if (p.coeff[i] != 0) {
				if (i != p.degree - 1) {
					os << " + ";
				}
				os << p.coeff[i];
				if (i > 0) {
					os << "x^" << i;
				}
			}
		}
		return os;
	}
	friend istream& operator>>(istream& is, Polinom& p) {
		for (int i = 0; i < p.degree; i++) {
			is >> p.coeff[i];
		}
		return is;
	}



	Polinom operator+(const Polinom& p2) const {
		int dmax = std::max(degree, p2.degree);
		Polinom res(dmax - 1);
		for (int i = 0; i < dmax; i++) {
			res.coeff[i] = (i < degree ? coeff[i] : 0) + (i < p2.degree ? p2.coeff[i] : 0);
		}
		return res;
	}

	Polinom operator-(const Polinom& p2) const {
		int dmax = std::max(degree, p2.degree);
		Polinom res(dmax - 1);
		for (int i = 0; i < dmax; i++) {
			res.coeff[i] = (i < degree ? coeff[i] : 0) - (i < p2.degree ? p2.coeff[i] : 0);
		}
		return res;
	}
	bool operator>(const Polinom& p1) {
		int d1 = degree;
		int d2 = p1.degree;
		int dmin, dmax;
		if (d1 > d2) {
			return true;
		}
		if (d2 > d1) {
			return false;
		}
		if (d1 == d2) {
			for (int i = d1; i > 0; i--) {
				if (coeff[i] > p1.coeff[i]) {
					return true;
				}
				if (coeff[i] < p1.coeff[i]) {
					return false;
				}
				
			}
		}
	}
	bool operator<(const Polinom& p1) {
		int d1 = degree;
		int d2 = p1.degree;
		int dmin, dmax;
		if (d1 < d2) {
			return true;
		}
		if (d2 < d1) {
			return false;
		}
		if (d1 == d2) {
			for (int i = d1; i > 0; i--) {
				if (coeff[i] < p1.coeff[i]) {
					return true;
				}
				if (coeff[i] > p1.coeff[i]) {
					return false;
				}

			}
		}
	}
	bool operator==(const Polinom& p1) {
		int d1 = degree;
		int d2 = p1.degree;
		int dmin, dmax;
		if (d1 != d2) {
			return false;
		}
		if (d1 == d2) {
			for (int i = d1; i > 0; i--) {
				if (coeff[i] != p1.coeff[i]) {
					return false;
				}
				

			}
			return true;
		}
	}
	Polinom&operator+=(const Polinom& p1) {
		int d1 = degree;
		int d2 = p1.degree;
		if (d1 >= d2) {
			for (int i = 0; i < d2; i++) {
				coeff[i] += p1.coeff[i];
			}
		}
		if (d1 < d2) {
			Polinom tmp(d2);
			for (int i = 0; i < d1; i++) {
				tmp.coeff[i] = coeff[i];
			}
			for (int i = d1; i < d2; i++) {
				tmp.coeff[i] = 0;
			}
			delete[]coeff;
			degree = p1.degree;
			coeff = new double[degree];
			for (int i = 0; i < degree;i++){
				coeff[i] = tmp.coeff[i] + p1.coeff[i];
			}
		}
	}
	double& operator[](int index) const {
		return coeff[index];
	}
	Polinom& operator=(const Polinom& p2) {
		if (this == &p2) return *this;
		delete[] coeff;
		degree = p2.degree;
		coeff = new double[degree];
		std::copy(p2.coeff, p2.coeff + degree, coeff);
		return *this;
	}
	Polinom operator/(double scalar) const {
		if (scalar == 0) {
			throw invalid_argument("Деление на ноль");
		}
		Polinom res(degree - 1);
		for (int i = 0; i < degree; i++) {
			res.coeff[i] = coeff[i] / scalar;
		}
		return res;
	}


	~Polinom() { delete[] coeff;};
	
};


int main() {
	setlocale(LC_ALL, "Russian");
	
	Polinom p1(2); 
	Polinom p2(2); 

	
	cout << "Введите коэффициенты для полинома p1 (3 числа): ";
	cin >> p1;
	cout << "Введите коэффициенты для полинома p2 (3 числа): ";
	cin >> p2;

	
	cout << "Полином p1: " << p1 << endl;
	cout << "Полином p2: " << p2 << endl;

	
	Polinom p3 = p1 + p2;
	cout << "Сумма p1 и p2: " << p3 << endl;

	
	Polinom p4 = p1 - p2;
	cout << "Разность p1 и p2: " << p4 << endl;

	
	Polinom p5 = p1 * p2;
	cout << "Произведение p1 и p2: " << p5 << endl;

	
	Polinom p6 = p1 / 0.5;
	cout << "Полином p1 умноженный на 2: " << p6 << endl;

	
	Polinom p7 = p1 / 2.0;
	cout << "Полином p1 деленный на 2: " << p7 << endl;

	
	Polinom p8 = p1.proizv();
	cout << "Производная p1: " << p8 << endl;

	
	double x = 2.0;
	cout << "Значение p1 в точке " << x << ": " << p1.inPoint(x) << endl;

	
	if (p1 == p2) {
		cout << "p1 и p2 равны" << endl;
	}
	else {
		cout << "p1 и p2 не равны" << endl;
	}

	if (p1 > p2) {
		cout << "p1 больше p2" << endl;
	}
	else {
		cout << "p1 не больше p2" << endl;
	}

	cout << "Коэффициент при x^1 в p1: " << p1[1] << endl;

	return 1;
}