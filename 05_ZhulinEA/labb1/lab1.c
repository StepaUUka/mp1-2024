#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
//задебагать couting sort для отрицательных 

#define and && 
#define or ||
int copy_massive(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	return b;
}

int min1(int a, int b) {
	if (a < b) {
		return a;

	}
	return b;
}
int max1(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
void print_menu() {
	printf("1. Buble sort\n");
	printf("2. Insertion sort \n");
	printf("3. Selection sort\n");
	printf("4. Merge sort\n");
	printf("5. Couting sort \n");
	printf("6. Quick sort\n ");
	printf("7. Shell sort\n");
	printf("8. Piramyd sort\n");
	printf("9. Radix sort\n");
	printf("10. Quick sort(not recursion)\n");
	printf("11. Merge sort(not recursion\n");
	printf("12. Binary search\n");
	printf("13. Linear search\n");
	printf("14. Поменять массив\n");
	printf("0. Exit\n");
}

void proverka(int a[], int n) {
	int f = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			f = 0;
		}
	}
	if (f == 0) {
		printf("Array not sorted!");
	}
	else {
		printf("Array sorted!");
	}
}
void Selection_sort(int a[], int n) {
	clock_t start = clock();
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			int t = a[i];
			a[i] = a[min_idx];
			a[min_idx] = t;
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("Time spent your programm: %f \n", time_spent);

	printf("\n");
}



void Buble_sort(int a[], int n) {
	int l = 1;
	int r = n - 1;
	int k;
	int f = 1;
	clock_t start = clock();
	while (l < r and f == 1) {
		f = 0;
		for (int i = r; i >= l; i--) {
			if (a[i] < a[i - 1]) {
				k = a[i];
				a[i] = a[i - 1];
				a[i - 1] = k;
				f = 1;
			}
		}
		l++;
		for (int i = l; i <= r; i++) {
			if (a[i - 1] > a[i]) {
				k = a[i];
				a[i] = a[i - 1];
				a[i - 1] = k;
				f = 1;
			}
		}
		r--;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("~~~~~~~~~~~~~~~~~~ \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("~~~~~~~~~~~~~~~~~~ \n");
	printf("Time spent your programm: %f \n", time_spent);
	printf("\n");
}

void Insertion_sort(int a[], int n) {
	clock_t start = clock();
	for (int i = 1; i < n; i++) {
		int k = a[i];
		int j = i - 1;
		while (j >= 0 and a[j] > k) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
	printf("Time spent your programm: %f \n", time_spent);

	printf("\n");

}
void merge(int arr[], int l, int mid, int r) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int L[10000], R[10000];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	

}
void Merge_sort(int arr[], int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		Merge_sort(arr, l, mid);
		Merge_sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

void Counting_sort(int a[], int n) {
	int mn = 100000000, mx = -10000000;
	clock_t start = clock();

	for (int i = 0; i < n; i++) {
		mn = min1(mn, a[i]);
		mx = max1(mx, a[i]);
	}
	int range = mx - mn + 1;
	int* count = (int*)calloc(range, sizeof(int));

	for (int i = 0; i < n; i++)
		count[a[i] - mn]++;
	for (int i = 1; i < range; i++)
		count[i] += count[i - 1];
	int* output = (int*)malloc(n * sizeof(int));
	for (int i = n - 1; i >= 0; i--) {
		output[count[a[i] - mn] - 1] = a[i];
		count[a[i] - mn]--;
	}
	for (int i = 0; i < n; i++){
		a[i] = output[i];
	printf("%d ", a[i]);
}
	free(count);
	free(output);
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Time spent your program: %f\n", time_spent);
	printf("\n");
}
int partition(int a[], int l, int r) {
	int pivot = a[(l + r) / 2];
	int k;
	while (l <= r) {
		while (a[l] < pivot)
			l++;
		while (a[r] > pivot)
			r--;
		if (l <= r) {
			k = a[l];
			a[l] = a[r];
			a[r] = k;
			l++;
			r--;
		}
	}
	return l;
}

void Quick_sort(int a[], int l, int r) {
	if (l < r) {
		int pi = partition(a, l, r);
		Quick_sort(a, l, pi - 1);
		Quick_sort(a, pi, r);
	}
	
}


void Shell_sort(int arr[], int n) {
	printf("not released!!!");
	printf("\n");

}
void Piramyd_sort(int arr[], int n) {
	printf("not released!!!");
	printf("\n");

}
void Radix_sort(int arr[], int n) {
	printf("not released!!!");
	printf("\n");

}
void Quick_sort_nr(int arr[], int n) {
	printf("not released!!!");
	printf("\n");

}
void Merge_sort_nr(int arr[], int n) {
	printf("not released!!!");
	printf("\n");

}
int Binary_search(int arr[], int n, int e) {
	int l = 0, r = n - 1, f = 0, mid, k, pos = -1;
	long long iteration = 0; 
	clock_t start = clock();
	while (l <= r) {
		mid = (l + r) / 2;
		iteration++; 
		if (arr[mid] < e) {
			l = mid + 1;
		}
		else if (arr[mid] > e) {
			r = mid - 1;
		}
		else {
			f = 1;
			pos = mid;
			break;
		}
	}
	if (f == 1) {
		printf("~~~~~~~~~~~~~~~~ \nЧисло найдено  %d\n~~~~~~~~~~~~~~~~ \n", pos);
	}
	else {
		printf("~~~~~~~~~~~~~~~~ \n Число не найдено \n~~~~~~~~~~~~~~~~ \n");
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time spent your programm: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);
	printf("\n");
	return pos;
}
void Linear_search(int a[], int n, int e) {
	int f = 0;
	long long iteration = 0; 
	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		if (a[i] == e) {
			f = 1;
		}
		iteration++; 
	}
	if (f == 1) {
		printf("~~~~~~~~~~~~~~~~ \nNumber is here\n~~~~~~~~~~~~~~~~ \n");
	}
	else {
		printf("~~~~~~~~~~~~~~~~ \n Number Not is here \n~~~~~~~~~~~~~~~~ \n");
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time spent your programm: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);
	printf("\n");

}
void printa(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void fuckthis(clock_t a, clock_t b) {
	double time_spent = (double)(b - a) / CLOCKS_PER_SEC; 
	printf("Time spent your programm: %f \n", time_spent);
}
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int a[40010];
	int n, e, g = 1;
	int c;
	int ac[20010];
	int iter;
	LARGE_INTEGER freq, start, finish;
	double time;
	int vibor;
	printf("Choose size your array:");
	scanf_s("%d", &n);
	printf("Choose the way to set the array: \n 1.To hand \n 2.Random \n");
	scanf_s("%d", &vibor);
	if (vibor == 2) {
		for (int i = 0; i < n; i++) {
			a[i] = (rand() % 20001) - 10000;
		}
		printf("The array is generated: \n");
		printa(a, n);
	}
	else {
		printf("Enter the numbers in the array separated by a space: \n");
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &a[i]);
		}
	}
	while (true) {
		print_menu();
		printf("Choose your way: ");
		scanf_s("%d", &c);
		switch (c) {
		case 0: printf("The program has completed the work");  return 0; break;
		case 1: copy_massive(a, ac, n); Buble_sort(ac, n); break;
		case 2: copy_massive(a, ac, n); Insertion_sort(ac, n); break;
		case 3: copy_massive(a, ac, n); Selection_sort(ac, n); break;
		case 4: copy_massive(a, ac, n); clock_t start = clock(); Merge_sort(ac, 0, n - 1); clock_t end = clock(); fuckthis(start, end); printa(ac, n); break;
		case 5: copy_massive(a, ac, n); Counting_sort(ac, n); break;
		case 6: copy_massive(a, ac, n); clock_t start1 = clock(); Quick_sort(ac, 0, n - 1); clock_t end1 = clock(); fuckthis(start1, end1); printa(ac, n);  break;
		case 7: copy_massive(a, ac, n); Shell_sort(ac, n); break;
		case 8: copy_massive(a, ac, n); Piramyd_sort(ac, n); break;
		case 9: copy_massive(a, ac, n); Radix_sort(ac, n); break;
		case 10: copy_massive(a, ac, n); Quick_sort_nr(ac, n); break;
		case 11: copy_massive(a, ac, n); Merge_sort_nr(ac, n); break;
		case 12: copy_massive(a, ac, n);
			printf("Enter the element we are looking for: \n");	
			scanf_s("%d", &e);
			Binary_search(ac, n, e);
			break;
		case 13: copy_massive(a, ac, n);
			printf("Enter the element we are looking for: \n");
			scanf_s("%d", &e);
			Linear_search(ac, n, e);
			break;
		case 14:
			printf("Choose size your array:");
			scanf_s("%d", &n);
			printf("Choose the way to set the array: \n 1.To hand \n 2.Random \n");
			scanf_s("%d", &vibor);
			if (vibor == 2) {
				for (int i = 0; i < n; i++) {
					a[i] = (rand() % 20001) - 10000;
				}
				printf("The array is generated: \n");
				printa(a, n);
			}
			else {
				printf("Enter the numbers in the array separated by a space: \n");
				for (int i = 0; i < n; i++) {
					scanf_s("%d", &a[i]);
				}
			}
		}
	}

	return 0;
}