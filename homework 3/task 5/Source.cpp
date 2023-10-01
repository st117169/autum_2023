#include <iostream>
#include <cmath>
#include <string>


int f(int a, int m) {
	int b = pow(10, (m / 2));
	a = a % b;
	int y = 0;
	while (a >= 10) {
		y = y * 10 + a % 10;
		a = a / 10;
	}
	

	return y;
}

int main() {
	int k = 0;
	std::cin >> k;
	int n = 0;
	for (int i = 1; i <= k; i++) {
		int m = 0;
		int o = pow(10, m);
		if (i / o >= 10) {
			m++;
	
		}
		if (m == 0) {
			n++;
		}
		else if (m == 1) {
			if (i / 10 == i % 10) {
				n++;
			}
		}
		else if (m % 2 == 0) {
			int y = f(i, (m - 1));
			if (i / pow(10, ((m + 1) / 2) + 1) == y) {
				n++;
			}
			
		}
		else if (m % 2 != 0) {
			int y = f(i, m);
			if (i / pow(10,  ((m + 1) / 2)) == y) {
				n++;

			}
		}
	}
	std::cout << n;

	return  0;
}