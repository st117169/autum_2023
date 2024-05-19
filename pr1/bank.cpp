#include "bank.h"
#include <iostream>
#include <fstream>
#include <string>
#include "split.h"
#include <string>

Bank::Bank()
{
	this->code = 0;
}

Bank::Bank(int code)
{
	this->code = code;
}

Bank::Bank(const Bank& b)
{
	this->code = b.code;
	this->acclist = b.acclist;
}

Bank::Bank(Bank&& bank) noexcept {
	this->code = bank.code;
	this->acclist = bank.acclist;
	bank.code = 0;
	bank.acclist.~AccList();
}


Bank::~Bank()
{
	this->acclist.~AccList();
	code = 0;
}

Account Bank::create(int n, std::string lastname, std::string name, std::string patronimyc, double balance)
{
	return Account(n, lastname, name, patronimyc, balance);
}

void Bank::add(Account& account)
{
	this->acclist.add(account);
}

void Bank::remove(const Account& acc)
{
	this->acclist.remove(acc);
}

bool Bank::exists(const Account& account) const
{
	return this->acclist.exists(account);
}


int Bank::getCode() const
{
	return this->code;
}

AccList Bank::getacclist()
{
	return this->acclist;
}

void Bank::setacclist(std::vector<Account> v)
{
	AccList acc = AccList();
	acc.setaccounts(v);
	this->acclist = acc;
}
std::ostream& operator<<(std::ostream& stream, const Bank& bank)
{
	return stream << bank.code << " " << bank.acclist;
}

std::istream& operator>>(std::istream& stream, Bank& bank)
{
	return stream >> bank.code >> bank.acclist;
}

void Bank::read(std::string filename)
{
	std::ifstream f(filename);
	std::string s = "";
	if (!f)
	{
		std::cout << "файл не найден\n";
		return;
	}
	std::vector <std::string> v;
	while (getline(f, s))
	{
		v.push_back(s);
	}
	f.close();
	int c = std::stoi(v[0]);
	this->code = c;
	for (int i = 1; i < v.size(); i++)
	{
		std::vector <std::string> s = split(v[i]);
		if (s.size() >= 5)
		{
			int num = std::stoi(s[0]);
			std::string ln = s[1];
			std::string n = s[2];
			std::string p = s[3];
			int bal = std::stoi(s[4]);
			Account b = Account(num, ln, n, p, bal);
			this->acclist.add(b);
		}
		else
		{
			std::cout << "запишите данные в формате пригодном для ситывания";
			break;
		}
	}
}

void Bank::save(std::string filename)
{
	std::ofstream f(filename);
	if (!f)
	{
		std::cout << "файл не найден\n";
		return;
	}
	f << this->code << " ";
	f << this->acclist;
	f.close();
}