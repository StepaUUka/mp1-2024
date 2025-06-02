#include "stdio.h"

void fill(int array[], int len, int digit) {
    int i = 0;
    for(i; i < len; i++) {
        array[i] = digit;
    }
}

int main() {
    int m, n, el;
    double sr, s = 0;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int matrix[m][n];
    int counter[m];
    fill(counter, m, 0);
    for (int i = 0;i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            printf("Enter element matrix[%d][%d]: ", i, j);
            scanf("%d", &el);
            s += el;
            matrix[i][j] = el;
        }
    }
    sr = s/(m*n);
    for (int i = 0;i < m; i++)
    {
        for (int j = 0;j < n; j++)
        {
            if (matrix[i][j] > sr) {
                counter[j] += 1;
            }
        }
    }
    int column = 0, number = counter[0];
    for(int i = 1; i < m; i++) {
        if (counter[i] > number) {
            number = counter[i];
            column = i;
        }
    }
    printf("Answer is: %d %d", column, number);
    return 0;
}