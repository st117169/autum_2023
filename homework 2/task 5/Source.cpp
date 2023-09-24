#include <iostream>
void f(int n) {
	if (n == 1) {
		std::cout << n << " bochka";
	}
	if (n >= 2 && n <= 4) {
		std::cout << n << " bochki";
	}
	if ((n >= 5 && n <= 20)|| n == 0) {
		std::cout << n << " bochek";
	}
	if (n > 20) {
		f (n % 10);
	}
}

int main() {
	int n;
	std::cin >> n;
	f(n);

	return 0;
}