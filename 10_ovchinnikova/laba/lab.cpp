#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include <time.h>
void print_menu1()
{
	setlocale(LC_ALL, "Russian");
	printf("0. Input_array\n");
	printf("1. RandomArray\n");
}
void print_menu2()
{
	setlocale(LC_ALL, "Russian");
	printf("2. Bubble sort\n");
	printf("3. Insert sort\n");
	printf("4. Counting sort\n");
	printf("5. Selection Sort\n");
	printf("6. Quick Sort\n");
}
void print_menu3()
{
	printf("7. Linear_search\n");
	printf("8. Binary_search\n");
}

void Bubble_sort(int A[], int n, int k)
{
	printf("���������� ���������\n");
	int i, j, temp, sr;
	sr = 0;
	for (i = 0; i < n - 1; i++)
	{
		sr++;
		for (j = 0; j < n - i - 1; j++)
		{
			sr++;
			if (A[j] > A[j + 1])
				sr++;
			{// ������ A[j] � A[j+1]
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				sr = sr + 3;
			}
		}
	}
	printf("\n����� ��������� � ������������ ����� %d\n", sr);
}

void Insert_sort(int A[], int n)
{
	int sr = 0;
	printf("���������� ���������\n");
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = A[i];
		j = i - 1;

		// ���������� �������� A[0..i-1], ������� ������ key,
		// �� ���� ��������� ������ �� �� ������� �������
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			sr = sr + 2;
			j = j - 1;
		}
		A[j + 1] = key;
		sr++;
	}
	printf("\n����� ��������� � ������������ ����� %d\n", sr);
}

void counting_Sort(int n, int A[], int B[]) {
	int k;
	int sr = 0;
	printf("��������� ���������");
	for (int i = 0; i < n; i++) {
		k = 0;
		sr++;
		for (int j = 0; j < n; j++) {
			sr++;
			if (A[i] > A[j])
				k++;
			sr++;
		}
		B[k] = A[i];
		sr++;
	}
	printf("\n����� ��������� � ������������ ����� %d\n", sr);
}
// ������� ���������� �������
void selectionSort(int A[], int n) {
	int i, j, min_idx;
	int sr = 0;

	for (i = 0; i < n - 1; i++) {
		sr++;
		// ������� ������ ������������ �������� � ����������������� ����� �������
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			sr++;
			if (A[j] < A[min_idx]) {
				min_idx = j;
				sr = sr + 2;
			}
		}
		// ����� ���������� ������������ �������� � ������ ���������
		int temp = A[min_idx];
		A[min_idx] = A[i];
		A[i] = temp;
		sr = sr + 3;
	}
	printf("\n����� ��������� � ������������ ����� %d\n", sr);
}

void QS(int* A, int per, int pos, long int p, int p1[])
{

	int i = per, j = pos, x = A[(per + pos) / 2], tmp;

	do {
		p++;
		while (A[i] < x)
			i++;
		while (A[j] > x)
			j--;

		if (i <= j) {
			if (A[i] > A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;

			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < pos)
		QS(A, i, pos, p, p1);
	if (per < j)
		QS(A, per, j, p, p1);

	p1[0] += p;


}

void Linear_search(int A[], int n, int val)
{
	int i, k, sr;
	i = 0;
	k = 0;
	sr = 0;
	while ((i < n) && (A[i] != val)) {
		i++;
		sr++;
	}
	if (i < n) {
		k = i;
		sr++;
	}
	printf("\n���������� ����������� �� %d �����", k + 1);
	printf("\n����� ��������� ����� %d\n", sr);
}
void Binary_search(int A[], int n, int val)
{
	int m, l, r, f, sr;
	m = 0;
	l = 0;
	r = n - 1;
	f = 0;
	sr = 0;
	while ((l <= r) && !f)
	{
		sr++;
		m = (l + r) / 2;
		if (val > A[m]) {
			l = m + 1;
			sr++;
		}
		else if (val < A[m]) {
			r = m - 1;
			sr++;
		}

		else f = 1;

	}
	printf("\n���������� ����������� �� %d �����", m + 1);
	printf("\n����� ��������� ����� %d\n", sr);
}

void Copy_array(int A[], int B[], int n)
{
	int i;
	for (i = 0;i < n;i++)
		B[i] = A[i];
}

void Input_array(int A[], int n)
{
	printf("��������:");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}

}

void RandomArray(int A[], int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = min + rand() % (max - min + 1);  // ��������� ���������� ����� � ��������� [min, max]
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");

	int c, max, min;
	int A[10000];
	int B[10000];
	int n;
	int status = 0;
	printf("�������� ������ �������� �������\n");
	print_menu1();
	scanf_s("%d", &c);
	if (c == 0) {
		printf("������� ���-�� ��������� �������\n");
		scanf_s("%d", &n);
		if (n > 10000) {
			printf("���������� ����� ��������� � �������.������� ���-�� ��������� ��� ���");
			scanf_s("%d", &n);
		}
		Input_array(A, n);
		printf("������ A:");
		for (int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
		Copy_array(A, B, n);
		status = 1;
	}
	if (c == 1) {
		printf("������� ���-�� ��������� �������\n");
		scanf_s("%d", &n);
		if (n > 10000) {
			printf("���������� ����� ��������� � �������.������� ���-�� ��������� ��� ��� ");
			scanf_s("%d", &n);
		}
		printf("������� �����������  �������, � ������� ����� ���������� �����\n");
		scanf_s("%d", &min);
		printf("������� �����������  �������, � ������� ����� ���������� �����\n");
		scanf_s("%d", &max);
		RandomArray(A, n, min, max);
		printf("������ A:");
		for (int j = 0; j < n; j++) {
			printf("%d ", A[j]);
		}
		Copy_array(A, B, n);
		status = 1;
	}
	printf("\n�������� ����� ����������\n");
	print_menu2();
	scanf_s("%d", &c);
	long int y = 0;
	int p1[2] = { 0,0 };
	if (c == 2) {
		int k = 0;
		Bubble_sort(A, n, k);
		for (int j = 0; j < n; j++) {
			printf("%d ", A[j]);
		}
		status = 2;
	}
	if (c == 3) {
		Insert_sort(A, n);
		for (int j = 0; j < n; j++) {
			printf("%d ", A[j]);
		}
		status = 2;
	}
	if (c == 4) {
		//���������� ������� ��������
		counting_Sort(n, A, B);
		for (int j = 0; j < n; j++) {
			printf("%d ", B[j]);
		}
		status = 2;
	}
	if (c == 5) {
		selectionSort(A, n);
		for (int j = 0; j < n; j++) {
			printf("%d ", A[j]);
		}
		status = 2;
	}
	if (c == 6) {
		QS(A, 0, n - 1, y, p1);
		for (int j = 0; j < n; j++) {
			printf("%d ", A[j]);
		}
		status = 2;
	}
	printf("\n������ ����� ������ �������� � ������\n");
	print_menu3();
	scanf_s("%d", &c);
	if (c == 7) {
		int val;
		printf("����� ��������, ������� ���������� ����� ");
		scanf_s("%d", &val);
		Linear_search(A, n, val);
	}
	if (c == 8) {
		int val;
		printf("\n����� ��������, ������� ���������� ����� ");
		scanf_s("%d", &val);
		Binary_search(A, n, val);
	}

}
