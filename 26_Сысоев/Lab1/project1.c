#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 10000

// ��������������� ������� ��� ������ ����������� ����������
void print_sort_results(int swaps, int comparisons, clock_t start, clock_t end) {
    printf("����� ������������: %d\n", swaps);
    printf("����� ���������: %d\n", comparisons);
    printf("����� ������: %.6f ������\n", (double)(end - start) / CLOCKS_PER_SEC);
}

// ������� ��� ������ �������
void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ������� ��� ����� ����� �������
int input_len() {
    int len;
    printf("������� ����� �������: ");
    scanf_s("%d", &len);
    if (len <= 0 || len > MAX_LEN) {
        printf("�������� ����� �������\n");
        return input_len();
    }
    return len;
}

// ������� ��� ����� ���������
void input_range(int* start, int* end) {
    printf("������� �������� ����� ������:\n");
    scanf_s("%d %d", start, end);
    if (*start >= *end || *start < 0 || *end > MAX_LEN) {
        printf("�������� ��������. ���������� �����.\n");
        input_range(start, end);
    }
}

// ������� ��� ������� ����� �������
void input_array(int* arr, int len) {
    printf("������� %d �����:\n", len);
    for (int i = 0; i < len; i++) {
        scanf_s("%d", &arr[i]);
    }
}

// ������� ��� ��������������� �������� ������� ���������� ������� � �������� ���������
void auto_create_array(int* arr, int size, int start, int end) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (end - start + 1) + start;
    }
    print_arr(arr, size);
}

// ������������ ���������� ���������
void bubble_sort(int* arr, int n) {
    int swaps = 0, comparisons = 0;
    clock_t start = clock();
    int left = 0, right = n - 1;
    int lastSwap;

    while (left < right) {
        // ������ ����� �������
        lastSwap = 0;
        for (int i = left; i < right; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swaps++;
                lastSwap = i; // ���������� ��������� ������������
            }
        }
        right = lastSwap; // ��������� ������� ������

        // ������ ������ ������
        for (int i = right; i > left; i--) {
            comparisons++;
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swaps++;
                lastSwap = i; // ���������� ��������� ������������
            }
        }
        left = lastSwap; // ��������� ������� �����
    }

    clock_t end = clock();
    print_sort_results(swaps, comparisons, start, end);
}

// ���������� ���������
void insertion_sort(int* arr, int n) {
    int swaps = 0, comparisons = 0;
    clock_t start = clock();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
        swaps++;
    }
    clock_t end = clock();
    print_sort_results(swaps, comparisons, start, end);
}

// ���������� ��������
void merge(int* arr, int left, int mid, int right, int* comparisons, int* swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            (*swaps)++;
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort_recursive(int* arr, int left, int right, int* comparisons, int* swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(arr, left, mid, comparisons, swaps);
        merge_sort_recursive(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

void merge_sort(int* arr, int n) {
    int swaps = 0, comparisons = 0;
    clock_t start = clock();
    merge_sort_recursive(arr, 0, n - 1, &comparisons, &swaps);
    clock_t end = clock();
    print_sort_results(swaps, comparisons, start, end);
}

// ���������� ���������
void counting_sort(int* arr, int n) {
    clock_t start = clock();  // ������ ������� ����������
    int comparisons = 0, swaps = 0;

    // ������� ����������� � ������������ ��������
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        comparisons++;  // ��������� ��� max
        if (arr[i] > max) max = arr[i];
        comparisons++;  // ��������� ��� min
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;  // �������� ��������
    int* count = (int*)malloc(range * sizeof(int));
    memset(count, 0, range * sizeof(int));  // ������������� ������� ��������

    // ���������� ������� ��������
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // ���������� ��������� ������� �� ������ ������� ��������
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]--) {
            arr[index++] = i + min;
            swaps++;  // ��������� ������ ����������� ��� "������������"
        }
    }

    free(count);  // ����������� ������

    clock_t end = clock();  // ����� ������� ����������
    print_sort_results(swaps, comparisons, start, end);  // ������� ����������
}

// ������� ���������� (�����)
void quick_sort_recursive(int* arr, int low, int high, int* swaps, int* comparisons) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            (*comparisons)++;
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                (*swaps)++;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        (*swaps)++;
        int pi = i + 1;

        quick_sort_recursive(arr, low, pi - 1, swaps, comparisons);
        quick_sort_recursive(arr, pi + 1, high, swaps, comparisons);
    }
}

void quick_sort(int* arr, int n) {
    int swaps = 0, comparisons = 0;
    clock_t start = clock();
    quick_sort_recursive(arr, 0, n - 1, &swaps, &comparisons);
    clock_t end = clock();
    print_sort_results(swaps, comparisons, start, end);
}

// �������� �����
int linear_search(int* arr, int n, int target, int* comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// �������� �����
int binary_search(int* arr, int n, int target, int* comparisons) {
    *comparisons = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (arr[mid] == target) {
            return mid;
        }
        (*comparisons)++;
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// ������� ��� ��������, ������������ �� ������
bool is_sorted(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// ����
void print_menu() {
    printf("�������� ����� ���������� ��� ������:\n");
    printf("1 - ����������� ����������\n");
    printf("2 - ���������� ���������\n");
    printf("3 - ���������� ��������\n");
    printf("4 - ���������� ���������\n");
    printf("5 - ������� ����������\n");
    printf("0 - �����\n");
}


int main() {
    setlocale(LC_ALL, "ru");
    while (true) {
        int choice, len, choice1;
        int arr[MAX_LEN];  // �������� ������ ��� ���������� � ������

        printf("�������� ������ ����� �������:\n1. �������\n2. ��������� ��������� � ���������\n3. �����\n");
        scanf_s("%d", &choice);

        if (choice == 1) {
            len = input_len();
            input_array(arr, len);
        }
        else if (choice == 2) {
            int start, end;
            len = input_len();
            input_range(&start, &end);
            auto_create_array(arr, len, start, end);
        }
        else {
            break;  // ����� �� ���������
        }
        while (true) {
            int arr_copy[MAX_LEN];
            memcpy(arr_copy, arr, len * sizeof(int));  // �������� ������ ��� ����������
            print_menu();
            scanf_s("%d", &choice);

            if (choice == 1) {
                bubble_sort(arr_copy, len);
            }
            else if (choice == 2) {
                insertion_sort(arr_copy, len);
            }
            else if (choice == 3) {
                merge_sort(arr_copy, len);
            }
            else if (choice == 4) {
                counting_sort(arr_copy, len);
            }
            else if (choice == 5) {
                quick_sort(arr_copy, len);
            }
            else if (choice1 == 0) {  
                break;
            }
            else {
                printf("�������� �����\n");
            }

            // ����� ���������������� �������
            printf("��������������� ������:\n");
            print_arr(arr_copy, len);
            printf("�������� ����� ������:\n"); 
            printf("1 - �������� �����\n");
            printf("2 - �������� �����\n");
            printf("0 - ���\n");
            scanf_s("%d", &choice1);
            if (choice1 == 1) {  // �������� �����
                int target, comparisons;
                printf("������� �������� ��� ������: ");
                scanf_s("%d", &target);
                int index = linear_search(arr, len, target, &comparisons);
                if (index != -1)
                    printf("������� ������ �� ������� %d (���������: %d)\n", index, comparisons);
                else
                    printf("������� �� ������ (���������: %d)\n", comparisons);
                    }
            else if (choice1 == 2) {  // �������� �����
                if (!is_sorted(arr_copy, len)) {  
                    printf("��� ��������� ������ ������ ������ ���� ������������.\n");
                }
                else {
                    int target, comparisons;
                    printf("������� �������� ��� ������: ");
                    scanf_s("%d", &target);
                    int index = binary_search(arr_copy, len, target, &comparisons); 
                    if (index != -1) {
                        printf("������� ������ �� ������� %d (���������: %d)\n", index, comparisons);
                    }
                    else {
                        printf("������� �� ������ (���������: %d)\n", comparisons);
                    }
                }
            }
            else if (choice1 == 0) {  // ����� �� ���� ���������� � ������
                printf("����� =)\n");
            }
            else {
                printf("�������� �����\n");
            }
        }
    }
    return 0;
}
