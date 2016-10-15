#include <iostream>
#include <map>
using namespace std;

// Custom types
typedef unsigned int ui;

// Custom comparators
const auto alphaCompare = [](const string& lhs, const string& rhs) {
	return lexicographical_compare(
		begin(lhs), end(lhs),
		begin(rhs), end(rhs),
		[](char l, char r) { return tolower(l) < tolower(r); });
};

// Globals
map<string, ui, decltype(alphaCompare)> clothToCount(alphaCompare);

int main() {
	string cloth;

	while (getline(cin, cloth))
		clothToCount[cloth]++;

	for (auto x : clothToCount) {
		if (x.first.find("sock") != string::npos) {
			if (x.second / 2 != 0)
				cout << x.second / 2 << "|" << x.first << endl;

			if (x.second % 2 != 0)
				cout << 0 << "|" << x.first << endl;
		} else cout << x.second << "|" << x.first << endl;
	}

	return 0;
}
