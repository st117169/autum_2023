#include "bank.h"
#include <iostream>
#include <fstream>

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
	this->acclist = AccList(b.acclist);
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

void Bank::trans(int fr, int to, double val)
{
	Account accfr = this->acclist.get(fr);
	Account accto = this->acclist.get(to);
	accfr.trans(accto, val);
}

int Bank::getCode() const 
{
	return this->code;
}

AccList Bank:: getacclist()
{
	return this->acclist;
}
std::ostream& operator<<(std::ostream& stream, const Bank& bank) 
{
	return stream << bank.code << " " << bank.acclist;
}

std::istream& operator>>(std::istream& stream, Bank& bank) 
{
	return stream >> bank.code >> bank.acclist;
}

void Bank::read(std::string filename, Bank a)
{
	std::ifstream f(filename);
	if (!f) {
		std::cout << "Файл не существует\n";
		return;
	}
	f >> a;
	f.close();
}

void Bank::save(std::string filename, Bank a)
{
	std::ofstream f(filename);
	if (!f) {
		std::cout<< "Невозможно создать файл\n";
		return;
	}
	f << a;
	f.close();
}
