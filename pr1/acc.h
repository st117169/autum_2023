
#pragma once
#include <iostream>
#include <string>

class Account {

	int num;
	std::string lastname;
	std::string name;
	std::string patronimyc;
	double balance;

public:
	Account();
	Account(int num, std::string lastName, std::string name, std::string patronimyc, double balance);
	Account(const Account& other);
	Account(Account&& acc) noexcept;
	~Account();
	void incresebal(double value);
	void decresebal(double value);
	void trans(Account& account, double value);
	friend std::ostream& operator<<(std::ostream& os, const Account& account);
	friend std::istream& operator>>(std::istream& is, Account& account);
	Account& operator=(const Account& acc)
	{
		this->num = acc.num;
		this->lastname = acc.lastname;
		this->name = acc.name;
		this->patronimyc = acc.patronimyc;
		this->balance = acc.balance;
		return *this;
	}
	bool operator== (const Account& a)
	{
		return (this->num == a.num && this->lastname == a.lastname && this->name == a.name && this->patronimyc == a.patronimyc && this->balance == a.balance);
	}
	int getnum() const;
	void setnum(int value);
	void setbal(double value);
};
