#include "stdio.h"
#include "locale.h"


void odin(int C[], int D[], int n1, int n2) {
	int k = -1;
	for (int i = 0;i < n1 + n2 - 1;i++) {
		for (int j = i + 1;j < n1 + n2;j++) {
			if (C[i] == C[j]) {
				k++;
				D[k] = C[i];
			}
		}
	}
	if (k == -1) {
		printf("��� �������������� ��-��� � �������");
	}
	else {
		for (int i = 0;i <=k;i++) {
			printf("%d ", D[i]);
		}
	}
	
}
//3 ������ �� ���������� �������
int main(){
	int n1, n2, A[10000], B[10000], C[10000], D[10000];
	setlocale(LC_ALL, "Russian");

	printf("����� ����� ������� �������, �� ����������� 10000:");
	scanf_s("%d", &n1);

	printf("\n����� �������� 1 ��������: ");

	for (int i = 0;i < n1;i++) {
		scanf_s("%d", &A[i]);
	}
	for (int i = 0;i < n1;i++) {
		printf("%d ", A[i]);
	}
	
	printf("\n����� ����� ������� �������, �� ����������� 10000:");
	scanf_s("%d", &n2);
	

	printf("\n����� �������� 2 ��������:");

	for (int i = 0;i < n2;i++) {
		scanf_s("%d", &B[i]);
	}
	for (int i = 0;i < n2;i++) {
		printf("%d ", B[i]);
	}
	

	printf("\n������� ��������: ");
	for (int j = 0;j < n1;j++) {
		C[j] = A[j];
	}
	int k;
	k = 0;
	for (int j = n1;j < (n1 + n2);j++) {
		C[j] = B[k];
		k++;
	}
	for (int i = 0;i < n1+n2;i++) {
		printf("%d ", C[i]);
	}
	printf("\n���������� ��������: ");
	odin(C, D, n1, n2);
}

