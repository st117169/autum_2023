#include <iostream>

#include<iostream>

void han(int n, int fr, int to)
{
	if (n == 0)
	{
		return;
	}

	int a = 6 - fr - to;
	han(n - 1, fr, a);
	std::cout << n << " " << fr <<  " " << to << std :: endl;
	han(n - 1, a, to);
}

int main(int, char*)
{
	int n = 0;
	std::cin >> n;
	int fr = 0;
	std::cin >> fr;
	int to = 0;
	std::cin >> to;
	han(n, fr, to);
	
	return EXIT_SUCCESS;
}

