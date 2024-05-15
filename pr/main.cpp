#include "bank.h"


int main() {
	setlocale(LC_ALL, "russian");


	

	std::cout << "1 - ������� ����� ����\n2 - ��������� ���� �� �����\n";
	int n; Bank r = Bank();
	std::cin >> n;
	if (n == 1)
	{
		int code; std::cout << "������� ��� �����\n"; std::cin >> code;
		int n; std::cout << "������� ���������� ���������\n"; std::cin >> n;
		r = Bank(code);
		for (int i = 0; i < n; i++)
		{
			Account a = Account(); std::cout << " ������� ������ ��������, ������� ������ ��������\n"; std::cin >> a;
			r.add(a);
		}
	}
	else if (n == 2)
	{
		std::string filename;
		std::cout << "������� ��� ����� ��� ������ �� �����\n";
		std::cin >> filename;
		Bank::read(filename, r);
		std::cout << "����������� ����\n";
		std::cout << r;
	}
	else 
	{
		std::cout << "�� ������� ����������� ��������\n";
		return 1;
	}

	while (true)
	{
		std::cout << "0 - ����� �� �������\n3 - ��������� ���� � ����\n4 - �������� ����� ������\n"
			<< "5 - ������� �������\n6 - ���������, ���������� �� ������� � �����\n7 - ������� ����� ����� �������\n"
			<< "8 - ������� ��� �����\n9 - �������� ������ �� �������\n10 - ����� ������ � ��������";
		std::cin >> n;
		if (n == 0) 
		{
			return 0;
		}
		else if (n == 3) 
		{
			std::string filename;
			std::cout << "������� �������� �����\n";
			std::cin >> filename;
			Bank::save(filename, r);
			std::cout << "���� ��������\n";
		}
		else if (n == 4) 
		{
			std::cout << "������� ������ ��������\n";
			std::cout << "������� ����� ��������\n";
			int num;
			std::cin >> num;

			std::string ln;
			std::cout << "������� ������� ���������\n";
			std::cin >> ln;

			std::cout << "������� ��� ���������\n";
			std::string name;
			std::cin >> name;

			std::string patronimyc;
			std::cout << "������� �������� ���������\n";
			std::cin >> patronimyc;

			double balance = 0;
			Account acc(num, ln, name, patronimyc, balance);
			r.add(acc);
			std::cout << "������� ������� ��������\n";
			acc.~Account();
		}

		else if (n == 5) 
		{
			std::cout << "������� ����� ��������\n";
			int a = 0; std::cin >> a;
			AccList v = r.getacclist();
			Account acc = v.search(n);
			r.remove(acc);
			acc.~Account();
			v.~AccList();
		}

		else if (n == 6)
		{
			std::cout << "������� ����� ��������\n";
			int a = 0; std::cin >> a;
			AccList v = r.getacclist();
			Account acc = v.search(n);
			if (r.exists(acc) == 1)
			{
				std::cout << "������� ������\n";
			}
			else
			{
				std::cout << "������� �� ������\n";
			}
			acc.~Account();
			v.~AccList();
		}
				
		else if (n == 7) 
		{
			int a = 0; std::cout << "������� ����� �������� ������ �������������� �������\n"; std::cin >> a;
			int b = 0; std::cout << "������� ����� �������� ���� �������������� �������\n"; std::cin >> b;
			int n = 0; std::cout << "������� ����� ��������\n"; std::cin >> n;
			AccList al = r.getacclist();
			Account aacc = al.search(a);
			Account bacc = al.search(b);
			aacc.trans(bacc, n);
			std::vector <Account> v = al.getaccounts();
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == aacc.getnum())
				{
					v[i] = aacc;
				}
				if (v[i].getnum() == bacc.getnum())
				{
					v[i] = bacc;
				}
			}
			aacc.~Account();
			bacc.~Account();
			al.~AccList();
		}

		else if (n == 8) 
		{
			std::cout << r.getCode() << std::endl;
		}

		else if (n == 9)
		{
			int a = 0; std::cout << "������� ����� �������� ������ �������������� �������\n"; std::cin >> a;
			int n = 0; std::cout << "������� ����� ��������\n"; std::cin >> n;
			AccList al = r.getacclist();
			Account aacc = al.search(a);
			std::vector <Account> v = al.getaccounts();
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == aacc.getnum())
				{
					v[i].incresebal(n);
				}
			}
			aacc.~Account();
			al.~AccList();
		}
		else if (n == 10)
		{
			int a = 0; std::cout << "������� ����� �������� ������ �������������� �������\n"; std::cin >> a;
			int n = 0; std::cout << "������� ����� ��������\n"; std::cin >> n;
			AccList al = r.getacclist();
			Account aacc = al.search(a);
			std::vector <Account> v = al.getaccounts();
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == aacc.getnum())
				{
					v[i].decresebal(n);
				}
			}
			aacc.~Account();
			al.~AccList();
		}
	}



	return 0;
}