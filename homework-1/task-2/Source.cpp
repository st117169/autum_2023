#include <iostream>
#include <algorithm>

int main() {
	int n; 
	std :: cin >> n;
	int n1 = abs(n - 1) + 1;
	int a = (n + 1) * n1 / 2;
	std :: cout << a;

	return 0;


}