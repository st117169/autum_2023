#include <iostream>

void han(int n, int fr, int to)
{
	if (n == 0)
	{
		return;
	}
	int res = 6 - fr - to;
	han(n - 1, fr, res);
	std::cout << n << " " << fr << " " << to << std::endl;
	han(n - 1, res, to);
}


int main()
{
	int n = 0;
	std::cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int i = 0;
	int from = 1;
	int to = 3;
	int res = 0;
	while (i <= n-1)
	{
		if (a[i] < a[i + 1]) 
		{
			i++;
		}
		else
		{
			han(i, from, to);
			res = abs(to - from);
			from = to;
			to = res;
		}
	}
}