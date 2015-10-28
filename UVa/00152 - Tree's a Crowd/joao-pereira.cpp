#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

float distance(vector<int> tree1, vector<int> tree2) {
	return sqrt(
			pow(tree2[0] - tree1[0], 2) + pow(tree2[1] - tree1[1], 2)
					+ pow(tree2[2] - tree1[2], 2));
}

int results[10];

int main() {
	vector<vector<int>> trees;
	int x, y, z;

	cin >> x >> y >> z;

	while (x != 0 || y != 0 || z != 0) {
		vector<int> newTree;

		newTree.push_back(x);
		newTree.push_back(y);
		newTree.push_back(z);

		trees.push_back(newTree);

		cin >> x >> y >> z;
	}

	for (unsigned int i = 0; i < trees.size(); i++) {
		int min = -1;

		for (unsigned int j = 0; j < trees.size(); j++) {
			if (i == j)
				continue;

			int dist = distance(trees[i], trees[j]);

			if (min == -1 || dist < min)
				min = dist;
		}

			results[(int) min]++;
	}

	for (auto i : results)
		cout << setw(4) << i;

	cout << endl;

	return 0;
}
