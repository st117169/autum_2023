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
		this->mass = copy(a.mass);
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
		if (ind < 0 || ind >= this->n)
		{
			svector a = svector();
			return t();
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
	v.removeel(c);
	v.print();


}