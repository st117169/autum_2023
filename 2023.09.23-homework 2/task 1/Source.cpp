#include <iostream>
#include <cmath>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a >> b >> c >> d;
	if (a == 0 && b == 0) {
		std::cout << "inf";
	}
	else if ((b / a) % 1 == 0) {
		std::cout << b / a;
	}
	else {
		std::cout << "no";
	}

	return 0;
}