#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu() {
    printf("|1.��������� ������       |\n");
    printf("|2.���� ������� �������   |\n");
    printf("|3.������� ������         |\n");
    printf("---------------------------\n");
    printf("|4.���������� ���������   |\n");
    printf("|5.���������� �������     |\n");
    printf("|6.���������� ���������   |\n");
    printf("|7.���������� �����       |\n");
    printf("|8.������� ����������     |\n");
    printf("|9.���������� ��������    |\n");
    printf("---------------------------\n");
    printf("|10.�����                 |\n\n");
    printf("�����: ");
}

void insertionSort(int arr[], int n, int* iterationCount) {
    *iterationCount = 0;
    for (int i = 1; i < n; i++) {
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*iterationCount)++;
        }
        arr[j + 1] = k;
        (*iterationCount)++;
    }
}

void selectionSort(int arr[], int n, int* iterationCount) {
    *iterationCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*iterationCount)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        (*iterationCount)++;
    }
}

void countingSort(int arr[], int size, int* iterationCount) {
    *iterationCount = 0;
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        (*iterationCount)++;
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < size; i++) {
        count[arr[i] - min]++;
        (*iterationCount)++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
            (*iterationCount)++;
        }
    }

    free(count);
}

void shellSort(int arr[], int size, int* iterationCount) {
    *iterationCount = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                (*iterationCount)++;
            }
            arr[j] = temp;
            (*iterationCount)++;
        }
    }
}

void quickSort(int arr[], int low, int high, int* iterationCount) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            (*iterationCount)++;
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        
        quickSort(arr, low, i, iterationCount);
        quickSort(arr, i + 2, high, iterationCount);
    }
}

void merge(int arr[], int left, int right, int* iterationCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge(arr, left, mid, iterationCount);
        merge(arr, mid + 1, right, iterationCount);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = (int*)malloc(n1 * sizeof(int));
        int* R = (int*)malloc(n2 * sizeof(int));

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
            (*iterationCount)++;
        }
        for (int i = 0; i < n2; i++) {
            R[i] = arr[mid + 1 + i];
            (*iterationCount)++;
        }

        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            (*iterationCount)++;
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            }
            else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
            (*iterationCount)++;
        }
        while (j < n2) {
            arr[k++] = R[j++];
            (*iterationCount)++;
        }

        free(L);
        free(R);
    }
}

void mergeSort(int arr[], int left, int right, int* iterationCount) {
    merge(arr, left, right, iterationCount);
}

int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void restoreArray(int* arr, int* originalArray, int size) {
    memcpy(arr, originalArray, size * sizeof(int));
}

int main() {
    int vib = 0;
    setlocale(LC_ALL, "rus");
    int globalArraySize = 0;
    int* globalArray = NULL;
    int* originalArray = NULL;

    menu();
    while (vib != 10) {
        scanf_s("%d", &vib);
        switch (vib) {
        case 1: {
            printf("������� ������ �������: ");
            scanf_s("%d", &globalArraySize);
            globalArray = (int*)malloc(globalArraySize * sizeof(int));
            originalArray = (int*)malloc(globalArraySize * sizeof(int));
            for (int i = 0; i < globalArraySize; i++) {
                globalArray[i] = rand() % 101;
            }
            memcpy(originalArray, globalArray, globalArraySize * sizeof(int));
            printf("\n");
            for (int i = 0; i < globalArraySize; i++) {
                printf("%d ", globalArray[i]);
            }
            printf(" - ��� ��������� ������\n\n");
            menu();
            break;
        }
        case 2: {
            printf("������� ������ �������: ");
            scanf_s("%d", &globalArraySize);
            globalArray = (int*)malloc(globalArraySize * sizeof(int));
            originalArray = (int*)malloc(globalArraySize * sizeof(int));
            printf("������� ������: ");
            for (int i = 0; i < globalArraySize; i++) {
                scanf_s("%d", &globalArray[i]);
            }
            memcpy(originalArray, globalArray, globalArraySize * sizeof(int));
            printf("\n");
            for (int i = 0; i < globalArraySize; i++) {
                printf("%d ", globalArray[i]);
            }
            printf(" - ��� ��������� ������\n\n");
            menu();
            break;
        }
        case 3: {
            if (globalArray != NULL && globalArraySize > 0) {
                printf("\n������� ������: ");
                for (int i = 0; i < globalArraySize; i++) {
                    printf("%d ", globalArray[i]);
                }
                printf("\n\n");
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 4: {
            if (globalArray != NULL && globalArraySize > 0) {
                int iterations = 0;
                clock_t start = clock();
                insertionSort(globalArray, globalArraySize, &iterations);
                clock_t end = clock();
                double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\n��������������� ������ (���������� ���������)\n");
                printf("���������� ��������: %d\n", iterations);
                printf("����� ����������: %f ������\n", time_spent);
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 5: {
            if (globalArray != NULL && globalArraySize > 0) {
                int iterations = 0;
                clock_t start = clock();
                selectionSort(globalArray, globalArraySize, &iterations);
                clock_t end = clock();
                double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\n��������������� ������ (���������� �������)\n");
                printf("���������� ��������: %d\n", iterations);
                printf("����� ����������: %f ������\n", time_spent);
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 6: {
            if (globalArray != NULL && globalArraySize > 0) {
                int iterations = 0;
                clock_t start = clock();
                countingSort(globalArray, globalArraySize, &iterations);
                clock_t end = clock();
                double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\n��������������� ������ (���������� ���������)\n");
                printf("���������� ��������: %d\n", iterations);
                printf("����� ����������: %f ������\n", time_spent);
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 7: {
            if (globalArray != NULL && globalArraySize > 0) {
                int iterations = 0;
                clock_t start = clock();
                shellSort(globalArray, globalArraySize, &iterations);
                clock_t end = clock();
                double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\n��������������� ������ (���������� �����)\n");
                printf("���������� ��������: %d\n", iterations);
                printf("����� ����������: %f ������\n", time_spent);
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 8: {
            if (globalArray != NULL && globalArraySize > 0) {
                int iterations = 0;
                clock_t start = clock();
                quickSort(globalArray, 0, globalArraySize - 1, &iterations);
                clock_t end = clock();
                double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\n��������������� ������ (������� ����������)\n");
                printf("���������� ��������: %d\n", iterations);
                printf("����� ����������: %f ������\n", time_spent);
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 9: {
            if (globalArray != NULL && globalArraySize > 0) {
                int iterations = 0;
                clock_t start = clock();
                mergeSort(globalArray, 0, globalArraySize - 1, &iterations);
                clock_t end = clock();
                double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

                printf("\n��������������� ������ (���������� ��������)\n");
                printf("���������� ��������: %d\n", iterations);
                printf("����� ����������: %f ������\n", time_spent);
            }
            else {
                printf("������ �� ���������������. ������� ������� ��� �������� ������.\n\n");
            }
            menu();
            break;
        }
        case 10:
            printf("�����\n");
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
            menu();
        }
    }

    if (globalArray != NULL) {
        free(globalArray);
    }
    if (originalArray != NULL) {
        free(originalArray);
    }

    return 0;
}