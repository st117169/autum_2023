#include <iostream> 
#include <fstream> 
#include <string>
using namespace std;

int main() {
	ifstream f("input.txt");
	int a;
	int b;
	f >> a >> b;
	f.close();
	ofstream k("output.txt");
	k << a + b;
	k.close();
	return 0;

}
