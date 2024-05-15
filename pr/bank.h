#pragma once
#include "acclist.h"

class Bank {
	int code;
	AccList acclist;

public:
	Bank();
	Bank(int code); 
	Bank(const Bank& b);
	~Bank();
	Account create(int n, std::string lastname, std::string name, std::string patronimyc, double balance);
	void add(Account& account);
	void remove(const Account& account);
	bool exists(const Account& account) const;
	void trans(int fr, int to, double val);
	friend std::ostream& operator<<(std::ostream& stream, const Bank& bank);
	friend std::istream& operator>>(std::istream& is, Bank& bank);
	int getCode() const;
	AccList getacclist();
	static void read(std::string filename, Bank a);
	static void save(std::string filename, Bank a);
};
