#include <iostream>
#include "functions.h"


int main(int, char**) {

	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	print(a, n);
	int c =0; std::cin >> c;
	add(a, n, c);
	print(a, n);
	int b = 0; std::cin >> b;
	del1(a, n, b);
	print(a, n);
	int n1 = 0; std::cin >> n1;
	del2(a, n, n1);
	print(a, n);
	for (int i = 1; i < n; i++) {
		sort_1(a[i-1], a[i]);
	}
	print(a, n);
	turn(a, n);
	print(a, n);
	change(a, n);
	print(a, n);
	del_cop(a, n); 
	print(a, n);
	//int j = n;
	//for (int i = 0; i < n; i++) {
	//	int k = 0;
	//	int y = 0;
	//	for (int h = 0; h < n; h++) {
	//		if (a[i] == a[h]) {
	//			k++;
	//		}
	//	}
	//	if (k > 1) {
	//		j -= (k - 1);
	//	}
	//}
	/*for (int i = 0; i < j; i++) {
		std::cout << a[i];
	}*/


}