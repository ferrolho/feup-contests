#include <iostream>
using namespace std;

int f(int x) {
	int last = 0;
	int n = 1;

	for (int i = 0; i < x; i++) {
		int next = last + n;
		last = n;
		n = next;
	}

	return n;
}

int main() {
	int l;

	do {
		cin >> l;

		if (l > 0)
			cout << f(l) << endl;
	} while (l != 0);

	return 0;
}
