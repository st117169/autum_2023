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
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) > max)
		{
			max = *(a + i);
		}
	}
	std::cout << max;
	free(a);
	return EXIT_SUCCESS;
}