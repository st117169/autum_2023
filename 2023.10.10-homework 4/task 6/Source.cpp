#include <iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		int m = 0;
		std::cin >> m;
		*(a + i) = m;
	}
	int k = 0;
	int j = 0;
	int max = 0;
	int min = *(a + 0);
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) < min)
		{
			min = *(a + i);
		}
		else if (*(a + i) > max)
		{
			max = *(a + i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == min)
		{
			*(a + i) = max;
		}
		else if (*(a + i) == max)
		{
			*(a + i) = min;
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);
	return EXIT_SUCCESS;

}