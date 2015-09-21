/*
 ID: henriqu13
 PROG: pprime
 LANG: C++11
 */

#include <assert.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
 * READ ME!
 * Change this to the respective problem name! And don't
 * forget to change the name in the top comment as well.
 */
const string PROB_NAME = "pprime";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants

// Globals
int a, b;
vi pprimes;

bool isPrime(int n) {
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;

	int i = 5;
	while (i * i <= n) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

		i += 6;
	}

	return true;
}

bool inScope(int numDigits) {
	switch (numDigits) {
	case 1:
		return a <= 9 || 0 <= b;
	case 2:
		return a <= 99 || 10 <= b;
	case 3:
		return a <= 999 || 100 <= b;
	case 4:
		return a <= 9999 || 1000 <= b;
	case 5:
		return a <= 99999 || 10000 <= b;
	case 6:
		return a <= 999999 || 100000 <= b;
	case 7:
		return a <= 9999999 || 1000000 <= b;
	case 8:
		return a <= 99999999 || 10000000 <= b;
	default:
		return true;
	}
}

void addSolution(int pprime) {
	if (a <= pprime && pprime <= b)
		pprimes.push_back(pprime);
}

void solve() {
	/*
	 * generate 1 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(1)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			int pal = d1;

			if (isPrime(pal))
				addSolution(pal);
		}
	}

	/*
	 * generate 2 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(2)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			int pal = 10 * d1 + d1;

			if (isPrime(pal))
				addSolution(pal);
		}
	}

	/*
	 * generate 3 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(3)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			for (ui d2 = 0; d2 <= 9; d2++) {
				int pal = 100 * d1 + 10 * d2 + d1;

				if (isPrime(pal))
					addSolution(pal);
			}
		}
	}

	/*
	 * generate 4 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(4)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			for (ui d2 = 0; d2 <= 9; d2++) {
				int pal = 1000 * d1 + 100 * d2 + 10 * d2 + d1;

				if (isPrime(pal))
					addSolution(pal);
			}
		}
	}

	/*
	 * generate 5 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(5)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			for (ui d2 = 0; d2 <= 9; d2++) {
				for (ui d3 = 0; d3 <= 9; d3++) {
					int pal = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;

					if (isPrime(pal))
						addSolution(pal);
				}
			}
		}
	}

	/*
	 * generate 6 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(6)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			for (ui d2 = 0; d2 <= 9; d2++) {
				for (ui d3 = 0; d3 <= 9; d3++) {
					int pal = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3
							+ 10 * d2 + d1;

					if (isPrime(pal))
						addSolution(pal);
				}
			}
		}
	}

	/*
	 * generate 7 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(7)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			for (ui d2 = 0; d2 <= 9; d2++) {
				for (ui d3 = 0; d3 <= 9; d3++) {
					for (ui d4 = 0; d4 <= 9; d4++) {
						int pal = 1000000 * d1 + 100000 * d2 + 10000 * d3
								+ 1000 * d4 + 100 * d3 + 10 * d2 + d1;

						if (isPrime(pal))
							addSolution(pal);
					}
				}
			}
		}
	}

	/*
	 * generate 8 digit palindrome
	 * only odd; evens aren't so prime
	 */
	if (inScope(8)) {
		for (ui d1 = 1; d1 <= 9; d1 += 2) {
			for (ui d2 = 0; d2 <= 9; d2++) {
				for (ui d3 = 0; d3 <= 9; d3++) {
					for (ui d4 = 0; d4 <= 9; d4++) {
						int pal = 10000000 * d1 + 1000000 * d2 + 100000 * d3
								+ 10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2
								+ d1;

						if (isPrime(pal))
							addSolution(pal);
					}
				}
			}
		}
	}
}

int main() {
	// DO NOT MESS WITH THIS BLOCK
	ofstream fout(PROB_NAME + ".out");
	ifstream fin(PROB_NAME + ".in");
	assert(fin != NULL && fout != NULL);

	// input
	fin >> a >> b;

	// processing
	solve();

	// output
	for (auto i : pprimes)
		fout << i << endl;

	return 0;
}
