#include <iostream>

int main() {
	long long n;
	std::cin >> n;
	long long a = ((n /10) *((n / 10 )+ 1)) * 100 + 25;
	std::cout << a;

	return 0;
}