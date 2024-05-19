#pragma once
#include "acclist.h"

class Bank {
	int code;
	AccList acclist;

public:
	Bank();
	Bank(int code);
	Bank(const Bank& b);
	Bank(Bank&& b) noexcept;
	~Bank();
	Account create(int n, std::string lastname, std::string name, std::string patronimyc, double balance);
	void add(Account& account);
	void remove(const Account& account);
	bool exists(const Account& account) const;
	friend std::ostream& operator<<(std::ostream& stream, const Bank& bank);
	friend std::istream& operator>>(std::istream& is, Bank& bank);
	Bank& operator=(const Bank& bank)
	{
		this->code = bank.code;
		this->acclist = bank.acclist;
		return *this;
	}
	int getCode() const;
	AccList getacclist();
	void setacclist(std::vector<Account> v);
	void read(std::string filename);
	void save(std::string filename);
};