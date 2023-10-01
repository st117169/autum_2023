#include <iostream>


int main() {
	int a = 0;
	int b = 0;
	std::cin >> a >> b;

	if (a >= b * 2) {
		while (a >= b * 2) {
			if (a % 2 == 0) {
				a /= 2;
				std::cout << ":2" << std::endl;
			}
			else {
				a -= 1;
				std::cout << "-1" << std::endl;
			}
		}
		if (a != b) {
			while (a != b) {
				a -= 1;
				std::cout << "-1" << std::endl;
			}
		}
		
	}
	if (a < b * 2) {
		while (a != b) {
			a -= 1;
			std::cout << "-1" << std::endl;
		}
	}

	return 0;
}