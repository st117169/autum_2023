#include <iostream>

int main(int, char*)
{
	int n = 0;
	std::cin >> n;

	int k = 1;
	while (n > 10)
	{
		k *= n % 10;
		n = n / 10;
	}

	k *= n;

	std::cout << k;

	return EXIT_SUCCESS;
}