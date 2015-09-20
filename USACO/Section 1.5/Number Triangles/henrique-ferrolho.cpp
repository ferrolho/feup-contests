/*
 ID: henriqu13
 PROG: numtri
 LANG: C++11
 */

#include <assert.h>
#include <algorithm>
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
const string PROB_NAME = "numtri";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants
const ui MAX_R = 1000;

// Globals
ui R;
ui triangle[MAX_R][MAX_R];

void solve() {
	for (ui i = R - 1; i > 0; i--)
		for (ui j = 0; j < i; j++)
			triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);
}

int main() {
	// DO NOT MESS WITH THIS BLOCK
	ofstream fout(PROB_NAME + ".out");
	ifstream fin(PROB_NAME + ".in");
	assert(fin != NULL && fout != NULL);

	// input
	fin >> R;

	for (ui i = 0; i < R; i++)
		for (ui j = 0; j <= i; j++)
			fin >> triangle[i][j];

	// processing
	solve();

	// output
	fout << triangle[0][0] << endl;

	return 0;
}
