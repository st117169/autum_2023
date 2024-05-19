#include <iostream>

class vector
{
	int n= 0;
	int* mass = new int [n];
	

public:
	vector() {}

	vector(int* mass)
	{
		this->mass = mass;
	}
	vector(int n)
	{
		int* m = new int[n];
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
		int* m = new int[n + 1];
		for (int i = 0; i <= n; i++) 
		{
			m[i] = this->mass[i];
		}
		m[n] = a;
		this->mass = m;
		this->n += 1;
		delete[] m;
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
			std::cout << "введите нормальный индекс пж\n";
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
		int k = 0;
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
		this->mass = m;
		this->n -= 1;

		delete[] m;
	}

	void remove(int a)
	{
			int* m = new int[this->n];
			int i = 0;
			while (this->mass[i] != n)
			{
				if (this->mass[i] != a)
				{
					m[i] = mass[i];
					i++;
				}
				
			}
			this->mass = m;
			this->n -= 1;

			delete[] m;

	}

	
};

int main()
{

	int a = 0;
	std::cin << a;
	return 0;

}