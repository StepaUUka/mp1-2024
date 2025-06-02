#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>


#define and && 
#define or ||
#define pi 3.141592

int main() {
/*````````````2````````````````*/
	int row = 0, col = 0;
	int n; 
	int a[10000];
	int k = 0;
	scanf_s("%d", &n);
	int b[100][100];
	col = pow(n, 0.5);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	while ((row)* (col) != n) {
		for (int i = 0; i < col; i++) {
			b[row][i] = a[k];
			k++;
		}
		row++;
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
/*````````end 2```````````````````````````*/


	/*`````````19`````````*/
	int n; 
	scanf_s("%d", &n);
	int a[10000][4];
	int n1_1 = 0, n1_neud = 0, n1_ud = 0, n1_hor = 0, n1_otl = 0;
	int n2_1 = 0, n2_neud = 0, n2_ud = 0, n2_hor = 0, n2_otl = 0;
	int n3_1 = 0, n3_neud = 0, n3_ud = 0, n3_hor = 0, n3_otl = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &a[i][j]);
			if (j == 0) {
				if (a[i][j] == 1) {
					n1_1++;
				}
				else if (a[i][j] == 2) {
					n1_neud++;
				}
				else if (a[i][j] == 3) {
					n1_ud++;
				}
				else if (a[i][j] == 4) {
					n1_hor++;
				}
				else {
					n1_otl++;
				}
			}
			else if (j == 1){
				if (a[i][j] == 1) {
					n2_1++;
				}
				else if (a[i][j] == 2) {
					n2_neud++;
				}
				else if (a[i][j] == 3) {
					n2_ud++;
				}
				else if (a[i][j] == 4) {
					n2_hor++;
				}
				else {
					n2_otl++;
				}
			}
			else {
				if (a[i][j] == 1) {
					n3_1++;
				}
				else if (a[i][j] == 2) {
					n3_neud++;
				}
				else if (a[i][j] == 3) {
					n3_ud++;
				}
				else if (a[i][j] == 4) {
					n3_hor++;
				}
				else {
					n3_otl++;
				}
			}
		}
	}
	printf("For the first exam result is: \nOtsutstvie = %d, Neudovlitvoritelno = %d, Udovlitvoritelno = %d, Horosho = %d, Otlichno = %d \n", n1_1, n1_neud, n1_ud, n1_hor, n1_otl);

	printf("For the second exam result is: \nOtsutstvie = %d, Neudovlitvoritelno = %d, Udovlitvoritelno = %d, Horosho = %d, Otlichno = %d \n", n2_1, n2_neud, n2_ud, n2_hor, n2_otl);

	printf("For the third exam result is: \nOtsutstvie = %d, Neudovlitvoritelno = %d, Udovlitvoritelno = %d, Horosho = %d, Otlichno = %d \n", n3_1, n3_neud, n3_ud, n3_hor, n3_otl);
	return 0;
}