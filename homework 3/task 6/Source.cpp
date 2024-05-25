#include <iostream>

int main() {

	int y = 0;
	int n = 0;
	std::cin >> n;
	if (n == 1) {
		std::cout << 1;
	}
	else {
		int a = 0;
		int b = 1;
		int c = 0;
		for (int i = 1; i < n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		std:: cout << c;
	}

	return 0;
}