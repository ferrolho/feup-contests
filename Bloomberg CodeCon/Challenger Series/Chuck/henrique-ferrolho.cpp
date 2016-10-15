#include <iostream>
using namespace std;

// Custom types
typedef unsigned int ui;

string smallestMultipleOf4ThatBeginsWithN(ui n) {
	auto nStr = to_string(n);

	ui multiple = 4;
	auto multipleStr = to_string(multiple);

	while (multipleStr.compare(0, nStr.length(), nStr) != 0) {
		multiple += 4;
		multipleStr = to_string(multiple);
	}

	return multipleStr;
}

int main() {
	ui n;
	cin >> n;

	string s;

	for (ui i = 1; s.length() < n; i++)
		s.append(smallestMultipleOf4ThatBeginsWithN(i));

	cout << s[n - 1] << endl;

	return 0;
}
