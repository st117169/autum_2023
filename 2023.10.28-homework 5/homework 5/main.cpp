#include <iostream>
#include <random>
#include "funk.h"

int main(int, char*)
{
	int n = 0;
	std::cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			print(a, n);
		}
		int choice = 0;
		{   
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
			{
				exit = true;
				break;
			}
			case 1: 
			{
				print(a, n);
				break;
			}
				
			case 2:
			{
				add(a, n);
				print(a, n);
				break;
			}
			case 31:
			{
				del1(a, n);
				print(a, n);
				break;
			}
			case 32:
			{
				del2(a, n);
				print(a, n);
				break;
			}
			case 4:
			{   
				sort_up(a, n);
				print(a, n);
				break;
			}
			case 5:
			{
				turn(a, n);
				print(a, n);
				break;
			}
			case 6:
			{
				change(a, n);
				print(a, n);
				break;
			}
			case 7:
			{
				del_dubs(a, n);
				print(a, n);
				break;
			}
			case 8:
			{
				add_n(a, n);
				print(a, n);
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}