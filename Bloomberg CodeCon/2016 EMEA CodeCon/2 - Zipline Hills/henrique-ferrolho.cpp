#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Custom types
typedef unsigned int ui;
typedef vector<unsigned int> vui;

// Macros
#define ALL(v) (v).begin(), (v).end()

// Globals
vui heights;

ui dfs(int curr, ui len) {
	//cout << heights[curr] << "-";
	//cout << curr << " --- " << len << endl;

	ui a = 0;
	ui b = 0;
	ui c = 0;
	ui d = 0;

	if (curr - 2 >= 0) {
		if (heights[curr] > heights[curr - 2]) {
			a = dfs(curr - 2, len + 1);
		}
	}

	if (curr - 1 >= 0) {
		if (heights[curr] > heights[curr - 1]) {
			b = dfs(curr - 1, len + 1);
		}
	}

	if (curr + 1 < heights.size()) {
		if (heights[curr] > heights[curr + 1]) {
			c = dfs(curr + 1, len + 1);
		}
	}

	if (curr + 2 < heights.size()) {
		if (heights[curr] > heights[curr + 2]) {
			d = dfs(curr + 2, len + 1);
		}
	}

	ui currMax = max(max(max(a, b), max(c, d)), len);

	//if (currMax == len)
	//	cout << "X" << endl;

	return currMax;
}

int main() {
	unsigned int N;
	cin >> N;

	for (ui i = 0; i < N; i++) {
		ui height;
		cin >> height;

		heights.push_back(height);
	}

    //sort(ALL(heights), std::greater<int>());

	ui max = 0;
	for (ui i = 0; i < heights.size(); i++) {
		ui path = dfs(i, 0);

		if (path > max)
			max= path;
	}

	cout << max << endl;

	/*
    cout << N << endl;
    for (auto x : heights)
    	cout << x << "-";
    cout << endl;
    */

    return 0;
}
