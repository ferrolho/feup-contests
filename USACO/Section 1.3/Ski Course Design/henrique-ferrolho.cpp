/*
 ID: henriqu13
 PROG: skidesign
 LANG: C++11
 */

#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

/*
 * READ ME!
 * Change this to the respective problem name! And don't
 * forget to change the name in the top comment as well.
 */
const string PROB_NAME = "skidesign";

// Custom types
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Constants
const ui MAX_HEIGHT = 100;
const ui MAX_DELTA = 17;

// Global variables
ui n;
vi heights;

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

/**
 * Returns the cost of normalizing the hills to heights
 * between minHeight and maxHeight (minHeight + MAX_DELTA)
 */
ui cost(ui minHeight) {
	ui maxHeight = minHeight + MAX_DELTA;

	ui cost = 0;

	for (ui height : heights)
		if (height < minHeight)
			cost += pow(minHeight - height, 2);
		else if (height > maxHeight)
			cost += pow(height - maxHeight, 2);

	return cost;
}

ui solve() {
	// sort heights vector
	heights = mergeSort(heights);

	// find the best cost
	ui best = cost(0);

	for (ui height = 1; height < MAX_HEIGHT - MAX_DELTA; height++) {
		ui currentCost = cost(height);

		if (currentCost < best)
			best = currentCost;
	}

	return best;
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

	heights.resize(n);

	for (ui i = 0; i < n; ++i)
		fscanf(fin, "%d", &heights[i]);

	// output
	fprintf(fout, "%u\n", solve());

	return 0;
}
