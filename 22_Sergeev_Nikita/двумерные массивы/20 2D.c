#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "rus");

    int employees, months;

    printf("������� ���������� �����������: ");
    scanf_s("%d", &employees);
    printf("������� ���������� �������: ");
    scanf_s("%d", &months);

    
    double* hourly_rates = (double*)malloc(employees * sizeof(double));
    int** hours_worked = (int**)malloc(employees * sizeof(int*));
    double** salaries = (double**)malloc(employees * sizeof(double*));

    for (int i = 0; i < employees; i++) {
        hours_worked[i] = (int*)malloc(months * sizeof(int));
        salaries[i] = (double*)malloc(months * sizeof(double));
    }

   
    for (int i = 0; i < employees; i++) {
        printf("\n������� ��������� ������ ���������� %d: ", i + 1);
        scanf_s("%lf", &hourly_rates[i]);

        printf("������� ���������� ������������ ����� ��� ���������� %d �� ������ �����:\n", i + 1);
        for (int j = 0; j < months; j++) {
            printf("����� %d: ", j + 1);
            scanf_s("%d", &hours_worked[i][j]);
        }
    }

    
    printf("\n�������� ����������� �� ������ �����:\n");
    for (int i = 0; i < employees; i++) {
        printf("\n��������� %d:\n", i + 1);
        for (int j = 0; j < months; j++) {
            salaries[i][j] = hourly_rates[i] * hours_worked[i][j];
            printf("����� %d: %.2f\n", j + 1, salaries[i][j]);
        }
    }

    printf("\n����� ���� �������� �� ������ �����:\n");
    for (int j = 0; j < months; j++) {
        double total_fund = 0.0;
        for (int i = 0; i < employees; i++) {
            total_fund += salaries[i][j];
        }
        printf("����� %d: %.2f\n", j + 1, total_fund);
    }

  

    return 0;
}