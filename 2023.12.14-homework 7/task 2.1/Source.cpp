#include <iostream>
#include <fstream>
#include <string>

std::string pal(std::string s)
{
	int len = s.size();
	std::string s1 = "";
	std::string s2 = "";
	for (int i = 0; i < (len / 2); i++)
	{
		s1 += s[i];
	}
	for (int i = len - 1; i >= len - (len/2); i--)
	{
		s2 += s[i];
	}
	if (s1 == s2)
	{
		return "yes";
	}
	return  "no";
}





int main()
{
	std::ifstream f("input.txt");
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
	for (int i = 0; i < len; i++) {
		std::cout << j[i] << " ";
	}
	f.close();
	std::ofstream k("output.txt");
	for (int i = 0; i < len; i++) {
		std::string s = pal(j[i]);
		k << s;
	}
	
	k.close();
}
