#include <iostream>

void han(int n, int fr, int to)
{
    int a = 6 - fr - to;
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        std::cout << n << " " << fr << " " << to << std::endl;
        
    }
    else
    {
        han(n - 1, fr, to);
        std::cout << n << " " << fr << " " << a << std::endl;
        han(n - 1, to, fr);
        std::cout << n << " " << a << " " << to << std::endl;
        han(n - 1, fr, to);
    }

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

