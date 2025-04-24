#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
int state = 0;


// M_PI

typedef double (*Start)(double x);
typedef double (*Step)(double x, int n);


double NoClamp(double x) {
	return x;
}


double ClampPI(double x) {
	double v = x / (2 * M_PI);
	return (x - floor(v) * 2. * M_PI);
}


double ChosinStart(double x) {
	return 1;
}


double ChosinStep(double x, int n) {
	return x * x / (2 * (double)n) / (double)(2 * (double)n - 1);
}


double ShinusStart(double x) {
	return x;
}


double ShinusStep(double x, int n) {
	return x * x / (2 * (double)n) / (double)(2 * (double)n + 1);
}


double expStart(double x) {
	return 1;
}


double expStep(double x, int n) {
	return x / n;
}


double sinStart(double x) {
	return x;
}


double sinStep(double x, int n) {
	return -x * x / (2 * (double)n * (2 * (double)n + 1));
}


double cosStart(double x) {
	return 1;
}


double cosStep(double x, int n) {
	return -x * x / (2 * (double)n * (2 * (double)n - 1));
}


// ������� �� �������� accur (��� �� n-���)
double TeylorAccuracy(int n, double accur, double trueVal, Start Clamp, Start first, Step next, double x) {
	int i = 1;
	double res;
	double step;

	x = Clamp(x);
	//printf("%lf\n", x);

	res = first(x);
	step = res * next(x, i);
	res += step;

	while ((i++ < n) && (accur < fabs(res - trueVal))) {
		step = step * next(x, i);
		res += step;
	}
	printf("����� ���������� - %d\n", i - 1);
	return res;
}

/*
// state = 0
void Interface() {
	int ans = 0;
	printf("�������� �����:\n");
	printf("1) ��������� �����.\n");
	//printf("2) �������� ����� �����.\n\n");
	printf("2) �����.");

	scanf_s("%d", &ans);

	switch (ans) {
	case(1): state = 1; break;
	case(2): state = 255; break;
	case(3): state = 255; break;
	}
}
*/

// ��������� n 
int AskNum(char* string) {
	int ans;
	printf(string);
	scanf_s("%d", &ans);
	return ans;
}


double AskDouble(char* string) {
	double ans;
	printf(string);
	scanf_s("%lf", &ans);
	return ans;
}


// state = 1
void NormalMode() {
	double found;
	double find;
	int ans = -1;
	double accurf;
	
	printf("�������� �������:\n");
	printf("1) �������\n");
	printf("2) �����\n");
	printf("3) ����������\n");
	printf("4) ����� (\"��������������� �����\")\n");
	printf("5) ������� (\"��������������� �������\")\n\n");
	printf("6) �����\n");
	while ((ans < 1) || (ans > 6)) {
		scanf_s("%d", &ans);
	}

	if (ans == 6) {
		state = 255;
		return NULL;
	}
	
	accurf = 1 / pow(10, (double)AskNum("������� �������� ( 10 ^ (-n) )"));
	printf("%lf\n", accurf);
	int n = AskNum("������� ����� ����������? (0 < n < 121)");
	if (n < 1) {
		n = 0;
	}
	else if (n > 120) {
		n = 120;
	}

	find = AskDouble("����� �������� ������ �����?\n");

	switch (ans) {
	case(1): found = TeylorAccuracy(n, accurf, cos(find), ClampPI, cosStart, cosStep, find);
		printf("���������� ���� - %lf\n�� ������� - %lf\n������� (����������) - %e", cos(find), found, fabs(cos(find) - found));
		break;
	case(2): found = TeylorAccuracy(n, accurf, sin(find), ClampPI, sinStart, sinStep, find);
		printf("���������� ���� - %lf\n�� ������� - %lf\n������� (����������) - %e", sin(find), found, fabs(sin(find) - found));
		break;
	case(3): found = TeylorAccuracy(n, accurf, exp(find), NoClamp, expStart, expStep, find);
		printf("���������� ���� - %lf\n�� ������� - %lf\n������� (����������) - %e", exp(find), found, fabs(exp(find) - found));
		break;
	case(4): found = TeylorAccuracy(n, accurf, sinh(find), NoClamp, ShinusStart, ShinusStep, find);
		printf("���������� ���� - %lf\n�� ������� - %lf\n������� (����������) - %e", sinh(find), found, fabs(sinh(find) - found));
		break;
	case(5): found = TeylorAccuracy(n, accurf, cosh(find), NoClamp, ChosinStart, ChosinStep, find);
		printf("���������� ���� - %lf\n�� ������� - %lf\n������� (����������) - %e", cosh(find), found, fabs(cosh(find) - found));
		break;
	}
	state = 0;
}

/*
// state = 2
void SerialMode() {
	AskNum("�������� �����.");
}
*/

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	while (state != 255) {
		printf("\n=================================\n");
		if (state > 1) {
			state = 0;
		}
		switch (state) {
		case(0): NormalMode(); break;
		//case(2): SerialMode(); break;
		}
	}
	printf("����");
	return 1;
}