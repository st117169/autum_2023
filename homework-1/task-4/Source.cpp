#include <iostream>

int main() {
	long long n;
	std::cin >> n;
	int a = 9;
	int d = 9 - (n%10);
	int ans = (n % 10) * 100 + 9 * 10 + d;
	std::cout << ans;

	return 0;
}