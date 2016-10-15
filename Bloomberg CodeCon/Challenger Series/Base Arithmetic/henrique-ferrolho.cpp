#include <algorithm>
#include <iostream>
using namespace std;

// Custom types
typedef unsigned int ui;

// Macros
#define ALL(v) (v).begin(), (v).end()

ui findMinBase(const string& str) {
	char maxDigit = *max_element(ALL(str));

	return ('0' <= maxDigit && maxDigit <= '9') ? maxDigit - '0' + 1 : maxDigit - 'A' + 11;
}

int main() {
	string x, y;
	cin >> x >> y;

	long x_10 = stol(x, nullptr, findMinBase(x));
	long y_10 = stol(y, nullptr, findMinBase(y));

	cout << x_10 + y_10 << endl;

	return 0;
}
