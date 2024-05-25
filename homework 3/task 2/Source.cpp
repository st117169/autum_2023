#include <iostream>

int main() {
	std :: string x = "";
	std::cin >> x;
	int k = 0;
	for (int i = x.size() - 1; i >= 0; i--) {
		if (x[i] != '0' || k != 0) {
			std::cout << x[i];
			k++;
		}
	}
	return 0;
}