#include <iostream>
#include <cmath>

int main(int, char*)
{
	int n = 0;
	std::cin >> n;

	for (int i = abs (n); i >= 0; i--)
	{
		std::cout << (i * (n / abs(n))) << " ";
	}

	return EXIT_SUCCESS;
}