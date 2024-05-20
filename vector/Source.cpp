#include <iostream>


class vector
{
	int n = 0;
	int* mass = new int[n];


public:
	vector() {}

	vector(int* mass)
	{
		this->mass = mass;
	}
	vector(int n1)
	{
		this->n = n1;
		this->mass = new int[n];
		int* m = new int[n1];
		for (int i = 0; i < n1; i++) {
			m[i] = 0;
		}
		this->mass = m;
	}

	vector(const vector& a)
	{
		this->mass = a.mass;
	}

	vector(vector&& a) noexcept
	{
		this->mass = a.mass;
		delete[] a.mass;
	}

	~vector()
	{
		delete[] this->mass;
	}

	void push_back(int a)
	{
		int* m = new int[this->n + 1];
		for (int i = 0; i < this->n; i++)
		{
			m[i] = this->mass[i];
		}
		m[this->n] = a;
		this->mass = new int[this->n + 1];
		this->mass = m; this->n += 1;

	}
	int indexof(int a)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (this->mass[i] = a)
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
	int* getmass()
	{
		return mass;
	}

	int operator[](int ind)
	{
		if (ind < 0 || ind >= this->n)
		{
			vector a = vector();
			return -1;
		}
		return this->mass[ind];
	}

	void operator= (vector a)
	{
		this->mass = a.getmass();
	}

	void remove1(int ind)
	{
		int* m = new int[this->n - 1];
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
		this->mass = new int[this->n];
		this->mass = m;
	}

	void remove(int a)
	{
		int* m = new int[this->n - 1];
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
		this->mass = new int[this->n];
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
	vector v = vector();
	for (int i = 0; i < a; i++)
	{
		int h; std::cin >> h;
		v.push_back(h);
	}
	v.print();
	int b; std::cin >> b;
	v.remove1(b);
	v.print();
	int c; std::cin >> c;
	v.remove(c);
	v.print();
}