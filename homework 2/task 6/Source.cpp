#include <iostream>



int main() {
	int k = 0; /*����� ������ �����*/
	int n = 0; /*����� ������ ������*/
	int m = 0; /*������*/
	std::cin >> k >> n >> m;
	if (n <= k) {
		std::cout << (2 * m);
	}
	else if (n % k == 0) {
		std::cout << ((n / k) * 2 * m);
	}
	else {
		std::cout << (((n / k) + 1) * 2 *m);
	}
	
	return 0;

}