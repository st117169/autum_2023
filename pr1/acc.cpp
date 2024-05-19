#include "acc.h"

Account::Account()
{
	this->num = 0;
	this->balance = 0.0;
}

Account::Account(int num, std::string lastName, std::string name, std::string patronimyc, double balance)
{
	this->num = num;
	this->lastname = lastName;
	this->name = name;
	this->patronimyc = patronimyc;
	this->balance = balance;
}

Account::Account(const Account& other)
{
	this->num = other.num;
	this->lastname = other.lastname;
	this->name = other.name;
	this->patronimyc = other.patronimyc;
	this->balance = other.balance;
}
Account::Account(Account&& acc) noexcept
{

	this->num = acc.num; acc.num = 0;
	this->lastname = acc.lastname; lastname = "";
	this->name = acc.name; acc.name = "";
	this->patronimyc = acc.patronimyc; acc.patronimyc = "";
	this->balance = acc.balance; acc.balance = 0;

}
Account::~Account()
{
	this->num = 0;
	this->lastname = "";
	this->patronimyc = "";
	this->name = "";
	this->balance = 0;
}


void Account::incresebal(double n)
{
	this->balance += n;
}

void Account::decresebal(double n)
{
	this->balance -= n;
}

void Account::trans(Account& acc, double n)
{
	if (this->balance < n)
	{
		std::cout << "недостаточн средств\n";
		return;
	}
	this->decresebal(n);
	acc.incresebal(n);
	std::cout << acc << std::endl;
}

int Account::getnum() const
{
	return this->num;
}

void Account::setnum(int n)
{
	this->num = n;
}

void Account::setbal(double n)
{
	this->balance = n;
}

std::ostream& operator<<(std::ostream& stream, const Account& acc)
{
	return stream << acc.num << " " << acc.lastname << " " << acc.name << " " << acc.patronimyc << " " << acc.balance;
}

std::istream& operator>>(std::istream& stream, Account& acc)
{
	return stream >> acc.num >> acc.lastname >> acc.name >> acc.patronimyc >> acc.balance;
}
