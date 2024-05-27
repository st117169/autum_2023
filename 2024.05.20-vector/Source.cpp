#include <iostream>


template <typename t>
class svector
{
	int n = 0;
	t* mass = new t[0];

public:
	svector()
	{}

	svector(int n1)
	{
		this->n = n1;
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
		dispose();
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
	void dispose()
	{
		if (this->mass != nullptr)
		{
			delete[] this->mass;
		}
		this->mass = nullptr;
		this->n = 0;
	}
	svector& operator= (svector a)
	{
		dispose();
		this->n = a.n;
		this->mass = new t[n];
		for (int i = 0; i < n; i++)
		{
			this->mass = a.mass;
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

	void removeelement(t a)
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

	void setind(t acc, int ind)
	{
		this->mass[ind] = acc;
	}

	void print()
	{
		for (int i = 0; i < this->n; i++) {
			std::cout << this->mass[i] << " ";
		}
		std::cout << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& stream, const svector <t>& v)
	{
		for (int i = 0; i < v.getsize(); i++)
		{
			stream << v[i] << std::endl;
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, svector <t>& v)
	{
		t acc;
		while (stream >> acc)
		{
			v.push_back(acc);
		}
		return stream;
	}


};





int main()
{
	int a;
	std::cin >> a;
	svector<std::string> v = svector <std::string>();
	for (int i = 0; i < a; i++)
	{
		std::string h; std::cin >> h;
		v.push_back(h);

	}
	v[2] = v[1];
	v.print();
	int b; std::cin >> b;
	v.removeind(b);
	v.print();
	std::string c; std::cin >> c;
	v.removeelement(c);
	v.print();


}