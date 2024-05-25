
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<cstring>

int count_worlds(int& n, int& max);//Посчитать количество слов в тексте, вывести самое длинное предложение.
std::string strcat(std::string s, std::string h); //сложение строк
std::string substr(std::string s, int a, int b); //выделение подстроки
int strstr(std::string s, std::string j); //поиск подстроки
std::string strcmp_size(std::string s, std::string j);//сравнение строк
std::string strcmp(std::string s, std::string j); //сравнение строк
std::string strmult(std::string s, int n); //умножение строки на число : "ba" * 3 == "bababa"
void printMenu();

int main()
{
	FILE* file = fopen("in.txt", "r");
	int n;
	std::cin >> n;
	std::string* h = (std::string*)malloc(sizeof(std::string) * n);
	int i = 0;
	while (!feof(file))
	{
		std::string h[i] =
	}

	std::string s = "";
	std::cin >> s;

	std::string j = "";
	std::cin >> j;

	std::string k = "";
	k = strcat(s, j);
	std::cout << k << std::endl;

	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	k = substr(s, a, b);
	std::cout << k <<std::endl;

	int o = 0;
	o = strstr(s, j);
	if (o == s.size()) 
	{
		std::cout << "not in str";
	}
	else
	{
		std::cout << o << std::endl;
	}
	
	k = strcmp_size(s, j);
	std::cout << k << std::endl;

	k = strcmp(s, j);
	std::cout << k << std::endl;

	int n = 0;
	std::cin >> n;
	k = strmult(s, n);
	std::cout << k << std::endl;

	return EXIT_SUCCESS;
}

std::string strcat(std::string s, std::string h)
{
	std::string j = "";
	j = s + h;
	return j;
}

std::string substr(std::string s, int a, int b)
{
	std::string k = "";
	if (a > s.size()) 
	{
		return "out_of_size";
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (i >= a && i <= a + b)
		{
			k += s[i];
		}
	}
	return k;
}

int strstr(std::string s, std::string j)
{
	for (int i = 0; i < s.size(); i++) 
	{
		std::string y = "";
		y = substr(s, i, j.size());
		if (y == j)
		{
			return i;
		}
	}
	return s.size();
}



std:: string strcmp_size(std::string s, std:: string j)
{
	if (s.size() > j.size())
	{
		return "s > j";
	}

	else
	{
		return "j > s";
	}
}

std::string strcmp(std::string s, std::string j)
{
	if (s > j)
	{
		return "s > j";
	}
	else
	{
		return "j > s";
	}
}

std::string strmult(std::string s, int n)
{
	std::string k = "";
	for (int i = 0; i < n; i++) 
	{
		k += s;
	}
	return k;
}

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - strcat" << std::endl;
	std::cout << "2 - substr" << std::endl;
	std::cout << "31 - strstr" << std::endl;
	std::cout << "41 - strcmp_size" << std::endl;
	std::cout << "42 - strcmp" << std::endl;
	std::cout << "5 - strmult" << std::endl;
	
}