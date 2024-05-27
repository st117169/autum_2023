#include <iostream>

std :: string f1(int a, char s) {
	std::string h = "";
	if (a >= 1) {
		h += s;
		a -= 1;
		f1(a, s);
	}
	return h;
}

std:: string f2(int x) {
	std::string s = "";
	if (x < 4) {
		s = f1(x, 'I');
	}
	else if (x == 4) {
		s += "I";
		s += "V";
	}
	else if (x >= 5 && x < 9) {
		s = "V";
		std::string a = "";
		a = f1(x, 'I');
		s += a;
	}
	else if (x == 9) {
		s += "I";
		s += "X";
	}
	return s;
}

std::string f3(int x) {
	std::string s = "";
	int y = x / 10;
	int i = (x % 50) / 10;
	int r = x % 10;
	std::string a = f1(y, 'L');
	std::string h = f1(i, 'X');
	std::string g = f2(r);
	s = a + h + g;
	return s;
}

int main() {
	int x = 0;
	std::cin >> x;
	std::string s = f3(x);
	std::cout << s;
	return 0;
}