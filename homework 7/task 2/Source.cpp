#include <iostream>
#include <fstream>
#include <string>

std::string tmpw(std::string * j, int len)
{
	int max_ind = 0;
	for (int i = 0; i < len; i++) {

		int n = 0;
		for (int i = 0; i < j.size(); i++)
		{
			if (j[i] == ' ')
			{
				n++;
			}
		}
		n++;
		std::string* s = new std::string[n]{ "" };
		int h = 0;
		for (int i = 0; i < j.size(); i++)
		{
			if ((j[i] <= 'z' && j[i] >= 'a') || (j[i] <= 'Z' && j[i] >= 'A'))
			{
				s[h] += j[i];
			}
			else
			{
				h++;
			}
		}
		int max_ind_ = 0;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			int k = 0;
			for (int h = i; h < n; h++)
			{
				if (s[i] == s[h])
				{
					k++;
				}
			}
			if (k > max)
			{
				max_ind = i;
				max = k;
			}
		}
	}
	
	return s[max_ind];
}




int main()
{
	std::ifstream f ("input.txt");
	int len = 0;
	std::string l = "";
	if (f) {
		while (!f.eof())
		{
			std::string j = "";
			getline(f, j);
			len++;
			l += j;
			l += '|';

		}

	}
	std::cout << len;
	int h = 0;
	std::string* j = new std::string[len]{ "" };
	for (int i = 0; i < len; i++)
	{
		while (l[h] != '|')
		{
			j[i] += l[h];
			h++;
		}
		h++;
	}
	std::string s = tmpw(j);
	f.close();

	std::ofstream k("output.txt");
	k << s;
	k.close();

	return	EXIT_SUCCESS;
	
}