#include <iostream>

int main() {
	int n = 0;
	std::cin >> n;
	int a = 0;
	std::cin >> a;
	int s = (((n % 10) * 10) + ((n % 100) / 10));
	if ((s == n / 100 && a == 1) || (s != n / 100 && a != 1)) {
		std::cout << "yes";
	}
	else {
		std::cout << "no";
	}

	return 0;
}