#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "memory.h"
#include "math.h"
#pragma warning (disable:4996)



typedef double (*FirstEl)(double);
typedef double (*NextEl)(double, int);



double rad_to_circle(double x) {
	
	double a = x;
	while (a >= (2*acos(-1.0))) {
		a = a - (2*acos(-1.0));
	}
	return a;
}



double sin_funcf(double x) {
	return x;
}

double sin_funcn(double x, int n) {
	return (-1) * (x * x) / ((2 * n) * (2 * n + 1));
}

double cos_funcf(double x) {
	return 1;
}

double cos_funcn(double x, int n) {
	return (-1) * (x * x) / ((2 * n - 1) * (2 * n));
}

double exp_funcf(double x) {
	return 1;
}

double exp_funcn(double x, int n) {
	return (x / n);
}

double ln_funcf(double x) {
	return x;
}

double ln_funcn(double x, int n) {
	return (-1) * ((x) / ((double)(n+1)/n));
}






void taylor_firstmode(int n, double x, double accuracy, double ideal, FirstEl st, NextEl nx) {

	double prev = 0.0, next = 0.0, summ = 0.0;
	int count = 1;

	prev = st(x);
	printf("%lf %lf\n", prev, next);

	for (int i = 1; i < n; i++) {
		if (i == 1) {
			summ += prev;
		}
		else {
			next = prev * nx(x, i - 1);
			printf("Next element: %.20lf  ", next);
			summ += next;
			prev = next;
			printf(" %.20lf\n", summ);
		}
	
		if ((count < n) && (fabs(summ - ideal) < accuracy)) {
			break;
		}
		count++;
	}



	if (count < n) {
		printf("Эталонное значение функции:  %lf %lf \n", ideal);
		printf("Полученное значение функции:  %lf \n", summ);
		printf("Разница между итоговым и эталонным значением:  %lf \n", fabs(summ - ideal));
		printf("Итоговое количество слагаемых при подсчете:  %d", count);
	}
	else {
		printf("К сожалению, лимита слагаемых при подсчете не хватило для заданной точности вычислений, но вот, что получилось: \n\n");
		printf("Эталонное значение функции:  %lf %lf \n", ideal);
		printf("Полученное значение функции:  %lf \n", summ);
		printf("Разница между итоговым и эталонным значением:  %lf \n", fabs(summ - ideal));
		printf("Итоговое количество слагаемых при подсчете:  %d \n", count);
	}
}




void taylor_secondmode(int NMax, double x, double ideal, FirstEl st, NextEl nx) {

	double prev = 0.0, next = 0.0, summ = 0.0;
	int count = 0, m = 3;
	int n = NMax;

	prev = st(x);
	next = nx(x, n);

	//Двумерный массив - таблица.
	double** A = (double**)malloc(sizeof(double*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (double*)malloc(sizeof(double) * m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = 0;
		}
	}


	for (int i = 1; i < n; i++) {
		if (i == 1) {
			summ += prev;
			A[i][0] = count+1;
			A[i][1] = summ;
			A[i][2] = fabs(summ - ideal);
		}
		else {
			next = prev * nx(x, i-1);
			summ += next;
			prev = next;
			A[i][0] = count+1;
			A[i][1] = summ;
			A[i][2] = fabs(summ - ideal);
		}
		if (count >= NMax) {
			break;
		}
		count++;
	}

	printf("Таблица с результатом вычислений, где:\n(1)Кол-во слагаемых (2)Посчитанная сумма (3)Дельта подсчитанное/эталонное\n");
	for (int i = 0; i < n; i++) {
		printf("%.0lf ", A[i][0]);
		printf("%.20lf ", A[i][1]);
		printf("%.20lf ", A[i][2]);
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);
}






void start_menu() {
	printf("1. Однократный расчет функции в заданной точке.\n");
	printf("2. Серия экспериментов по расчету функции.\n");
}

void function_menu() {
	printf("3. sin(x)\n");
	printf("4. cos(x)\n");
	printf("5. exp(x)\n");
	printf("6. ln(1+x)\n");
}

void end_menu() {
	printf("1. Повторить выбранный режим работы с другой функцией.\n");
	printf("2. Выбрать иной режим работы.\n");
	printf("3. Завершить работу программы.\n");
}







int main() 
{
	int b = 0, c = 0, n = 0, NMax = 0, status = 0, mode = 0;
	double x = 0, accur = 0, tmp = 0.0, Ideal = 0.0, xr = 0.0;
	setlocale(LC_ALL, "Russian");


	while (c <= 10) {
		if (status == 0) {
			printf("Выберите режим работы программы: \n\n");
			start_menu();
			scanf("%d", &c);

			switch (c) {
			case 1: {
				printf("\n");
				printf("Отлично! Выбран однократный расчет функции!\n");
				status = 1;
				mode = 1;
				break;
			}
			case 2: {
				printf("\n");
				printf("Отлично! Выбрана серия экспериментов!\n");
				status = 1;
				mode = 2;
				break;
			}
			}
		}
		


		if ((status == 1) && (mode == 1)) {
			printf("Выберите вычисляемую функцию: \n");
			function_menu();
			scanf("%d", &c);

			printf("Задайте интересующую вас точку x для вычисления значения: \n");
			scanf("%lf", &x);
			printf("%lf\n", x);

			printf("Задайте максимальную точность вычисления, начиная от 10^(-7) \n0.0000001\n");
			scanf("%lf", &tmp);
			accur = pow(10, -7) * tmp;
			printf("%.9lf\n", accur);

			printf("Обозначьте число слагаемых для подсчета(от 1 до 1000): ");
			int check = 0;
			while (check == 0) {
				scanf("%d", &n);
				if (1 <= n <= 1000) {
					check = 1;
				}
				else {
					check = 0;
					printf("Число слагаемых превышает/недостает до диапазона! Введите количество еще раз! \n");
				}
			}

			switch (c) {
			case 3: {
				printf("Выбранная функция: sin(x) \n\n");
				FirstEl FirstS = &sin_funcf;
				NextEl NextS = &sin_funcn;
				xr = rad_to_circle(x);
				Ideal = sin(xr);
				taylor_firstmode(n, xr, accur, Ideal, FirstS, NextS);
				status = 2;
				break;
			}

			case 4: {
				printf("Выбранная функция: cos(x) \n\n");
				FirstEl FirstC = &cos_funcf;
				NextEl NextC = &cos_funcn;
				xr = rad_to_circle(x);
				Ideal = cos(xr);
				taylor_firstmode(n, xr, accur, Ideal, FirstC, NextC);
				status = 2;
				break;
			}

			case 5: {
				printf("Выбранная функция: exp(x) \n\n");
				FirstEl FirstE = &exp_funcf;
				NextEl NextE = &exp_funcn;
				Ideal = exp(x);
				taylor_firstmode(n, x, accur, Ideal, FirstE, NextE);
				status = 2;
				break;
			}

			case 6: {
				printf("Выбранная функция: ln(1+x) \n\n");
				FirstEl FirstL = &ln_funcf;
				NextEl NextL = &ln_funcn;
				Ideal = log(1+x);
				taylor_firstmode(n, x, accur, Ideal, FirstL, NextL);
				status = 2;
				break;
			}
			default: {
				function_menu;
			}
			}
		}



		if ((status == 1) && (mode == 2)) {
			printf("Выберите вычисляемую функцию: \n");
			function_menu();
			scanf("%d", &c);

			printf("Задайте интересующую вас точку x для вычисления значения: \n");
			scanf("%lf", &x);

			printf("Обозначьте число проводимых экспериментов(от 1 до 25): ");
			int check = 0;
			while (check == 0) {
				scanf("%d", &NMax);
				if (1 <= NMax <= 25) {
					check = 1;
				}
				else {
					check = 0;
					printf("Число экспериментов превышает/недостает до диапазона! Введите правильное количество еще раз! \n");
				}
			}

			switch (c) {
			case 3: {
				printf("Выбранная функция: sin(x) \n\n");
				FirstEl FirstS2 = &sin_funcf;
				NextEl NextS2 = &sin_funcn;
				xr = rad_to_circle(x);
				Ideal = sin(xr);
				taylor_secondmode(NMax, xr, Ideal, FirstS2, NextS2);
				status = 2;
				break;
			}

			case 4: {
				printf("Выбранная функция: cos(x) \n\n");
				FirstEl FirstC2 = &cos_funcf;
				NextEl NextC2 = &cos_funcn;
				xr = rad_to_circle(x);
				Ideal = cos(xr);
				taylor_secondmode(NMax, xr, Ideal, FirstC2, NextC2);
				status = 2;
				break;
			}

			case 5: {
				printf("Выбранная функция: exp(x) \n\n");
				FirstEl FirstE2 = &exp_funcf;
				NextEl NextE2 = &exp_funcn;
				Ideal = exp(x);
				taylor_secondmode(NMax, x, Ideal, FirstE2, NextE2);
				status = 2;
				break;
			}

			case 6: {
				printf("Выбранная функция: ln(1+x) \n\n");
				FirstEl FirstL2 = &ln_funcf;
				NextEl NextL2 = &ln_funcn;
				Ideal = log(1+x);
				taylor_secondmode(NMax, x, Ideal, FirstL2, NextL2);
				status = 2;
				break;
			}

			default: {
				function_menu;
			}
			}
		}



		if (status == 2) {
			printf("\n\nРазложение в ряд Тейлора успешно инициировано! \n\n");
			end_menu();
			printf("Введите ваш выбор:  ");
			scanf("%d", &c);
			printf("\n");

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
				printf("Thanks for use! Greatful!\n");
				c = 11;
				break;
			}
			}
		}
	}

}
