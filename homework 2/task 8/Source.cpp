#include <iostream>
void f(int a, int b, int c) {
	if (a > b && a > c) {
		if (b > c) {
			std::cout << c << " " << b << " ";
		}
		else {
			std::cout << b << " " << c << " ";
		}
		std::cout << a ;
	}
	else if (b > a && b > c) {
		if (a > c) {
			std::cout << c << " " << a << " ";
		}
		else {
			std::cout << a << " " << c << " ";
		}
		std::cout << b;
	}
	else if (c > b && a < c) {
		if (b > a) {
			std::cout << a << " " << b << " ";
		}
		else {
			std::cout << b << " " << a << " ";
		}
		std::cout << c;
	}
}


int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a >> b >> c;
	f(a, b, c);
	return 0;
}