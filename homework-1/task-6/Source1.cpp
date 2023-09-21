#include <iostream>

using namespace std;

int main() {
	int a; cin >> a; int b; cin >> b;
	int ans = (a / b * a + b / a * b) / (a / b + b / a);
	std :: cout << ans;

	return 0;
}