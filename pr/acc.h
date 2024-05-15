#pragma once
#include <iostream>
#include <string>
#include "ex.h"


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
	~Account();
	void incresebal(double value);
	void decresebal(double value);
	void trans(Account& account, double value);
	friend std:: ostream& operator<<(std::ostream& os, const Account& account);
	friend std::istream& operator>>(std::istream& is, Account& account);
	int getnum() const;
	void setnum(int value);
	void setbal(double value);
};