#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream f("INPUT.txt");
	string line; getline(f, line);
	long long n = stoi(line);
	f.close();
	int a =  9;
	int d = 9 - (stoi(line)%10);
	int ans = (stoi(line) % 10) * 100 + 9 * 10 + d;
	ofstream k("OUTPUT.txt");
	k << to_string(ans) << endl;
	k.close();







	return 0;


}