#include <iostream>
#include "functions.h"


int main(int, char**) {

	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	del_cop(a, n);
	int j = n;
	for (int i = 0; i < n; i++) {
		int k = 0;
		int y = 0;
		for (int h = 0; h < n; h++) {
			if (a[i] == a[h]) {
				k++;
			}
		}
		if (k > 1) {
			j -= (k - 1);
		}
	}
	for (int i = 0; i < j; i++) {
		std::cout << a[i];
	}


}