#include <iostream>
using namespace std;

int main() {
	unsigned int t;
	cin >> t;

	for (unsigned int i = 0; i < t; i++) {
		unsigned int a, b;
		cin >> a >> b;

		if (a == b) {
			cout << "=" << endl;
		} else if (a < b) {
			cout << "<" << endl;
		} else {
			cout << ">" << endl; 
		}
	}

	return 0;
}
