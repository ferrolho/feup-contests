#include <iostream>
using namespace std;

// Custom types
typedef unsigned int ui;

bool isPalindrome(const string& str) {
	return str == string(str.rbegin(), str.rend());
}

int main() {
	string str;
	cin >> str;

	if (isPalindrome(str)) {
		cout << str.size() << endl;
		return 0;
	}

	ui min = str.size() * 2;

	for (ui i = 0; i < str.size() / 2; i++) {
		string testStr = str;

		for (ui j = i + 1; j < str.size(); j++) {
			testStr.insert(testStr.begin(), str[j]);

			if (isPalindrome(testStr)) {
				if (testStr.size() < min)
					min = testStr.size();
			}
		}
	}

	cout << min << endl;

	return 0;
}
