/*
 ID: henriqu13
 PROG: milk3
 LANG: C++11
 */

#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

/*
 * READ ME!
 * Change this to the respective problem name! And don't
 * forget to change the name in the top comment as well.
 */
const string PROB_NAME = "milk3";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants
const ui A = 0, B = 1, C = 2;

// Globals
ui CAPS[3];
bool visitedStates[212121];
vi solutions;

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

void solve(ui* state) {
	// state ID: milk in bucket AA . BB . CC
	ui stateID = state[A] * 10000 + state[B] * 100 + state[C];

	// return if this state has already been visited
	if (visitedStates[stateID])
		return;

	visitedStates[stateID] = true;

	// solution found!
	if (state[A] == 0)
		solutions.push_back(state[C]);

	// pick a bucket
	for (ui i = 0; i < 3; i++) {
		if (state[i] == 0)
			continue;

		// pour it to another bucket
		for (ui j = 0; j < 3; j++) {
			// excluding picked bucket
			if (j == i)
				continue;

			if (state[j] < CAPS[j]) {
				ui newState[3];
				copy(state, state + 3, newState);

				// amount of milk to be transferred
				ui load = min(CAPS[j] - state[j], state[i]);

				newState[i] = state[i] - load;
				newState[j] = state[j] + load;

				solve(newState);
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
	fscanf(fin, "%d %d %d", &CAPS[A], &CAPS[B], &CAPS[C]);

	ui state[3];
	state[A] = 0;
	state[B] = 0;
	state[C] = CAPS[C];

	// processing
	solve(state);
	solutions = mergeSort(solutions);

	// output
	for (ui i = 0; i < solutions.size(); i++)
		fprintf(fout, i == solutions.size() - 1 ? "%d\n" : "%d ", solutions[i]);

	return 0;
}
