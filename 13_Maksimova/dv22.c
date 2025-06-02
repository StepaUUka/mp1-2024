#include <stdio.h>
#include <locale.h>

// ������� ��� ���������� ������������� ���������� ������ ������ ��������� ����
void findMaxFreeSeats(int train[100][100], int wagons, int seats, int* maxFree, int* wagonNumber) {
    *maxFree = 0;
    *wagonNumber = -1;

    for (int i = 0; i < wagons; i++) {
        int currentFree = 0;

        for (int j = 0; j < seats; j++) {
            if (train[i][j] == 0) {
                currentFree++;
            }
            else {
                if (currentFree > *maxFree) {
                    *maxFree = currentFree;
                    *wagonNumber = i + 1;
                }
                currentFree = 0;
            }
        }

        if (currentFree > *maxFree) {
            *maxFree = currentFree;
            *wagonNumber = i + 1;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int train[100][100];
    int wagons, seats;

    printf("������� ���������� �������: ");
    scanf_s("%d", &wagons);
    printf("������� ���������� ���� � ������ ������: ");
    scanf_s("%d", &seats);

    for (int i = 0; i < wagons; i++) {
        printf("������� ������ ��� ������ %d (0 - ��������, 1 - ������):\n", i + 1);
        for (int j = 0; j < seats; j++) {
            scanf_s("%d", &train[i][j]);
        }
    }
    int maxFree, wagonNumber;
    findMaxFreeSeats(train, wagons, seats, &maxFree, &wagonNumber);

    if (wagonNumber != -1) {
        printf("������������ ���������� ������ ������ ��������� ����: %d\n", maxFree);
        printf("����� ������ � ���� ����������� ��������� ����: %d\n", wagonNumber);
    }
    else {
        printf("��� ����� ������.\n");
    }

    return 0;
}
