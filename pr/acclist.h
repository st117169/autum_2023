#pragma once

#pragma once
#include <iostream>
#include <vector>
#include "acc.h"
#include "ex.h"

class AccList {
	std::vector <Account> accounts;
	int getmaxnum();
	int indexof(const Account& acc) const;
public:
	AccList();
	AccList(const AccList& v);
	~AccList();
	void add(Account& acc);
	Account getfirst() const;
	Account getlast() const;
	Account& operator[](int ind);
	bool exists(const Account& acc) const;
	size_t getsize() const;
	Account get(int n);
	Account search(int n);
	std::vector <Account> getaccounts();
	void remove (const Account& account);
	friend std::ostream& operator<<(std::ostream& stream, const AccList& acclist);
	friend std::istream& operator>>(std::istream& is, AccList& acclist);
	
};