/*
 ID: henriqu13
 PROG: sprime
 LANG: C++11
 */

#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * READ ME!
 * Change this to the respective problem name! And don't
 * forget to change the name in the top comment as well.
 */
const string PROB_NAME = "sprime";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants
const int oneDigitPrimes[4] = { 2, 3, 5, 7 };

// Globals
int N;
vi sprimes;

bool isPrime(long n) {
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

void solve(int ribsLeft, long superprime) {
	if (ribsLeft == 0) {
		if (isPrime(superprime))
			sprimes.push_back(superprime);
	} else {
		for (ui i = 1; i <= 9; i += 2) {
			long num = 10 * superprime + i;

			if (isPrime(num))
				solve(ribsLeft - 1, num);
		}
	}
}

void solve() {
	for (auto i : oneDigitPrimes)
		solve(N - 1, i);
}

int main() {
	// DO NOT MESS WITH THIS BLOCK
	ofstream fout(PROB_NAME + ".out");
	ifstream fin(PROB_NAME + ".in");
	assert(fin != NULL && fout != NULL);

	// input
	fin >> N;

	// processing
	solve();

	// output
	for (auto i : sprimes)
		fout << i << endl;

	return 0;
}
