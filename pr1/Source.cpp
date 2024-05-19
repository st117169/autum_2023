#include "bank.h"
#include <fstream>

int main() {
	setlocale(LC_ALL, "russian");

	std::cout << "1 - создать новый банк\n2 - загрузить банк из файла\n";
	int n;
	Bank r = Bank();
	std::cin >> n;
	if (n == 1)
	{
		int code; std::cout << "Введите код банка\n"; std::cin >> code;
		int n; std::cout << "Введите количество аккаунтов\n"; std::cin >> n;
		r = Bank(code);
		for (int i = 0; i < n; i++)
		{
			Account a = Account();
			std::cout << "Введите данные аккаунта, который хотите добавить\n";
			std::cin >> a;
			r.add(a);
		}
		std::cout << r << std::endl;
	}
	else if (n == 2)
	{
		std::string filename;
		std::cout << "Введите имя файла для чтения из файла\n";
		std::cin >> filename;
		r.read(filename);
		std::cout << "Загруженный банк\n";
		std::cout << r;
	}
	else
	{
		std::cout << "Вы выбрали неизвестную операцию\n";
		return 1;
	}

	while (true)
	{
		std::cout << "0 - выход из системы\n3 - Сохранить банк в файл\n4 - Добавить новый аккаун\n"
			<< "5 - удалить аккаунт\n6 - проверить, существует ли аккаунт в банке\n7 - перевод суммы между счетами\n"
			<< "8 - вывести код банка\n9 - положить деньги на аккаунт\n10 - снять деньги с аккаунта";
		std::cin >> n;
		if (n == 0)
		{
			return 0;
		}
		else if (n == 3)
		{
			std::string filename;
			std::cout << "Введите название файла\n";
			std::cin >> filename;
			r.save(filename);
			std::cout << "Банк сохранен\n";
		}
		else if (n == 4)
		{
			std::cout << "Введите данные аккаунта\n";
			std::cout << "Введите номер аккаунта\n";
			int num;
			std::cin >> num;

			std::string ln;
			std::cout << "Введите фамилию владельца\n";
			std::cin >> ln;

			std::cout << "Введите имя владельца\n";
			std::string name;
			std::cin >> name;

			std::string patronimyc;
			std::cout << "Введите отчество владельца\n";
			std::cin >> patronimyc;

			double balance = 0;
			Account acc(num, ln, name, patronimyc, balance);
			r.add(acc);
			std::cout << "Аккаунт успешно добавлен\n";
			std::cout << r << std::endl;
			acc.~Account();
		}

		else if (n == 5)
		{
			std::cout << "Введите номер аккаунта\n";
			int a = 0;
			std::cin >> a;
			AccList v = r.getacclist();
			Account acc = v.search(a);
			r.remove(acc);
			std::cout << r << std::endl;
			acc.~Account();
			v.~AccList();
		}

		else if (n == 6)
		{
			std::cout << "Введите номер аккаунта\n";
			int a = 0;
			std::cin >> a;
			AccList v = r.getacclist();
			Account acc = v.search(a);
			if (r.exists(acc) == 1)
			{
				std::cout << "Аккаунт найден\n";
			}
			else
			{
				std::cout << "Аккаунт не найден\n";
			}
			acc.~Account();
			v.~AccList();
		}

		else if (n == 7)
		{
			int a = 0;
			std::cout << "Введите номер аккаунта откуда осуществляется перевод\n";
			std::cin >> a;
			int b = 0;
			std::cout << "Введите номер аккаунта куда осуществляется перевод\n";
			std::cin >> b;
			int n = 0;
			std::cout << "Введите сумму перевода\n";
			std::cin >> n;
			AccList al = r.getacclist();
			std::vector<Account> v = al.getaccounts();
			int k = 0; int u = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == a)
				{
					k += 1;
				}
			}
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == b)
				{
					u += 1;
				}
			}
			if (k > 0 && u > 0)
			{
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
				r.setacclist(v);
			}
			if (k == 0 || u == 0)
			{
				std::cout << "одоного из аккаунтов не существует\n";
			}

			std::cout << r << std::endl;
			al.~AccList();

		}

		else if (n == 8)
		{
			std::cout << r.getCode() << std::endl;
		}

		else if (n == 9)
		{
			int a = 0;
			std::cout << "введите номер аккаунта откуда осуществляется перевод\n";
			std::cin >> a;
			int n = 0;
			std::cout << "Введите сумму перевода\n";
			std::cin >> n;
			AccList al = r.getacclist();
			std::vector<Account> v = al.getaccounts();
			int k = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == a)
				{
					k += 1;
				}
			}
			if (k == 0)
			{
				std::cout << "одоного из аккаунтов не существует\n";
			}
			if (k > 0)
			{
				Account aacc = al.search(a);
				std::vector <Account> v = al.getaccounts();
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].getnum() == aacc.getnum())
					{
						v[i].incresebal(n);
					}
				}
				r.setacclist(v);
				std::cout << r << std::endl;
				aacc.~Account();
			}
			al.~AccList();
		}
		else if (n == 10)
		{
			int a = 0;
			std::cout << "введите номер аккаунта откуда осуществляется перевод\n";
			std::cin >> a;
			int n = 0;
			std::cout << "Введите сумму перевода\n";
			std::cin >> n;
			AccList al = r.getacclist();
			std::vector<Account> v = al.getaccounts();
			int k = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].getnum() == a)
				{
					k += 1;
				}
			}
			if (k == 0)
			{
				std::cout << "одоного из аккаунтов не существует\n";
			}
			if (k > 0)
			{
				Account aacc = al.search(a);
				std::vector <Account> v = al.getaccounts();
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].getnum() == aacc.getnum())
					{
						v[i].decresebal(n);
					}
				}
				r.setacclist(v);
				std::cout << r << std::endl;
				aacc.~Account();
			}
			al.~AccList();
		}
	}



	return 0;
}