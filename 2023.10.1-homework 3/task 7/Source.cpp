#include <iostream>
#include <cmath>

int main() {
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		if (pow(i, 2) >= n) {
			std :: cout << i;
			break;
		}
	}
	return 0;
}