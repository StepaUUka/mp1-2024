#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h> // ��� QueryPerformanceCounter � QueryPerformanceFrequency

#define MAX_SIZE 10000

void bubbleSort(int mass[], int size, int* iterations) {
    int flag = 1;
    *iterations = 0;
    while (flag) {
        flag = 0;
        for (int i = 0; i < size - 1; i++) {
            (*iterations)++;
            if (mass[i] > mass[i + 1]) {
                int t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;
            }
        }
    }
}

void merge(int mass[], int left, int mid, int right, int* iterations) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[10000], rightArr[10000];

    for (int i = 0; i < n1; i++)
        leftArr[i] = mass[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = mass[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*iterations)++;
        if (leftArr[i] <= rightArr[j]) {
            mass[k] = leftArr[i];
            i++;
        }
        else {
            mass[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        mass[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        mass[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int mass[], int left, int right, int* iterations) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(mass, left, mid, iterations);
        mergeSort(mass, mid + 1, right, iterations);
        merge(mass, left, mid, right, iterations);
    }
}

void quickSort(int mass[], int left, int right, int* iterations) {
    if (left < right) {
        int pivot = mass[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (mass[i] < pivot) i++;
            while (mass[j] > pivot) j--;
            if (i <= j) {
                int temp = mass[i];
                mass[i] = mass[j];
                mass[j] = temp;
                i++;
                j--;
            }
            (*iterations)++;
        }
        quickSort(mass, left, j, iterations);
        quickSort(mass, i, right, iterations);
    }
}

void insertionSort(int mass[], int size, int* iterations) {
    *iterations = 0;
    for (int i = 1; i < size; i++) {
        int el = mass[i];
        int loc = i - 1;
        while (loc >= 0 && mass[loc] > el) {
            mass[loc + 1] = mass[loc];
            loc--;
            (*iterations)++;
        }
        mass[loc + 1] = el;
        (*iterations)++;
    }
}

void selectionSort(int mass[], int size, int* iterations) {
    *iterations = 0;
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            (*iterations)++;
            if (mass[j] < mass[min_idx]) {
                min_idx = j;
            }
        }
        int temp = mass[min_idx];
        mass[min_idx] = mass[i];
        mass[i] = temp;
    }
}

int binSearch(int mass[], int min, int max, int target) {
    while (min <= max) {
        int mid = (min + max) / 2;
        if (target < mass[mid]) {
            max = mid - 1;
        }
        else if (target > mass[mid]) {
            min = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int linSearch(int mass[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (mass[i] == target) {
            return i;
        }
    }
    return -1;
}

int isSorted(int mass[], int size) {
    for (int i = 1; i < size; i++) {
        if (mass[i - 1] > mass[i]) {
            return 0;
        }
    }
    return 1;
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int a, b, size;
    int mass[MAX_SIZE];

    printf("������� ���������� ��������� ������� (�������� %d): ", MAX_SIZE);
    scanf_s("%d", &size);
    if (size > MAX_SIZE) {
        printf("������: ���������� ��������� ��������� ������������ ��������.\n");
        return 1;
    }

    printf("�������� ������ ����� �������:\n1. ���� �������\n2. ��������� �����\n");
    scanf_s("%d", &a);

    if (a == 1) {
        printf("������� ������ ������ � %d ��������:\n", size);
        for (int i = 0; i < size; i++) {
            scanf_s("%d", &mass[i]);
        }
    }
    else if (a == 2) {
        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            mass[i] = rand() % 100;
            printf("%d\n", mass[i]);
        }
    }
    else {
        printf("������: �������� �����.\n");
        return 1;
    }

    int temp[MAX_SIZE];
    int iterations = 0;
    LARGE_INTEGER start, end, frequency;

    while (1) {
        printf("�������� ����� ����������:\n1. ����������� ����������\n2. ���������� ��������\n3. ������� ����������\n4. ���������� ���������\n5. ���������� �������\n6. �����\n");
        scanf_s("%d", &b);

        if (b == 6) {
            break; // ����� �� ���������
        }

        copyArray(mass, temp, size);

        // ������ ������� �������
        QueryPerformanceFrequency(&frequency); // �������� ������� �������
        QueryPerformanceCounter(&start); // ���������� ��������� �����

        switch (b) {
        case 1:
            bubbleSort(temp, size, &iterations);
            break;
        case 2:
            mergeSort(temp, 0, size - 1, &iterations);
            break;
        case 3:
            quickSort(temp, 0, size - 1, &iterations);
            break;
        case 4:
            insertionSort(temp, size, &iterations);
            break;
        case 5:
            selectionSort(temp, size, &iterations);
            break;
        default:
            printf("������: �������� �����.\n");
            continue;
        }

        // ����� ������� �������
        QueryPerformanceCounter(&end); // ���������� �������� �����

        double time_spent = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // ����� � ��������

        printf("��������������� ������:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", temp[i]);
        }
        printf("\n");

        printf("��������, ��� ������ ������������: %s\n", isSorted(temp, size) ? "��" : "���");
        printf("���������� ��������: %d\n", iterations);
        printf("����� ������: %f ������\n", time_spent);

        int target;
        printf("�������� ����� ������:\n1. �������� �����\n2. �������� �����\n");
        int searchMethod;
        scanf_s("%d", &searchMethod);

        printf("������� ������� ��� ������: ");
        scanf_s("%d", &target);

        int result;
        if (searchMethod == 1) {
            result = binSearch(temp, 0, size - 1, target);
        }
        else if (searchMethod == 2) {
            result = linSearch(temp, size, target);
        }
        else {
            printf("������: �������� ����� ������ ������.\n");
            continue;
        }

        if (result != -1) {
            printf("������� %d ������ �� ������� %d.\n", target, result);
        }
        else {
            printf("������� %d �� ������.\n", target);
        }
    }

    return 0;
}
