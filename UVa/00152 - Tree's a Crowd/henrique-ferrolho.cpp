#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

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
vvi trees;
ui answer[10];

float calcDist(float x1, float y1, float z1, float x2, float y2, float z2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void addTree(int x, int y, int z) {
	vi tree;
	tree.push_back(x);
	tree.push_back(y);
	tree.push_back(z);

	trees.push_back(tree);
}

void solve() {
	for (ui i = 0; i < trees.size(); i++) {
		float min = -1;

		for (ui j = 0; j < trees.size(); j++) {
			if (i == j)
				continue;

			float dist = calcDist(trees[i][0], trees[i][1], trees[i][2],
					trees[j][0], trees[j][1], trees[j][2]);

			if (dist < min || min == -1)
				min = dist;
		}

		if (min < 10)
			answer[(int) min]++;
	}
}

int main() {
	// input
	bool done = false;
	while (!done) {
		int x, y, z;
		cin >> x >> y >> z;

		if (x == 0 && y == 0 && z == 0)
			done = true;
		else
			addTree(x, y, z);
	}

	// processing
	solve();

	// output
	for (auto val : answer)
		cout << setw(4) << val;
	cout << endl;

	return 0;
}
