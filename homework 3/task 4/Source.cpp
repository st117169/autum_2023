#include <iostream>
#include <cmath>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a >> b >> c >> d;

	for (int i = 0; i <= 1000; i++) {
		if (a * pow(i, 3) + b * pow(i, 2) + c * i + d == 0) {
			std::cout << i << " ";
		}
	}
	return 0;
}