#pragma once
#include <iostream>
#include <vector>
#include "acc.h"


class AccList {
	std::vector <Account> accounts;
	int getmaxnum();
	int indexof(const Account& acc) const;
public:
	AccList();
	AccList(const AccList& v);
	AccList(AccList&& v) noexcept;
	~AccList();
	void add(Account& acc);
	Account getfirst() const;
	Account getlast() const;
	Account& operator[](int ind);
	bool exists(const Account& acc) const;
	size_t getsize() const;
	Account get(int n);
	void setaccounts(std::vector<Account> v);
	Account search(int n);
	std::vector <Account> getaccounts();
	void remove(const Account& account);
	friend std::ostream& operator<<(std::ostream& stream, const AccList& acclist);
	friend std::istream& operator>>(std::istream& is, AccList& acclist);
	AccList& operator= (const AccList& acc)
	{
		this->accounts = acc.accounts;
		return *this;
	}
};
