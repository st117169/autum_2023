#include <iostream>
#include <cmath>

int main() {
	int n = 0;
	std::cin >> n;
	int k = 2;
	for (int i = 2; i < n; i++) {
		if (pow(i, 2) < n && n % i == 0) {
			k+= 2;
		}
		else if (pow(i, 2) == n) {
			k++;
			break;
		}
		else if (pow(i, 2) >= n) {
			break;
		}
	}
	std::cout << k;

	return 0;
}