#include <iostream>
#include<algorithm>
#include<ctime>


bool ch_pl(int a, int b);
void bubblesort(int* a, int n);
void insertionsort(int* a, int n);
void selectionsort(int* a, int n);
void countsort(int* a, int n);
bool iss(int* a, int n);
void mix(int* a, int n);
void monkeysort(int* a, int n);
void gnomsort(int* a, int n);
void print_1();
void print(int* a, int n);


int main(int, char**)
{
    int n = 0;
    std::cin >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    bool e = false;
    while (!e)
    {
        {
            system("cls");
            print_1();
            print(a, n);
        }
        int ch = 0;
        {
            std::cin >> ch;
        }
        {
            switch (ch)
            {
            case 1:
            {
                break;
            }
            case 2:
            {
                for (int i = 0; i < n; i++) {
                    a[i] = rand();
                }
                bubblesort(a, n);
                print(a, n);
                system("pause");
                break;
            }
            case 3:
            {
                for (int i = 0; i < n; i++) {
                    a[i] = rand();
                }
                insertionsort(a, n);
                print(a, n);
                system("pause");
                break;
            }
            case 4:
            {  
                for (int i = 0; i < n; i++) {
                    a[i] = rand();
                }
                selectionsort(a, n);
                print(a, n);
                system("pause");
                break;
            }
            case 5:
            {
                for (int i = 0; i < n; i++) {
                    a[i] = rand();
                }
                countsort(a, n);
                print(a, n);
                system("pause");
                break;
            }
            case 6:
            {
                for (int i = 0; i < n; i++) {
                    a[i] = rand();
                }
                monkeysort(a, n);
                print(a, n);
                system("pause");
                break;
            }
            case 7:
            {
                for (int i = 0; i < n; i++) {
                    a[i] = rand();
                }
                gnomsort(a, n);
                print(a, n);
                system("pause");
                break;
            }
            default:
            {
                std::cout << "Unknown command" << std::endl;
                break;
            }
            }
        }
    }
    
    return EXIT_SUCCESS;
}

bool ch_pl(int a, int b)
{
    int k = a;
    a = b;
    b = k;
}

void bubblesort(int*& a, int& n)
{
    int k = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int h = n - 1; h > i; h--)
        {
            if (a[h] < a[h - 1])
            {
                ch_pl(a[h], a[h - 1]);
            }
        }
    }
}

void insertionsort(int*& a, int& n) 
{
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        for (int h = i; h >= 0; h--)
        {
            if (a[i] < a[h]) 
            {
                ch_pl(a[i], a[h]);
            }
        }
    }
}

void selectionsort(int*& a, int& n) 
{
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int h = n - 1; h >= 0; h--)
        {
            if (a[i] < a[h])
            {
                min = i;
            }


        }
        if (min != i) {
            ch_pl(a[i], a[min]);
        }
    }
}

void countsort(int* a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++) 
    {
        if (a[i] > max)
        { 
            max = a[i];
        }
    }
    int* b = (int*)malloc(sizeof(int) * (max +1));
    for (int i = 0; i <= max; i++)
    { 
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    { 
        b[a[i]]++;
    }
    int k = 0;
    for (int i = 0; i < 100; i++)
    {
        while (b[i] != 0)
        {
            a[k] = i;
            k++;
            b[i]--;
        }
    }
        
}

bool iss(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void mix(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int k = rand() % n;
        ch_pl(a[i], a[k]);
    }
}

void monkeysort(int* a, int n)
{
    while (!iss(a, n))
    {
        mix(a, n);
    }
}

void gnomsort(int* a, int n) 
{
    while (!iss(a, n))
    {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1])
            {
                ch_pl(a[i], a[i + 1]);
            }
        }
    }
}
void print_1()
{
    std::cout << "1 - Exit" << std::endl;
    std::cout << "2 - bubble sort" << std::endl;
    std::cout << "3 - insertion sort" << std::endl;
    std::cout << "4 - selection sort" << std::endl;
    std::cout << "5 - count sort" << std::endl;
    std::cout << "6 - monkey sort" << std::endl;
    std::cout << "7 - gnom sort" << std::endl;
}
void print(int* a, int n)
{
    if (a != nullptr) {
        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}




