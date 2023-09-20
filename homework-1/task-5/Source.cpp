#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream f("INPUT.txt");
	int a; int b;
	f >> a >> b;
	f.close();
	int y = 109;
	int km = 109 + (a * b) % y;
	int l = km % 109 + 1;
	ofstream k("OUTPUT.txt");
	k << to_string(l) << endl;
	k.close();

	return 0;

}