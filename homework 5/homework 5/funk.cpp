#include <iostream>
#include "funk.h"

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - print" << std::endl;
	std::cout << "2 - add" << std::endl;
	std::cout << "31 - del1" << std::endl;
	std::cout << "32 - del2" << std::endl;
	std::cout << "4 - sort_up" << std::endl;
	std::cout << "5 - turn" << std::endl;
	std::cout << "6 - change" << std::endl;
	std::cout << "7 - del_dubs" << std::endl;
	std::cout << "8 - add_n" << std::endl;
}

//1 - Вывести массив +

void print(int* a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
//2 - Добавить элемент в массив

void up_size(int*& a, int& n)
{
	n++;
	delete[] a;
	a = new int[n];
}
void add(int*& a, int& n) {
	int c = 0;
	std::cin >> c;
	up_size(a, n);
	a[n - 1] = c;
	
}

//3 - Удалить элемент из массива

void del1(int*& a, int& n) 
{
	int c = 0;
	std::cin >> c;
	int* b = (int*)malloc(sizeof(int) * (n - 1));
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != c) {
			b[i - k] = a[i];
		}
		else {
			k++;
		}
	}
	n--;
	a = new int[n];
	a = b;
}

void del2(int*& a, int& n)
{
	int c = 0;
	std::cin >> c;
	int*b = (int*)malloc(sizeof(int) * (n - 1));
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (i != c) {
			b[i - k] = a[i];
		}
		else {
			k++;
		}
	}
	n--;
	a = new int[n];
	a = b;
}
//4 - Отсортировать массив по возрастанию(любым способом)

void sort_up(int*& a, int& n) 
{
	int k = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int h = n - 1; h > i; h--)
		{
			if (a[h] < a[h - 1])
			{
				int k = a[h];
				a[h] = a[h - 1];
				a[h - 1] = k;
				
			}
		}
	}
}

//5 - Развернуть массив

void turn(int*& a, int n) {
	int* b = (int*)malloc(sizeof(int) * (n));
	for (int i = n - 1; i >= 0; i--) {
		b[(n - 1) - i] = a[i];
	}
	delete[] a;
	a = b;
}
//6 - Поменять местами первый максимальный и последний минимальный элемент массива

void change(int*& a, int n) 
{
	int max = 0;
	int min = a[0];
	for (int i = 0; i < n; i++) 
	{
		if (max < a[i]) 
		{
			max = a[i];
		}
		if (min > a[i]) 
		{
			min = a[i];
		}
	}
	int k = 0;
	int l = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] == max)
		{
			k = i;
			break;
		}
	}
	for (int i = (n - 1); i >= 0; i--) 
	{
		if (a[i] == min) 
		{
			l = i;
			break;
		}
	}
	int u = 0;
	u = a[k];
	a[k] = a[l];
	a[l] = u;
}

//7 - Удалить из массива все дубликаты

void del_dubs(int*& a, int& n)
{
	int* b = (int*)malloc(sizeof(int) * (n));
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		for (int h = i; h < n; h++)
		{
			if (a[i] == a[h])
			{
				k++;
			}
		}
		if (k == 1)
		{
			b[i] = a[i];
		}
		else
		{
			b[i] = 0;
		}
	}
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 0)
		{
			l++;
		}
	}
	delete[] a;
	n -= l;
	a = new int[n];
	int j = 0;
	for (int i = 0; i < n + l; i++) 
	{
		if (b[i] != 0) 
		{
			a[j] = b[i];
			j++;
		}
	}
}

//8 - Добавить в массив n случайных элементов(n вводится с клавиатуры)

void add_n(int*& a, int& n)
{
	int k = 0;
	std::cin >> k;
	int* b = (int*)malloc(sizeof(int) * (n + k));
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	for (int i = n; i < n + k; i++)
	{
		int y = 0;
		y = rand ();
		b[i] = y;
	}
	n += k;
	delete[] a;
	a = new int[n];
	a = b;
}