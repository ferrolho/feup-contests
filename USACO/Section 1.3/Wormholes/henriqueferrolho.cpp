/*
 ID: henriqu13
 PROG: wormhole
 LANG: C++11
 */

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<unsigned int> vui;
typedef vector<vector<int>> vvi;
typedef vector<vector<unsigned int>> vvui;

/*
 * TODO
 * Change this to the respective problem name! And don't forget to
 * change the name in the initial multi-line comment as well.
 */
const string PROB_NAME = "wormhole";

const bool DEBUGGING = 0;

ui n;
vector<pair<ui, ui>> holes;
vector<vector<pair<ui, ui>>> pairings, map;

bool holeBetween(pair<ui, ui> pair) {
	for (auto hole : holes) {
		// if hole is on the same line
		if (hole.second == holes[pair.first].second) {
			ui x1 = min(holes[pair.first].first, holes[pair.second].first);
			ui x2 = max(holes[pair.first].first, holes[pair.second].first);

			if (x1 < hole.first && hole.first < x2)
				return true;
		}
	}

	return false;
}

void aux(vector<pair<ui, ui>> vec, vui left) {
	pair<ui, ui> p;

	p.first = left[0];
	left.erase(left.begin());

	for (ui i = 0; i < left.size(); ++i) {
		p.second = left[i];
		left.erase(left.begin() + i);

		vec.push_back(p);

		if (!left.empty())
			aux(vec, left);
		else
			pairings.push_back(vec);

		vec.pop_back();

		left.insert(left.begin() + i, p.second);
	}
}

void generateAllPairings() {
	for (ui i = 1; i < n; ++i) {
		// aux vector with numbers left to use
		vui left;
		for (ui j = 0; j < n; ++j)
			left.push_back(j);

		pair<ui, ui> p(0, i);
		left.erase(left.begin());
		left.erase(left.begin() + i - 1);

		// push first pair to pairing being built
		vector<pair<ui, ui>> vec;
		vec.push_back(p);

		// push remaining pairs to that pairing
		aux(vec, left);
	}

	if (DEBUGGING) {
		cout << "Pairings:" << endl;
		cout << "---------" << endl;
		for (auto pairing : pairings) {
			for (auto pair : pairing)
				cout << pair.first << "-" << pair.second << " ";
			cout << endl;
		}
	}
}

void printMap() {
	for (auto row : map) {
		for (auto hole : row)
			cout << hole.first << "," << hole.second << " ";

		cout << endl;
	}
}

void buildRelativeMap() {
	if (DEBUGGING)
		cout << "building map... ";

	// build a relative map
	for (auto hole : holes) {
		if (map.empty()) {
			// insert first element
			vector<pair<ui, ui> > vec;
			vec.push_back(hole);

			map.push_back(vec);
		} else {
			// for each row
			for (ui i = 0; i < map.size(); ++i) {

				// if row of holes with hole.y exists
				if (hole.second == map[i][0].second) {

					// look for right x position and insert hole
					for (ui j = 0; j < map[i].size(); j++) {

						if (hole.first < map[i][j].first) {
							map[i].insert(map[i].begin() + j, hole);

							break;
						} else if (j == map[i].size() - 1) {
							map[i].push_back(hole);

							break;
						}
					}

					break;
				} else if (hole.second < map[i][0].second) {
					// if row of holes with hole.y should exist before, create it

					vector<pair<ui, ui> > vec;
					vec.push_back(hole);

					map.insert(map.begin() + i, vec);

					break;
				} else if (i == map.size() - 1) {
					vector<pair<ui, ui> > vec;
					vec.push_back(hole);

					map.push_back(vec);

					break;
				}
			}
		}
	}

	if (DEBUGGING) {
		cout << "map built:" << endl;
		printMap();
	}
}

ui findHoleExit(ui hole, vector<pair<ui, ui>>& pairing) {
	// look through each pair
	for (auto pair : pairing) {
		if (pair.first == hole)
			return pair.second;
		else if (pair.second == hole)
			return pair.first;
	}

	cout << "ERROR FINDING HOLE" << endl;

	return 0;
}

/**
 * Returns the hole to the right, or -1 if no hole
 */
int getHoleToTheRight(ui n) {
	for (auto row : map) {
		for (ui i = 0; i < row.size(); ++i) {
			if (row[i] == holes[n]) {
				// if this is the last element of the row
				if (i == row.size() - 1)
					return -1;
				else {
					for (ui j = 0; j < holes.size(); ++j)
						if (row[i + 1] == holes[j])
							return j;
				}
			}
		}
	}

	cout << "ERROR @ getHoleToTheRight" << endl;

	return -1;
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

	for (ui i = 0; i < n; ++i) {
		pair<ui, ui> hole;

		fscanf(fin, "%d %d", &hole.first, &hole.second);

		holes.push_back(hole);
	}

	// processing
	generateAllPairings();
	buildRelativeMap();

	// this is the program output
	ui possibleLoops = 0;

	for (auto pairing : pairings) {
		bool loopAlreadyFound = false;

		// search for simple horizontal loops
		for (auto pair : pairing) {
			// if pair on same line && no hole in between
			if (holes[pair.first].second == holes[pair.second].second
					&& !holeBetween(pair)) {
				possibleLoops++;
				loopAlreadyFound = true;
				break;
			}
		}

		if (loopAlreadyFound)
			continue;
		else {
			// searching for more complex loops

			// go through each hole, and see what happens
			for (int i = 0; i < (int) holes.size(); ++i) {
				int entranceHole = i;

				bool done = false;
				while (!done) {
					ui exitHole = findHoleExit(entranceHole, pairing);

					int nextHole = getHoleToTheRight(exitHole);

					if (nextHole < 0)
						break;
					else if (nextHole == i) {
						// COMPLEX LOOP FOUND
						possibleLoops++;
						done = true;
						break;
					} else
						entranceHole = nextHole;
				}

				if (done)
					break;
			}
		}
	}

	// output
	fprintf(fout, "%u\n", possibleLoops);

	return 0;
}
