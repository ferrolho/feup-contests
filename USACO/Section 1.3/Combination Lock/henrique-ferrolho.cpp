/*
 ID: henriqu13
 PROG: combo
 LANG: C++11
 */

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;

/*
 * TODO
 * Change this to the respective problem name! And don't forget to
 * change the name in the initial multi-line comment as well.
 */
const string PROB_NAME = "combo";

const bool DEBUGGING = 0;

int n;
vvi sets;

bool settingExists(int a, int b, int c) {
	for (auto s : sets)
		if (s[0] == a && s[1] == b && s[2] == c)
			return true;

	return false;
}

void addSetting(int a, int b, int c) {
	// wrapping under 1 and/or over N
	a = a <= 0 ? n + a : a > n ? a - n : a;
	b = b <= 0 ? n + b : b > n ? b - n : b;
	c = c <= 0 ? n + c : c > n ? c - n : c;

	// special case: N = 1
	if (n == 1) {
		a = a <= 0 ? 1 : a > n ? n : a;
		b = b <= 0 ? 1 : b > n ? n : b;
		c = c <= 0 ? 1 : c > n ? n : c;
	}

	if (!settingExists(a, b, c)) {
		vi s;
		s.push_back(a);
		s.push_back(b);
		s.push_back(c);

		sets.push_back(s);
	}
}

int main() {
	// DO NOT MESS WITH THIS...
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");
	assert(fin != NULL && fout != NULL);

	// input
	fscanf(fin, "%d", &n);

	vi john(3), master(3);
	fscanf(fin, "%d %d %d", &john[0], &john[1], &john[2]);
	fscanf(fin, "%d %d %d", &master[0], &master[1], &master[2]);

	if (DEBUGGING) {
		cout << "N: " << n << endl;
		cout << john[0] << "," << john[1] << "," << john[2] << endl;
		cout << master[0] << "," << master[1] << "," << master[2] << endl;
		cout << "------" << endl;
	}

	// processing
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			for (int k = -2; k <= 2; k++) {
				addSetting(john[0] + i, john[1] + j, john[2] + k);
				addSetting(master[0] + i, master[1] + j, master[2] + k);
			}
		}
	}

	if (DEBUGGING)
		for (auto s : sets)
			cout << s[0] << "," << s[1] << "," << s[2] << endl;

	// output
	fprintf(fout, "%lu\n", sets.size());

	return 0;
}
