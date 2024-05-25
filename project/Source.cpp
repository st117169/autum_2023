#include <iostream>
#include<fstream>
#include <string>


#include <iostream>


template <typename t>
class svector
{
	int n = 0;
	t* mass;

public:
	svector()
	{}

	svector(int n1)
	{
		this->n = n1;
		this->k = n;
	}

	svector(const svector& a) : mass(nullptr), n(0)
	{
		this->mass = new t[a.n];
		for (int i = 0; i < a.n; i++)
		{
			this->mass[i] = a.mass[i];
		}
		this->n = a.n;
	}

	svector(svector&& a) noexcept
	{
		this->n = a.n;
		this->mass = a.mass;
		delete[] a.mass;
		a.n = 0;
	}

	~svector()
	{
		this->mass = new t[0];
		delete[] this->mass;
	}

	void push_back(t a)
	{
		t* m = new t[this->n + 1];
		if (this->mass != nullptr)
		{
			for (int i = 0; i < this->n; ++i)
			{
				m[i] = this->mass[i];
			}
			delete[] this->mass;
		}
		this->mass = m;
		++n;
		this->mass[n - 1] = a;
	}

	int indexof(t a)
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

	t* getmass()
	{
		return this->mass;
	}

	t operator[](int ind) const
	{
		return this->mass[ind];
	}

	svector& operator= (svector a)
	{
		this->n = a.n;
		this->mass = new t[n];
		for (int i = 0; i < a.n; i++)
		{
			this->mass[i] = a.mass[i];
		}
		return *this;
	}

	void removeind(int ind)
	{

		if (ind >= this->n)
		{
			return;
		}
		t* m = new t[this->n - 1];
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
		delete[] this->mass;
		this->n -= 1;
		this->mass = m;
	}

	void removeel(t a)
	{
		t* m = new t[this->n - 1];
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
		delete[] this->mass;
		this->n -= 1;
		this->mass = new t[this->n];
		this->mass = m;
	}

	void print()
	{
		for (int i = 0; i < this->n; i++) {
			std::cout << this->mass[i] << " ";
		}
		std::cout << std::endl;
	}

	bool exists(const t& account) const
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

	t get(int n)
	{
		for (int i = 0; i < this->n; i++) {
			if (this->mass[i].getnum() == n) {
				return this->mass[i];
			}
		}
		std::cout << "аккаунт не найден\n";
	}

	t search(int n)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i].getnum() == n)
			{
				return this->mass[i];
			}
		}
	}

	svector getaccounts()
	{
		svector getaccounts;
		for (int i = 0; i < this->n; i++)
		{
			getaccounts.push_back(this->mass[i]);
		}
		return getaccounts;
	}

	void setind(t acc, int ind)
	{
		this->mass[ind] = acc;
	}

	friend std::ostream& operator<<(std::ostream& stream, const svector& v)
	{
		for (int i = 0; i < v.n; i++)
		{
			stream << v.mass[i] << std::endl;
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, svector& v)
	{
		t acc;
		while (stream >> acc)
		{
			v.push_back(acc);
		}
		return stream;
	}

};

svector <std::string> split(std::string s)
{
	svector < std::string > v;
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
	int balance;

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
			std::cout << "недостаточн средств\n";
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


class Bank {
	int code = 0;
	svector <Account> acclist;

public:

	Bank()
	{ }

	Bank(int code)
	{
		this->code = code;
		acclist = svector <Account>();
	}

	Bank(int code, svector<Account> acc)
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
		bank.acclist.~svector <Account>();
	}


	~Bank()
	{
		this->acclist.~svector <Account>();
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

	svector<Account> getaccv()
	{
		return this->acclist;
	}

	void setacclist(svector<Account> v)
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
			std::cout << "файл не найден\n";
			return;
		}
		svector<std::string> v;
		while (getline(f, s))
		{
			v.push_back(s);
		}
		f.close();
		int c = std::stoi(v[0]);
		this->code = c;
		for (int i = 1; i < v.getsize(); i++)
		{
			svector<std::string> s = split(v[i]);
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
				std::cout << "запишите данные в формате пригодном для ситывания";
				break;
			}
		}
	}

	void save(std::string filename)
	{
		std::ofstream f(filename);
		if (!f)
		{
			std::cout << "файл не найден\n";
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
	std::cout << "1 - создать новый банк\n2 - загрузить банк из файла\n";
	int n;
	Bank r = Bank();
	std::cin >> n;
	if (n == 1)
	{
		int code; std::cout << "Введите код банка\n"; std::cin >> code;
		int n; std::cout << "Введите количество аккаунтов\n"; std::cin >> n;
		r = Bank(code);
		svector<Account> a = svector<Account>();
		for (int i = 0; i < n; i++)
		{
			std::cout << "Введите данные аккаунта, который хотите добавить\n";
			std::cout << "Введите номер аккаунта\n";
			int num;
			std::cin >> num;

			std::string ln;
			std::cout << "Введите фамилию владельца\n";
			std::cin >> ln;

			std::cout << "Введите имя владельца\n";
			std::string name;
			std::cin >> name;

			std::string patronimyc;
			std::cout << "Введите отчество владельца\n";
			std::cin >> patronimyc;

			double balance = 0;
			std::cout << "Введите баланс\n";
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
		std::cout << "Введите имя файла для чтения из файла\n";
		std::cin >> filename;
		r.read(filename);
		std::cout << "Загруженный банк\n";
		std::cout << r;
	}
	else
	{
		std::cout << "Вы выбрали неизвестную операцию\n";
		return 1;
	}

	while (true)
	{
		std::cout << "0 - выход из системы\n3 - Сохранить банк в файл\n4 - Добавить новый аккаун\n"
			<< "5 - удалить аккаунт\n6 - проверить, существует ли аккаунт в банке\n7 - перевод суммы между счетами\n"
			<< "8 - вывести код банка\n9 - положить деньги на аккаунт\n10 - снять деньги с аккаунта";
		std::cin >> n;
		if (n == 0)
		{
			return 0;
		}
		else if (n == 3)
		{
			std::string filename;
			std::cout << "Введите название файла\n";
			std::cin >> filename;
			r.save(filename);
			std::cout << "Банк сохранен\n";
		}
		else if (n == 4)
		{
			std::cout << "Введите данные аккаунта\n";
			std::cout << "Введите номер аккаунта\n";
			int num;
			std::cin >> num;
			svector<Account> v = r.getaccv();
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
				std::cout << "Введите фамилию владельца\n";
				std::cin >> ln;

				std::cout << "Введите имя владельца\n";
				std::string name;
				std::cin >> name;

				std::string patronimyc;
				std::cout << "Введите отчество владельца\n";
				std::cin >> patronimyc;

				double balance = 0;
				Account acc(num, ln, name, patronimyc, balance);
				r.add(acc);
				std::cout << "Аккаунт успешно добавлен\n";

				std::cout << r << std::endl;
				acc.~Account();
			}
			else
			{
				std::cout << "Аккаунт с таким номером уже существует\n";
			}
		}

		else if (n == 5)
		{
			std::cout << "Введите номер аккаунта\n";
			int a = 0;
			std::cin >> a;
			svector<Account> v = r.getaccv();
			Account acc = v.get(a);
			r.remove(acc);
			std::cout << r << std::endl;
			acc.~Account();
			v.~svector<Account>();
		}

		else if (n == 6)
		{
			std::cout << "Введите номер аккаунта\n";
			int a = 0;
			std::cin >> a;
			svector<Account> v = r.getaccv();
			Account acc = v.search(a);
			if (r.exists(acc) == 1)
			{
				std::cout << "Аккаунт найден\n";
			}
			else
			{
				std::cout << "Аккаунт не найден\n";
			}
			acc.~Account();
			v.~svector <Account>();
		}

		else if (n == 7)
		{
			int a = 0;
			std::cout << "Введите номер аккаунта откуда осуществляется перевод\n";
			std::cin >> a;
			int b = 0;
			std::cout << "Введите номер аккаунта куда осуществляется перевод\n";
			std::cin >> b;
			int n = 0;
			std::cout << "Введите сумму перевода\n";
			std::cin >> n;
			svector<Account> v = r.getaccv();
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
				std::cout << "одоного из аккаунтов не существует\n";
			}

			std::cout << r << std::endl;
			v.~svector <Account>();

		}

		else if (n == 8)
		{
			std::cout << r.getCode() << std::endl;
		}

		else if (n == 9)
		{
			int a = 0;
			std::cout << "введите номер аккаунта откуда осуществляется перевод\n";
			std::cin >> a;
			int val = 0;
			std::cout << "Введите сумму перевода\n";
			std::cin >> val;
			svector <Account> v = svector <Account>();
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
				std::cout << "одоного из аккаунтов не существует\n";
			}
			if (k > 0)
			{
				Account aacc = v.search(a);
				int ind = v.indexof(aacc);
				Account ac = v[ind].incresebal(val);
				v.setind(ac, ind);
				r.setacclist(v);
				std::cout << r << std::endl;
				aacc.~Account();
				ac.~Account();
			}
			v.~svector <Account>();
		}
		else if (n == 10)
		{
			int a = 0;
			std::cout << "введите номер аккаунта откуда осуществляется перевод\n";
			std::cin >> a;
			int val = 0;
			std::cout << "Введите сумму перевода\n";
			std::cin >> val;
			svector<Account> v = r.getaccv();
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
				std::cout << "одоного из аккаунтов не существует\n";
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
