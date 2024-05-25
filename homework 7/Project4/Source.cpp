#include<iostream>

	int * a = new int [4] { 0 };
	int** d = new int* [4]{ nullptr, new int[10], new int[10], new int[10] };

void shift(int fr = 1, int to = 3)
{
	std::cout << d[fr][a[fr] - 1] << " " << fr << " " << to << std::endl;
	d[to][a[to]++] = d[fr][--a[fr]];
}
void han(int n, int fr = 1, int to = 3)
{
	if (n == 0)
	{
		return;
	}

	int res = 6 - fr - to;

	han(n - 1, fr, res);
	shift(fr, to);
	std::cout << n << " " << fr << " " << to << std::endl;
	han(n - 1, res, to);
}

void sort()
{
	int n = 0;
	while (a[1] > 0)
	{
		for (int i = 0; i < a[3]; i++) 
		{
			if (d[1][a[1] - 1] > d[3][a[3] - 1 - i])
			{
				n++;
			}
			else
			{
				break;
			}
			han(n, 3, 2);
			shift(1, 3);
			han(n, 2, 3);
		}
	}
}

int main(int argc, char* argv[])
{
	a[1] = 0;
	std::cin >> a[1];
	for (int i = 1; i < 4; ++i)
	{
		std::cin >> d[1][i];
	}
	sort();

	return EXIT_SUCCESS;
}

//2 1 2
//1 1 2
//3 1 3
//1 2 3
//2 2 1
//1 3 1
//3 3 2
//1 1 3
//2 1 2
//1 3 2