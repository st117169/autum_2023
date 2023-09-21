#include <iostream>

int main() {
	int a; int b;
	std :: cin >> a >> b;
	
	int y = 109;
	int km = 109 + (a * b) % y;
	int l = km % 109 + 1;
	std::cout << l;

	return 0;

}