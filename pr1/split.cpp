#include "split.h"
#include <string>

std::vector <std::string> split(std::string s)
{
	std::vector < std::string > v;
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