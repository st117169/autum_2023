#include<iostream>

void han(int n, int fr, int to)
{
	if (n <= 0)
	{
		return;
	}

	int res = 6 - fr - to;

	if (n == 1)
	{
		std::cout << n << " " << fr << " " << to; 
	}
	else
	{
		han(n - 1, fr, to);
		han(n - 2, to, res);
		std::cout << "0" << " " << fr << " " << to;
		han(n - 2, res, fr);
		han(n - 1, fr, to);
	}
}


int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	han(n);
	return 0;
}