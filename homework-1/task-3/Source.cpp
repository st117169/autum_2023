#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream f("INPUT.txt");
	string line; getline(f, line);
	long long n = stoi(line);
	f.close();
	long long a = ((n /10) *((n / 10 )+ 1)) * 100 + 25;
	ofstream k("OUTPUT.txt");
	k << to_string(a) << endl;
	k.close();







	return 0;


}