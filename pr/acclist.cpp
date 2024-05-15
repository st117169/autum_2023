#include "acclist.h"

int AccList::getmaxnum()
{
	int max = 0;
	for (Account& account : this->accounts) 
	{
		if (account.getnum() > max) 
		{
			max = account.getnum();
		}
	}
	return max;
}

int AccList::indexof(const Account& acc) const
{
	for (int i = 0; i < this->accounts.size(); i++) 
	{
		if (this->accounts[i].getnum() == acc.getnum()) 
		{
			return i;
		}
	}
	return -1;
}

AccList::AccList() {}

AccList::AccList(const AccList& v)
{
	for (Account acc : v.accounts)
	{
		this->accounts.push_back(acc);
	}
}

AccList::~AccList()
{
	for (Account acc: this->accounts)
	{
		acc.~Account();
	}
}

void AccList::add(Account& acc)
{
	if (this->exists(acc)) 
	{
		std::cout << "Аккаунт уже существует\n";
		return;
	}
	int max = this->getmaxnum();
	acc.setnum(max + 1);
	this->accounts.push_back(acc);
}

Account AccList::getfirst() const
{
	if (this->accounts.size() == 0) 
	{
		std::cout<<"Список аккаунтов пуст\n";
		return Account();
	}
	return this->accounts[0];
}

Account AccList::getlast() const
{
	if (this->accounts.size() == 0) 
	{
		std::cout<< "Список аккаунтов пуст\n";
		return Account();
	}
	return this->accounts[this->accounts.size() - 1];
}

Account& AccList::operator[](int ind)
{
	if (ind < 0 || ind >= this->accounts.size()) 
	{
		std::cout << "Индекс вне границ списка аккаунтов\n";
		Account a = Account();
		return a;
	}
	return this->accounts[ind];
}

bool AccList::exists(const Account& account) const
{
	for (Account acc : this->accounts) 
	{
		if (acc.getnum() == account.getnum()) 
		{
			return true;
		}
	}
	return false;
}

size_t AccList::getsize() const
{
	return this->accounts.size();
}

Account AccList::get(int n)
{
	for (Account& acc : this->accounts) {
		if (acc.getnum() == n) {
			return acc;
		}
	}
	throw AccountNotFoundException("Аккаунт с таким номером не найден");
}

void AccList::remove(const Account& acc)
{
	int ind = this->indexof(acc);
	if (ind == -1) 
	{
		throw IllegalArgumentException("Аккаунт не найден");
	}
	this->accounts.erase(this->accounts.begin() + ind);
}

Account AccList::search(int n)
{
	for (Account acc : accounts)
	{
		if (acc.getnum() == n)
		{
			return acc;
		}
	}
	return Account();
}

std::vector <Account> AccList:: getaccounts()
{
	std::vector <Account> getaccounts;
	for (Account acc : this->accounts)
	{
		getaccounts.push_back (acc);
	}
	return getaccounts;
}
std::ostream& operator<<(std::ostream& stream, const AccList& accountList)
{
	for (const Account& acc : accountList.accounts) {
		stream << acc << std::endl;
	}
	return stream;
}

std::istream& operator>>(std::istream& is, AccList& acclist)
{
	Account acc;
	while (is >> acc)
	{
		acclist.add(acc);
	}
	return is;
}