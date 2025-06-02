#include "locale.h"
#include "windows.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int state;


float genRand() {
	return ((float)rand() / (float)RAND_MAX * 2);
}


void fillRandList(float list[], int n) {
	for (int i = 0; i < n; i++) list[i] = genRand(); /*list[i] = 4;*/
}


int check(float a, float b, int *h) {
	(*h)++;
	return (a > b);
}


int checkE(float a, float b, int* h) {
	(*h)++;
	return (a >= b);
}


void swap(float *a, float *b, int *h) {
	float c;
	c = *a;
	*a = *b;
	*b = c;
	(*h)++;
}


int checkListSorted(float* list, int n) {
	int i = 0;
	int ch = 1;
	while ((i < n - 1) && ch == 1) {
		ch = list[i] <= list[i++ + 1];
	}
	return ch;
}


void listPrint(float list[], int n) {
	int np;
	//����� 10<= ��-�� �������.
	np = min(n, 10);
	printf("%.2f", list[0]);
	for (int i = 1; i < np; i++) {
		printf(" %.2f", list[i]);
	}
	if (n > 10) {
		printf("...");
	}
	printf("\n");
}


void ChoiceSort(float* const list, int n, int* checks, int* swaps) {
	int imn;
	//float mn = -(float)RAND_MAX;
	for (int i = 0; i < n - 1; i++) {
		imn = i;
		for (int j = i + 1; j < n; j++) {
			if (check(list[imn], list[j], checks)) {
				imn = j;
			}
		}
		swap(&list[imn], &list[i], swaps);
	}
}


void DoubleBubble(float* const list, int n, int* checks, int* swaps) {
	int l = 0, r = 0;
	int dlt = 0;
	for (int i = 0; (i < n) || (l + r) < n; i++) {
		//����� ������.
		if (i % 2) {
			dlt = 1;
			for (int j = l; j + r + 1 < n; j++) {
				if (check(list[j], list[j + 1], checks)) {
					swap(&list[j], &list[j + 1], swaps);
					dlt = 1;
				}
				else dlt++;
			}
			r += dlt;
		}
		//����� �����.
		else {
			dlt = 1;
			for (int j = n - r - 1; j > l; j--) {
				if (check(list[j - 1], list[j], checks)) {
					swap(&list[j - 1], &list[j], swaps);
					dlt = 1;
				}
				else dlt++;
			}
			l += dlt;
		}
	}
}



void QuickSortReq(float* const list, int n, int* checks, int* swaps) {
	if (n >= 2) {

		//listPrint(list, n);

		int mid = n / 2;
		float val = list[mid];
		int i = 0, j = n - 1;
		while (check(val, list[i], checks)) i++;
		while (check(list[j], val, checks)) j--;
		while (i<=j) {
			swap(&list[i], &list[j], swaps);
			i++; j--;
			while (check(val, list[i], checks)) i++;
			while (check(list[j], val, checks)) j--;
			//printf("\t%d - %d ����� \n", i, j);
			
		}
		//listPrint(list, n);
		//printf("%f - %d - %d - %d ������ \n", val, i, j, j + 1);
		QuickSortReq(list, j + 1, checks, swaps);
		QuickSortReq(list + i, n - i, checks, swaps);
	}
}


void QuickSortIter(float* const list, int n, int* checks, int* swaps) {
	int startPos;
	int locN;
	float val;
	int i = 0, j = n - 1;

	int chN = 1;
	int* ch = (int*)malloc(sizeof(int) * n * 2);
	ch[0] = i;
	ch[1] = n;
	while (chN > 0) {
		startPos = ch[chN * 2 - 2];
		i = startPos;
		locN = ch[chN * 2 - 1];
		val = list[startPos + locN / 2];
		j = startPos + locN - 1;
		while (check(val, list[i], checks)) i++;
		while (check(list[j], val, checks)) j--;
		while (i <= j) {
			swap(&list[i], &list[j], swaps);
			i++; j--;
			while (check(val, list[i], checks)) i++;
			while (check(list[j], val, checks)) j--;
		}
		chN--;
		if (j - startPos > 0) {
			ch[chN * 2] = ch[chN * 2];
			ch[chN * 2 + 1] = j + 1 - startPos;
			chN++;
		}
		if (locN - i + startPos > 1) {
			ch[chN * 2] = i;
			ch[chN * 2 + 1] = locN - i + startPos;
			chN++;
		}
		
	}
	free(ch);
}


void PyramidMaximise(float* const list, int n, int* checks, int* swaps) {
	int locN = (n - 1) / 2 - (n % 2);
	int k;
	int ch;
	int child;
	while (locN >= 0) {
		k = locN;
		ch = 1;
		child = k * 2 + 1;
		if (child + 1 < n) {
			child += check(list[child + 1], list[child], checks);
		}
		while (ch && check(list[child], list[k], checks)) {
			
			swap(&list[k], &list[child], swaps);
			k = child;
			child = k * 2 + 1;
			if (child >= n) {
				ch = 0;
			}
			else if (child + 1 < n) {
				child += check(list[child + 1], list[child], checks);
			}
		}
		locN--;
		
	}
}


void Pyramid(float* const list, int n, int* checks, int* swaps) {
	PyramidMaximise(list, n, checks, swaps);
	int k = 0;
	int ch = 1;
	int child = k * 2 + 1;
	while (n > 1) {
		swap(&list[0], &list[n - 1], swaps);
		n--;
		k = 0;
		ch = 1;
		child = k * 2 + 1;

		if (child + 1 < n) {
			child += check(list[child + 1], list[child], checks);
		}
		while (ch && check(list[child], list[k], checks)) {

			swap(&list[k], &list[child], swaps);
			k = child;
			child = k * 2 + 1;
			if (child >= n) {
				ch = 0;
			}
			else if (child + 1 < n) {
				child += check(list[child + 1], list[child], checks);
			}

		}
	}
	swap(&list[0], &list[n], swaps);
}



//state = 0: ���� - ��������� �������
void showBaseScreen(float list[], int* n) {
	int input;
	float cop[9] = {5, 4, 1, 2, 5, 6, 9, 7, 8};
	listPrint(list, *n);

	//������ ������.
	printf("\n1) ��������� ������ (������ ��� n < 11).\n");
	printf("2) �������� ��������� ������.\n");
	printf("3) �������� ������ �������.\n");
	printf("4) ������� ������������� ������.\n");
	printf("\n5) ������������� ������.\n");
	printf("\n25) �����.\n");

	input = 0;
	scanf_s("%d", &input);
	switch (input) {
	case(1): state = 1; break;
	case(2): fillRandList(list, *n); printf("������ �������� ������������;)\n"); break;
	case(3): state = 2; break;
	case(4): memcpy(list, cop, (sizeof(float) * 9)); *n = 9; break;
	case(5): state = 3; break;
	case(25): state = 255; break;
	}
}


//state = 1: ��������������� ����� �������.
void manualFillScreen(float list[10], int n) {
	if (n > 10) {
		printf("\n������ ������� �������: ������� �������� ������ �������.\n");
	}
	else {
		printf("\n�� ������ ������� �������� �������.\n");
		for (int i = 0; i < n; i++) scanf_s("%f", &list[i]);
	}
	state = 0;
}


//state = 2: ��������� ������� �������.
void listSizeChangeScreen(float list[], int *n) {
	int input = 0;
	printf("\n������ ������� ��������� �� 2 - 15000 ���������,\n �� ������ ������ ������ ������� - %d\n", *n);
	scanf_s("%d", &input);
	while ((input < 2) || (input > 15000)) {
		printf("������������ ������ �������.\n");
		scanf_s("%d", &input);
	}
	if (input > *n) {
		for (int i = *n; i < input; i++) list[i] = genRand();
	}
	*n = input;
	state = 0;
}

//state = 3: ����������
void sortScreen(float list[], int n, LARGE_INTEGER freq) {
	int input;
	LARGE_INTEGER start, finish;
	int checks = 0, swaps = 0;
	float* sr_list = (float*)malloc(sizeof(float) * n);
	state = 0;
	
	if (sr_list == NULL) printf("\n��� ������((.\n");
	else {
		listPrint(list, n);
		memcpy(sr_list, list, sizeof(float) * n);

		printf("\n1) ��������������� ������.\n");
		printf("2) ���������� �������\n");
		printf("3) ������� ����������. (� ���������)\n");
		printf("4) ������� ����������. (��� ��������)\n");
		printf("5) ������������� ����������\n");
		scanf_s("%d", &input);

		
		QueryPerformanceCounter(&start);
		switch (input) {
		case(1): 
			printf("\n��������������� ������:\n");
			DoubleBubble(sr_list, n, &checks, &swaps);break;
		case(2):
			printf("\n���������� �������:\n");
			ChoiceSort(sr_list, n, &checks, &swaps); break;
		case(3):
			printf("\n������� ����������. (� ���������):\n");
			QuickSortReq(sr_list, n, &checks, &swaps); break;
		case(4):
			printf("\n������� ����������. (��� ��������):\n");
			QuickSortIter(sr_list, n, &checks, &swaps); break;
		case(5):
			printf("\n������������� ����������:\n");
			Pyramid(sr_list, n, &checks, &swaps); break;
		}
		QueryPerformanceCounter(&finish);
		if (checkListSorted(sr_list, n))
			printf("������������.\n");
		else printf("������ ����������!!\n");
		listPrint(sr_list, n);
		printf("\n����� ����������: %lf\n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
		printf("���-�� ��������: %d, ���-�� �������: %d\n\n", checks, swaps);
		free(sr_list);
	}
	
}



int main() {
	LARGE_INTEGER freq;
	float list[15001];
	int n = 10;
	//printf("%d\n", RAND_MAX);
	//��� �������:
	QueryPerformanceFrequency(&freq);
	//��� �����:
	setlocale(LC_ALL, "Russian");
	//������ + ��������� ����:
	//srand(time(NULL));
	fillRandList(list, n);

	while (state != 255) {
		printf("\n=================================\n");
		if (state > 3) {
			state = 0;
		}
		switch (state) {
		case(0): showBaseScreen(list, &n); break;
		case(1): manualFillScreen(list, n); break;
		case(2): listSizeChangeScreen(list, &n); break;
		case(3): sortScreen(list, n, freq); break;
		}
	}
	return 1;
}