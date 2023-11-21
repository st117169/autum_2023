
#include "functions.h"

//1
void print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		std:: cout << a[i];
	}
}

//2
void add(int* a, int n, int c) {
	int* a1 = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++) {
		a1[i] = a[i];
	}
	a1[n] = c;
	a = a1;
}

//3
void del1(int* a, int n, int c) {
	int* a1 = (int*)malloc(sizeof(int) * (n - 1));
	for (int i = 0; i < n; i++) {
		if (a[i] != c) {
			a1[i] = a[i];
		}
	}
}

void del2(int* a, int n, int c) {
	int* a1 = (int*)malloc(sizeof(int) * (n - 1));
	for (int i = 0; i < n; i++) {
		if (i != c) {
			a1[i] = a[i];
		}
	}
}

//4

bool sort_1(int a, int b) {
	return a < b;
}

//5

void turn(int* a, int n) {
	int* b = (int*)malloc(sizeof(int) * (n));
	for (int i = n - 1; i >= 0; i--) {
		b[(n - 1) - i] = a[i];
	}
	a = b;
}


//6

void change(int* a, int n) {
	int max = 0;
	int min = a[0];
	for (int i = 0; i < n; i = 0) {
		if (max < a[i]) {
			max = a[i];
		}
		else if (min > a[i]) {
			min = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			a[i] = min;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == min) {
			a[i] = max;
			break;
		}
	}
}

//7

void del_cop(int* a, int n) {
	int j = n;
	for (int i = 0; i < n; i++) {
		int k = 0;
		int y = 0;
		for (int h = i; h < n; h++) {
			if (a[i] == a[h]) {
				k ++;
			}
		}
		if (k > 1) {
			j --;
		}
	}
	int* a1 = (int*)malloc(sizeof(int) * (j));
	for (int i = 0; i < n; i++) {
		int k = 0;
		int y = 0;
		for (int h = 0; h < j; h++) {
			if (a[i] == a1[h]) {
				k++;
			}
		}
		if (k == 0) {
			a1[y] = a[i];
			y++;
		}
	}
	a = a1;

}