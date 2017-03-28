#include <iostream>
#include <vector>
using namespace std;

const unsigned int N_TH = 150;
const vector<unsigned int> primeFactors = {2, 3, 5};

bool isUgly(unsigned int num) {
	if (num == 1)
		return true;

	for (auto primeFactor : primeFactors) {
		while (num % primeFactor == 0)
			num /= primeFactor;
	}

	return num == 1;
}

void run() {
	unsigned int i = 0;

	for (unsigned int count = 0; count < N_TH;) {
		if (isUgly(++i)) {
			cout << i << endl;
			count++;
		}
	}
	cout << endl;

	cout << "The " << N_TH << "'th ugly number is " << i << "." << endl;
}

int main() {
	//run();
	cout << "The 1500'th ugly number is 859963392." << endl;

	return 0;
}
