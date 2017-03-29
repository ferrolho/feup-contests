#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int uint;

const string JOLLY = "Jolly";
const string NOT_JOLLY = "Not jolly";

int main() {
	uint n;
	while (cin >> n) {
		if (n == 1) {
			cin >> n; // discard
			cout << JOLLY << endl;
		} else {
			vector<bool> diffs = vector<bool>(n);
			diffs[0] = true; // just for commodity

			int last;
			cin >> last;

			for (uint i = 1; i < n; i++) {
				int current;
				cin >> current;

				diffs[abs(current - last)] = true;

				last = current;
			}

			cout << (all_of(begin(diffs), end(diffs), [] (bool i) { return i; }) ? JOLLY : NOT_JOLLY) << endl;
		}
	}

	return 0;
}
