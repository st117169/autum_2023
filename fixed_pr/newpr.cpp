#include <iostream>
#include <fstream>
#include <string>

class svector {

	int n;
	std::string* mass;

public:
	svector()
	{ }
	svector(int n1)
	{
		this->n = n1;
		this->mass = new std::string[n];
		std::string* m = new std::string[n1];
		for (int i = 0; i < n1; i++) {
			m[i] = "0";
		}
		this->mass = m;

		m = new std::string[0];
		delete[] m;
	}

	svector(const svector& a)
	{
		this->n = a.n;
		this->mass = a.mass;
	}

	svector(svector&& a) noexcept
	{
		this->mass = a.mass;
		delete[] a.mass;
	}

	~svector()
	{
		delete[] this->mass;
	}

	void push_back(std::string a)
	{
		std::string* m = new std::string[this->n + 1];
		for (int i = 0; i < this->n; i++)
		{
			m[i] = this->mass[i];
		}
		m[this->n] = a;
		this->mass = new std::string[this->n + 1];
		this->mass = m;
		this->n += 1;
		m = new std::string[0];
		delete[] m;

	}
	int indexof(std::string a)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i] == a)
			{
				return i;
			}
		}
		return -1;
	}

	int getsize()
	{
		return n;
	}

	std::string* getmass()
	{
		return this->mass;
	}

	std::string operator[](int ind)
	{
		if (ind < 0 || ind >= this->n)
		{
			svector a = svector();
			return std::string();
		}
		return this->mass[ind];
	}

	svector& operator= (svector a)
	{
		this->n = a.n;
		this->mass = a.getmass();
		return *this;
	}

	void removeind(int ind)
	{
		std::string* m = new std::string[this->n - 1];
		for (int i = 0; i < n; i++)
		{
			if (i < ind)
			{
				m[i] = this->mass[i];
			}
			if (i > ind)
			{
				m[i - 1] = this->mass[i];
			}
		}
		this->n -= 1;
		this->mass = new std::string[this->n];
		this->mass = m;

		m = new std::string[0];
		delete[] m;
	}
	void removeel(std::string a)
	{
		std::string* m = new std::string[this->n - 1];
		int k = -1;
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i] == a)
			{
				k = i;
			}
		}
		if (k == -1)
		{
			return;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (i < k)
				{
					m[i] = this->mass[i];
				}
				if (i > k)
				{
					m[i - 1] = this->mass[i];
				}
			}
		}
		this->n -= 1;
		this->mass = new std::string[this->n];
		this->mass = m;

		m = new std::string[0];
		delete[] m;
	}

	void print()
	{
		for (int i = 0; i < this->n; i++) {
			std::cout << this->mass[i] << " ";
		}
		std::cout << std::endl;
	}
};


svector split(std::string s)
{
	svector v;
	std::string k = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			k += s[i];
		}
		else if (s[i] == ' ')
		{
			v.push_back(k);
			k = "";
		}
	}
	v.push_back(k);
	return v;
}

class Account {

	int num;
	std::string lastname;
	std::string name;
	std::string patronimyc;
	double balance;

public:

	Account()
	{
		this->num = 0;
		this->balance = 0.0;
	}

	Account(int num, std::string lastName, std::string name, std::string patronimyc, double balance)
	{
		this->num = num;
		this->lastname = lastName;
		this->name = name;
		this->patronimyc = patronimyc;
		this->balance = balance;
	}

	Account(const Account& other)
	{
		this->num = other.num;
		this->lastname = other.lastname;
		this->name = other.name;
		this->patronimyc = other.patronimyc;
		this->balance = other.balance;
	}
	Account(Account&& acc) noexcept
	{

		this->num = acc.num; acc.num = 0;
		this->lastname = acc.lastname; lastname = "";
		this->name = acc.name; acc.name = "";
		this->patronimyc = acc.patronimyc; acc.patronimyc = "";
		this->balance = acc.balance; acc.balance = 0;

	}
	~Account()
	{
		this->lastname = "";
		this->patronimyc = "";
		this->name = "";
		this->balance = 0;
	}


	Account incresebal(double n)
	{
		 int b = this->balance + n;
		 Account a = Account(this->num, this->lastname, this->name, this->patronimyc, b);
		 return a;
	}

	Account decresebal(double n)
	{
		int b = this->balance - n;
		Account a = Account(this->num, this->lastname, this->name, this->patronimyc, b);
		return a;
	}

	void trans(Account& acc, double n)
	{
		if (this->balance < n)
		{
			std::cout << "����������� �������\n";
			return;
		}
		Account a = this->decresebal(n);
		Account b = acc.incresebal(n);
		*this = a;
		acc = b;
	}

	int getnum() const
	{
		return this->num;
	}
	int getbal() const
	{
		return this->balance;
	}

	void setnum(int n)
	{
		this->num = n;
	}

	void setbal(double n)
	{
		this->balance = n;
	}

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

	friend std::ostream& operator<<(std::ostream& stream, const Account& acc)
	{
		return stream << acc.num << " " << acc.lastname << " " << acc.name << " " << acc.patronimyc << " " << acc.balance;
	}

	friend std::istream& operator>>(std::istream& stream, Account& acc)
	{
		return stream >> acc.num >> acc.lastname >> acc.name >> acc.patronimyc >> acc.balance;
	}
};


class accvector
{	
	int n;
	Account* mass;
	
public:
	accvector()
	{}

	accvector(int n1)
	{
		this->n = n1;
		this->mass = new Account[n];
		Account* m = new Account[n1];
		for (int i = 0; i < n1; i++) {
			m[i] = Account();
		}
		this->mass = m;

		m = new Account[0];
		delete[] m;
	}

	accvector(const accvector& a)
	{
		this->n = a.n;
		this->mass = a.mass;
	}

	accvector(accvector&& a) noexcept
	{
		this->mass = a.mass;
		delete[] a.mass;
	}

	~accvector()
	{
		this->mass = new Account[0];
		delete[] this->mass;
	}

	void push_back(Account a)
	{
		int n1 = this->n + 1;
		Account* m = new Account[n1];
		if (this->n != 0)
		{
			for (int i = 0; i < this->n; i++)
			{
				m[i] = this->mass[i];
			}
		}
		m[this->n] = a;
		this->mass = new Account[n1];
		this->mass = m;
		this->n += 1;
		m = new Account[0];
		delete[] m;

	}
	int indexof(Account a)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i] == a)
			{
				return i;
			}
		}
		return -1;
	}

	int getsize() const
	{
		return n;
	}

	Account* getmass()
	{
		return this->mass;
	}

	Account operator[](int ind) const
	{
		if (ind < 0 || ind >= this->n)
		{
			accvector a = accvector();
			return Account();
		}
		return this->mass[ind];
	}

	accvector& operator= (accvector a)
	{
		this->n = a.n;
		this->mass = a.getmass();
		return *this;
	}

	void removeind(int ind)
	{

		if (ind >= this->n)
		{
			return;
		}
		Account* m = new Account[this->n - 1];
		for (int i = 0; i < n; i++)
		{
			if (i < ind)
			{
				m[i] = this->mass[i];
			}
			if (i > ind)
			{
				m[i - 1] = this->mass[i];
			}
		}
		this->n -= 1;
		this->mass = new Account[this->n];
		this->mass = m;
		m = new Account[0];
		delete[] m;
	}

	void removeel(Account a)
	{
		Account* m = new Account[this->n - 1];
		int k = -1;
		if (k >= this->n)
		{
			return;
		}
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i] == a)
			{
				k = i;
			}
		}
		if (k == -1)
		{
			return;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (i < k)
				{
					m[i] = this->mass[i];
				}
				if (i > k)
				{
					m[i - 1] = this->mass[i];
				}
			}
		}
		this->n -= 1;
		this->mass = new Account[this->n];
		this->mass = m;

		m = new Account[0];
		delete[] m;
	}

	void print()
	{
		for (int i = 0; i < this->n; i++) {
			std::cout << this->mass[i] << " ";
		}
		std::cout << std::endl;
	}

	bool exists(const Account& account) const
	{
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i].getnum() == account.getnum())
			{
				return true;
			}
		}
		return false;
	}

	Account get(int n)
	{
		for (int i = 0; i < this->n; i++) {
			if (this->mass[i].getnum() == n) {
				return this->mass[i];
			}
		}
		std::cout << "������� �� ������\n";
	}

	Account search(int n)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i].getnum() == n)
			{
				return this->mass[i];
			}
		}

		return Account();
	}

	accvector getaccounts()
	{
		accvector getaccounts;
		for (int i = 0; i < this->n; i++)
		{
			getaccounts.push_back(this->mass[i]);
		}
		return getaccounts;
	}

	void setind(Account acc, int ind)
	{
		this->mass[ind] = acc;
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const accvector& v)
	{
		for (int i = 0; i < v.n; i++)
		{
			stream << v.mass[i] << std::endl;
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, accvector& v)
	{
		Account acc;
		while (stream >> acc)
		{
			v.push_back(acc);
		}
		return stream;
	}
};

class Bank {
	int code = 0;
	accvector acclist = accvector();

public:
	Bank()
	{ }

	Bank(int code)
	{
		this->code = code;
	}

	Bank(int code, accvector acc)
	{
		this->code = code;
	}

	Bank(const Bank& b)
	{
		this->code = b.code;
		this->acclist = b.acclist;
	}

	Bank(Bank&& bank) noexcept
	{
		this->code = bank.code;
		this->acclist = bank.acclist;
		bank.code = 0;
		bank.acclist.~accvector();
	}


	~Bank()
	{
		this->acclist.~accvector();
		code = 0;
	}

	Account create(int n, std::string lastname, std::string name, std::string patronimyc, double balance)
	{
		return Account(n, lastname, name, patronimyc, balance);
	}

	void add(Account& account)
	{
		this->acclist.push_back(account);
	}

	void remove(const Account& acc)
	{
		this->acclist.removeel(acc);
	}

	bool exists(const Account& account) const
	{
		return this->acclist.exists(account);
	}

	int getCode() const
	{
		return this->code;
	}

	accvector getaccv()
	{
		return this->acclist;
	}

	void setacclist(accvector v)
	{
		this->acclist = v;

	}

	Bank& operator=(const Bank& bank)
	{
		this->code = bank.code;
		this->acclist = bank.acclist;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Bank& bank)
	{
		return stream << bank.code << " " << bank.acclist;
	}

	friend std::istream& operator>>(std::istream& stream, Bank& bank)
	{
		return stream >> bank.code >> bank.acclist;
	}

	void read(std::string filename)
	{
		std::ifstream f(filename);
		std::string s = "";
		if (!f)
		{
			std::cout << "���� �� ������\n";
			return;
		}
		svector v;
		while (getline(f, s))
		{
			v.push_back(s);
		}
		f.close();
		int c = std::stoi(v[0]);
		this->code = c;
		for (int i = 1; i < v.getsize(); i++)
		{
			svector s = split(v[i]);
			if (s.getsize() >= 5)
			{
				int num = std::stoi(s[0]);
				std::string ln = s[1];
				std::string n = s[2];
				std::string p = s[3];
				int bal = std::stoi(s[4]);
				Account b = Account(num, ln, n, p, bal);
				this->acclist.push_back(b);
			}
			else
			{
				std::cout << "�������� ������ � ������� ��������� ��� ���������";
				break;
			}
		}
	}

	void save(std::string filename)
	{
		std::ofstream f(filename);
		if (!f)
		{
			std::cout << "���� �� ������\n";
			return;
		}
		f << this->code << " ";
		f << this->acclist;
		f.close();
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	std::cout << "1 - ������� ����� ����\n2 - ��������� ���� �� �����\n";
	int n;
	Bank r = Bank();
	std::cin >> n;
	if (n == 1)
	{
		int code; std::cout << "������� ��� �����\n"; std::cin >> code;
		int n; std::cout << "������� ���������� ���������\n"; std::cin >> n;
		r = Bank(code);
		accvector a = accvector();
		for (int i = 0; i < n; i++)
		{
			std::cout << "������� ������ ��������, ������� ������ ��������\n";
			std::cout << "������� ����� ��������\n";
			int num;
			std::cin >> num;

			std::string ln;
			std::cout << "������� ������� ���������\n";
			std::cin >> ln;

			std::cout << "������� ��� ���������\n";
			std::string name;
			std::cin >> name;

			std::string patronimyc;
			std::cout << "������� �������� ���������\n";
			std::cin >> patronimyc;

			double balance = 0;
			std::cout << "������� ������\n";
			std::cin >> balance;
			Account acc(num, ln, name, patronimyc, balance);
			a.push_back(acc);
		}
		r.setacclist(a);
		std::cout << r << std::endl;
	}
	else if (n == 2)
	{
		std::string filename;
		std::cout << "������� ��� ����� ��� ������ �� �����\n";
		std::cin >> filename;
		r.read(filename);
		std::cout << "����������� ����\n";
		std::cout << r;
	}
	else
	{
		std::cout << "�� ������� ����������� ��������\n";
		return 1;
	}

	while (true)
	{
		std::cout << "0 - ����� �� �������\n3 - ��������� ���� � ����\n4 - �������� ����� ������\n"
			<< "5 - ������� �������\n6 - ���������, ���������� �� ������� � �����\n7 - ������� ����� ����� �������\n"
			<< "8 - ������� ��� �����\n9 - �������� ������ �� �������\n10 - ����� ������ � ��������";
		std::cin >> n;
		if (n == 0)
		{
			return 0;
		}
		else if (n == 3)
		{
			std::string filename;
			std::cout << "������� �������� �����\n";
			std::cin >> filename;
			r.save(filename);
			std::cout << "���� ��������\n";
		}
		else if (n == 4)
		{
			std::cout << "������� ������ ��������\n";
			std::cout << "������� ����� ��������\n";
			int num;
			std::cin >> num;
			accvector v = r.getaccv();
			int k = 0;
			for (int i = 0; i < v.getsize(); i++)
			{
				if (v[i].getnum() == num)
				{
					k++;
				}
			}
			if (k == 0) {
				std::string ln;
				std::cout << "������� ������� ���������\n";
				std::cin >> ln;

				std::cout << "������� ��� ���������\n";
				std::string name;
				std::cin >> name;

				std::string patronimyc;
				std::cout << "������� �������� ���������\n";
				std::cin >> patronimyc;

				double balance = 0;
				Account acc(num, ln, name, patronimyc, balance);
				r.add(acc);
				std::cout << "������� ������� ��������\n";

				std::cout << r << std::endl;
				acc.~Account();
			}
			else
			{
				std::cout << "������� � ����� ������� ��� ����������\n";
			}
		}

		else if (n == 5)
		{
			std::cout << "������� ����� ��������\n";
			int a = 0;
			std::cin >> a;
			accvector v = r.getaccv();
			Account acc = v.get(a);
			r.remove(acc);
			std::cout << r << std::endl;
			acc.~Account();
			v.~accvector();
		}

		else if (n == 6)
		{
			std::cout << "������� ����� ��������\n";
			int a = 0;
			std::cin >> a;
			accvector v = r.getaccv();
			Account acc = v.search(a);
			if (r.exists(acc) == 1)
			{
				std::cout << "������� ������\n";
			}
			else
			{
				std::cout << "������� �� ������\n";
			}
			acc.~Account();
			v.~accvector();
		}

		else if (n == 7)
		{
			int a = 0;
			std::cout << "������� ����� �������� ������ �������������� �������\n";
			std::cin >> a;
			int b = 0;
			std::cout << "������� ����� �������� ���� �������������� �������\n";
			std::cin >> b;
			int n = 0;
			std::cout << "������� ����� ��������\n";
			std::cin >> n;
			accvector v = r.getaccv();
			int k = 0; int u = 0;
			for (int i = 0; i < v.getsize(); i++)
			{
				if (v[i].getnum() == a)
				{
					k += 1;
				}
			}
			for (int i = 0; i < v.getsize(); i++)
			{
				if (v[i].getnum() == b)
				{
					u += 1;
				}
			}
			if (k > 0 && u > 0)
			{
				Account aacc = v.search(a);
				int inda = v.indexof(aacc);
				Account bacc = v.search(b);
				int indb = v.indexof(bacc);
				aacc.trans(bacc, n);
				v.setind(aacc, inda);
				v.setind(bacc, indb);

				aacc.~Account();
				bacc.~Account();
				r.setacclist(v);
			}
			if (k == 0 || u == 0)
			{
				std::cout << "������� �� ��������� �� ����������\n";
			}
			
			std::cout << r << std::endl;
			v.~accvector();

		}

		else if (n == 8)
		{
			std::cout << r.getCode() << std::endl;
		}

		else if (n == 9)
		{
			int a = 0;
			std::cout << "������� ����� �������� ������ �������������� �������\n";
			std::cin >> a;
			int val = 0;
			std::cout << "������� ����� ��������\n";
			std::cin >> val;
			accvector v = accvector();
			v = r.getaccv();
			int k = 0;
			for (int i = 0; i < v.getsize(); i++)
			{
				if (v[i].getnum() == a)
				{
					k += 1;
				}
			}
			if (k == 0)
			{
				std::cout << "������� �� ��������� �� ����������\n";
			}
			if (k > 0)
			{
				Account aacc = v.search(a);
				int ind = v.indexof(aacc);
				Account ac = v[ind].incresebal(val);
				v.setind (ac, ind);
				r.setacclist(v);
				std::cout << r << std::endl;
				aacc.~Account();
				ac.~Account();
			}
			v.~accvector();
		}
		else if (n == 10)
		{
			int a = 0;
			std::cout << "������� ����� �������� ������ �������������� �������\n";
			std::cin >> a;
			int val = 0;
			std::cout << "������� ����� ��������\n";
			std::cin >> val;
			accvector v = r.getaccv();
			int k = 0;
			for (int i = 0; i < v.getsize(); i++)
			{
				if (v[i].getnum() == a)
				{
					k += 1;
				}
			}
			if (k == 0)
			{
				std::cout << "������� �� ��������� �� ����������\n";
			}
			if (k > 0)
			{
				Account aacc = v.search(a);
				int ind = v.indexof(aacc);
				Account ac = v[ind].decresebal(val);
				v.setind(ac, ind);
				r.setacclist(v);
				std::cout << r << std::endl;
				aacc.~Account();
				ac.~Account();
			}
			
		}
	}

	return 0;


}