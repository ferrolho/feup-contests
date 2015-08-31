/*
 ID: henriqu13
 PROG: ariprog
 LANG: C++11
 */

#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
 * READ ME!
 * Change this to the respective problem name! And don't
 * forget to change the name in the top comment as well.
 */
const string PROB_NAME = "ariprog";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants
const ui MAX_M = 250;
const ui MAX_BISQUARES = MAX_M * MAX_M * 2;

// Globals
ui N, M;
vi S;
bool auxS[MAX_BISQUARES + 1];
vector<pair<int, int>> solutions;

vi mergeSort(const vi &data) {
	if (data.size() <= 1)
		return data;

	int middle = data.size() / 2;
	vi left(data.begin(), data.begin() + middle);
	vi right(data.begin() + middle, data.end());

	left = mergeSort(left);
	right = mergeSort(right);

	vi result(data.size());
	merge(ALL(left), ALL(right), result.begin());

	return result;
}

void generateBisquaresSet() {
	for (ui p = 0; p <= M; p++) {
		for (ui q = p; q <= M; q++) {
			int bisquare = pow(p, 2) + pow(q, 2); // p^2 + q^2

			// if bisquare not yet added
			if (!auxS[bisquare]) {
				S.push_back(bisquare);
				auxS[bisquare] = true;
			}
		}
	}

	S = mergeSort(S);
}

bool solutionExists(int a, int b) {
	for (auto solution : solutions) {
		if (solution.second == b && solution.first == a)
			return true;
		else if (solution.second > b)
			break;
	}

	return false;
}

void addSolution(int a, int b) {
	if (solutions.empty())
		solutions.push_back(pair<int, int>(a, b));
	else {
		for (ui i = 0; i < solutions.size(); i++) {
			if (b < solutions[i].second
					|| (b == solutions[i].second && a < solutions[i].first)) {
				solutions.insert(solutions.begin() + i, pair<int, int>(a, b));
				break;
			} else if (i == solutions.size() - 1) {
				solutions.push_back(pair<int, int>(a, b));
				break;
			}
		}
	}
}

void solve() {
	generateBisquaresSet();

	if (0) {
		for (auto i : S)
			cout << i << ", ";
		cout << endl;
	}

	// arithmetic progressions formula: a + n * b

	// for each 'a'
	for (ui i = 0; i < S.size(); i++) {
		int a = S[i];

		// for each possible 'b'
		for (ui j = i + 1; j < S.size(); j++) {
			int b = S[j] - a;

			// by definition of an arithmetic progression,
			// 'b' needs to be a positive integer
			if (b == 0)
				continue;

			// if solution already added
			if (solutionExists(a, b))
				continue;

			// check if the sequence has at least N elements
			for (int n = 2, val = a + n * b; val <= S.back(); n++, val += b) {
				// if val is not a bisquare
				if (!auxS[val])
					break;

				int n1 = N - 1;
				if (n >= n1)
					addSolution(a + (n - n1) * b, b); // solution found
			}
		}
	}
}

int main() {
	// DO NOT MESS WITH THIS BLOCK
	string str;
	str = PROB_NAME + ".in";
	FILE *fin = fopen(str.c_str(), "r");
	str = PROB_NAME + ".out";
	FILE *fout = fopen(str.c_str(), "w");
	assert(fin != NULL && fout != NULL);

	// input
	fscanf(fin, "%d", &N);
	fscanf(fin, "%d", &M);

	// processing
	solve();

	// output
	if (solutions.empty())
		fprintf(fout, "NONE\n");
	else
		for (auto solution : solutions)
			fprintf(fout, "%d %d\n", solution.first, solution.second);

	return 0;
}
