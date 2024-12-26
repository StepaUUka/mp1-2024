#include <stdio.h>
#include <locale.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

void print_menu()
{
    printf("0. ����� \n");
    printf("1. ������� \n");
    printf("2. ���������� \n");
    printf("3. ������ \n");
    printf("4. ����� \n");
}

// ������ �����
double FirstSin(double x)
{
    return x;
}
// ��������� �����
double NextSin(double x, int i)
{
    return (-x * x / (i - 1) / i);
}
// ������ �������
double FirstCos(double x)
{
    return 1;
}
// ��������� �������
double NextCos(double x, int i)
{
    i--;
    return (-x * x / (i - 1) / i);
}
// ������ ����������
double FirstExp(double x)
{
    return 1;
}
// ��������� ����������
double NextExp(double x, int i)
{
    i--;
    return x / i;
}
// ������ ������
double FirstSec(double x)
{
    return 1;
}
// ��������� ������
double NextSec(double x, int i)
{
    if (i % 2 == 0) {
        return (x * x / (i - 1) / i);
    }
    else {
        return 0; // ������ ������ �����
    }
}

typedef double(*First)(double);
typedef double(*Next)(double, int);

// ������ ����� 1
double Teylor(double x, int N, First f, Next g, int h, double eps, double rez, int max_iter)
{
    double prev;
    double next;
    double sums;
    int i = 1, shag;
    prev = f(x);
    sums = 0.0;
    next = 0;
    shag = h;
    int iter = 0;

    while (fabs(sums - rez) > eps && iter < max_iter) // ��������� �� �������� � ���������� ��������
    {
        if (i == 1)
            sums += prev;
        else
        {
            next = prev * g(x, i);
            sums += next;
            prev = next;
        }
        i += shag;
        iter++; // ����������� ������� ��������
    }

    printf("�������� �������� - %lf \n", rez);
    printf("����������� �������� - %lf \n", sums);
    printf("������� � ��������� - %lf \n", fabsl(rez - sums));
    printf("���������� ���������, ������� ���� ��������� ����� %d \n", i);

    // ��������, �� ������ ������� ��������� ������
    if (iter >= max_iter) {
        printf("��������� ������������ ����� �������� (%d).\n", max_iter);
    }
    else {
        printf("���������� ��������� ��������.\n");
    }

    return sums;
}

int main()
{
    int N;
    double eps;
    double x, y;
    int c1 = 0;
    int max_iter;

    setlocale(LC_ALL, "Russian");

    printf("������ ������� �� ������� \n");
    print_menu();
    scanf_s("%d", &c1);

    printf("����� ����� x, � ������� ������ ����� �������� ������� \n");
    scanf_s("%lf", &x);
    printf("����� ����� ��������� ���� ��� ���������� ������� (N) \n");
    scanf_s("%d", &N);
    printf("����� �������� ���������� (eps) \n");
    scanf_s("%lf", &eps);
    printf("����� ������������ ���������� �������� (max_iter) \n");
    scanf_s("%d", &max_iter);

    while (x > M_PI_2)
    {
        x = x - M_PI_2;
    }

    switch (c1)
    {
    case 0:
        y = Teylor(x, N, FirstSin, NextSin, 2, eps, sin(x), max_iter);
        break;
    case 1:
        y = Teylor(x, N, FirstCos, NextCos, 2, eps, cos(x), max_iter);
        break;
    case 2:
        y = Teylor(x, N, FirstExp, NextExp, 1, eps, exp(x), max_iter);
        break;
    case 3:
        y = Teylor(x, N, FirstSec, NextSec, 2, eps, 1 / cos(x), max_iter);
        break;
    case 4:
        printf("����� �� ���������\n");
        return 0;
    default:
        printf("������������ ����. ���������� �����.\n");
        return 1;
    }

    return 0;
}
