#include <iostream>
#include <sstream>
using namespace std;

typedef unsigned int uint;

void alg(uint n, uint& counter) {
	counter++;

	if (n != 1) {
		alg(n % 2 ? 3 * n + 1 : n / 2, counter);
	}
}

int main() {
	string line;
	while(getline(cin, line)) {
		istringstream iss(line);

		uint i, j;
		iss >> i >> j;

		uint iBak = i;
		uint jBak = j;

		if (i > j) {
			swap(i, j);
		}

		uint maxCycleLength = 0;

		for (uint k = i; k <= j; k++) {
			uint cycleLength = 0;

			alg(k, cycleLength);

			maxCycleLength = max(cycleLength, maxCycleLength);
		}

		cout << iBak << " " << jBak << " " << maxCycleLength << endl;
	}

	return 0;
}
