#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
int smax = 0;

#define and && 
#define or ||
#define pi 3.141592

int main() {
    /*int n;
    scanf_s("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(n * sizeof(int));
    int* c = (int*)malloc((2 * n) * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
        c[i] = a[i];
    }
    int g, k = 0;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &g);
        int f = 0;
        for (int j = 0; j < n; j++) {
            if (g == a[j]) {
                f = 1;
            }
        }
        if (f == 0) {
            b[k] = g;
            k++;
        }
    }
    for (int i = n; i < n + k; i++) {
        c[i] = b[i - n];
    }
    for (int i = 0; i < n + k; i++) {
        printf("%d ", c[i]);
    }
    free(a);
    free(b);
    free(c);
    */


    int m, n;
    int topLeftX = -1, topLeftY = -1, bottomRightX = -1, bottomRightY = -1;
    int matrix[100][100];
    scanf_s("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i][j]);
        }

        smax = 0;
        topLeftX = -1;
        topLeftY = -1; 
        bottomRightX = -1;
        bottomRightY = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    int w = 0, h = 0;
                    while (j + w < n && matrix[i][j + w] == 0) {
                        w++;
                    }
                    bool f = true;
                    while (i + h < m && f) {
                        for (int k = 0; k < w; k++) {
                            if (matrix[i + h][j + k] != 0) {
                                f = false;
                                break;
                            }
                        }
                        if (f) {
                            h++;
                        }
                    }
                    int s = w * h;
                    if (s > smax) {
                        smax = s;
                        topLeftX = i;
                        topLeftY = j;
                        bottomRightX = i + h - 1;
                        bottomRightY = j + w - 1;
                    }
                    
                }
            }
        }
    }

        printf("%d %d \n", topLeftX, topLeftY);
        printf("%d %d \n", bottomRightX, bottomRightY);
        printf("%d", smax);

    
    return 0;
}