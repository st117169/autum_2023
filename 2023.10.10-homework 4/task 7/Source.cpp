#include <iostream>

int main(int, char**)
{
    int n = 0;
    std::cin >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        int m = 0;
        std::cin >> m;
        *(a + i) = m;
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(a + i) < 0)
        {
            for (int h = i; h < n - 1; h++) {
                *(a + h) = *(a + (h + 1));
            }
            n--;


        }
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << *(a + i) << " ";
    }

    free(a);

    return EXIT_SUCCESS;

}