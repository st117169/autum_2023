#include <iostream>

int f(int a, int b) {
	int max = 0;
	for (int i = 1; i <= a; i ++) {
		if (a % i == 0 && b % i == 0) {
			max = i;
		}
	}
	return max;
}

//int f1(int a, int b, int n) {
//
//}

int main() {
	int a = 0;
	int b = 0;
	int n = 0;
	std::cin >> a >> b >> n;
	int y = f(a, b);
	if (n % y != 0 || (n > a && n > b)) {
		std::cout << "imposible";
	}
	else {
		if (a > b) {
			if (a - b == n) {
				std::cout << ">A" << std::endl << "A>B";
			}
			else {
				while (b - a!= n) {
					a -= b;
					std::cout << ">B" << std::endl << "B>A" << std::endl << ">B" << std::endl <<
						"B>A";
				}
			}
		}
		else if (b > a) {
			if (b - a == n) {
				std::cout << ">B" << std::endl << "B>A";
			}
			else {
				while (a - b != n) {
					b -= a;
					std::cout << ">A" << std::endl << "A>B" << std::endl << ">A" << std::endl <<
						"A>B";
				}
			}
		}
	}

	return 0;
}